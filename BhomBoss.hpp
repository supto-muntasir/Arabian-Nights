#ifndef BHOMBOSS_HPP
#define BHOMBOSS_HPP

#include "Bhombola.hpp"
#include "LoadImage.hpp"

//HealthBar Variables
extern int playerHealth;
extern int playerMaxHealth;
extern int playerDamageCooldown;
extern int playerXBhom, playerYBhom; // player's current position in Bhombola
extern bool gameOver;




//  Boss state 
struct BhomBoss {
	int  x;
	int  y;
	int  hp;
	bool alive;
};

BhomBoss bhomBoss;
int bhomBossMaxHP = 150;
bool bhomBossSpawned = false;

// Size / speed 
int bhomBossWidth = 140;
int bhomBossHeight = 180;
int bhomBossFootOffset = 10;    

// Combat values 
bool bhomBossHitLatched = false; 

// Ranges 
int bhomBossAttackRangeX = 70;
int bhomBossAttackRangeY = 70;

//  Flags 
bool bhomBossAttacking = false;
bool bhomBossFacingRight = false;

//  Animation 

int bhomBossIdleFrame = 0, bhomBossIdleTimer = 0;
int bhomBossWalkFrame = 0, bhomBossWalkTimer = 0;
int bhomBossAttackFrame = 0, bhomBossAttackTimer = 0;

//  Timings 
int bhomBossAttackLock = 0, bhomBossAttackLockMax = 10;

// last movement step 
int bhomBossLastStep = 0;


// Setup 
void initBhomBoss() {
	bhomBoss.x = screenwidth + 100;
	bhomBoss.y = groundYBhom - bhomBossFootOffset;
	bhomBoss.hp = bhomBossMaxHP;
	bhomBoss.alive = true;

	bhomBossAttacking = false;
	bhomBossHitLatched = false;
	bhomBossFacingRight = false;

	bhomBossIdleFrame = bhomBossIdleTimer = 0;
	bhomBossWalkFrame = bhomBossWalkTimer = 0;
	bhomBossAttackFrame = bhomBossAttackTimer = 0;
	bhomBossAttackLock = 0;

	bhomBossLastStep = 0;
	bhomBossSpawned = true;
}


//  Update (no player HP damage) 
void updateBhomBoss() {
	if (!bhomBossSpawned) return;
	if (!bhomBoss.alive)  return;

	// stick to ground
	bhomBoss.y = groundYBhom - bhomBossFootOffset;

	//  take damage from player (one hit per swing)
	if (playerAttacking) {
		if (!bhomBossHitLatched &&
			abs(playerXBhom - bhomBoss.x) < 120 &&
			abs(playerYBhom - bhomBoss.y) < 120) {

			bhomBoss.hp -= 8;
			bhomBossHitLatched = true;

			if (bhomBoss.hp <= 0) {
				bhomBoss.alive = false;  // screen theke vanish
				return;
			}
		}
	}
	else {
		bhomBossHitLatched = false;
	}

	// attack / walk switch (animation-only attack)
	if (!bhomBossAttacking &&
		(abs(playerXBhom - bhomBoss.x) < bhomBossAttackRangeX) &&
		(abs(playerYBhom - bhomBoss.y) < bhomBossAttackRangeY)) {
		bhomBossAttacking = true;
		
	}

	if (bhomBossAttacking) {
		if (bhomBossAttackLock > 0) bhomBossAttackLock--;
		if (bhomBossAttackLock == 0) {
			if ((abs(playerXBhom - bhomBoss.x) < bhomBossAttackRangeX) &&
				(abs(playerYBhom - bhomBoss.y) < bhomBossAttackRangeY)) {

				// Reset lock
				bhomBossAttackLock = bhomBossAttackLockMax;

				// PLAYER DAMAGE 
				if (playerDamageCooldown == 0) {
					playerHealth -= 10;   
					if (playerHealth < 0) playerHealth = 0;

					playerDamageCooldown = 70; 
				}
			}
			else {
				bhomBossAttacking = false;
				bhomBossAttackFrame = 0;
				bhomBossAttackTimer = 0;
			}
		}
	}

	//  movement & animation
	
	int step = -3;                               
	int dx = playerXBhom - bhomBoss.x;         

	// bg scroll LEFT (player running right)
	if (playerXBhom > 500 && bgXBhom > -(bgWidthBhom - screenwidth)) {
		if (dx < -20)       step = -4;   
		else if (dx > 20)   step = -2;   
	}
	// bg scroll RIGHT (player running left)
	else if (playerXBhom < 500 && bgXBhom < 0) {
		step = +2;                         
		if (dx > 20)        step = +3;    
	}
	// no bg scroll: full chase both ways
	else {
		if (dx > 20)        step = +2;     
		else if (dx < -20)  step = -4;     
	}

	// update facing by player position ( avoids jitter on overlap)
	int faceDx = playerXBhom - bhomBoss.x;
	if (faceDx > 10) {
		bhomBossFacingRight = true;   
	}
	else if (faceDx < -10) {
		bhomBossFacingRight = false;  
	}
	

	// apply movement every frame (even while attacking)
	bhomBoss.x += step;
	bhomBossLastStep = step;

	// animation
	if (bhomBossAttacking) {
		bhomBossAttackTimer++;
		if (bhomBossAttackTimer > 4) {
			bhomBossAttackTimer = 0;
			bhomBossAttackFrame = (bhomBossAttackFrame + 1) % 16;
		}
	}
	else if (bhomBossLastStep == 0) {
		// idle animation
		bhomBossIdleTimer++;
		if (bhomBossIdleTimer > 7) {
			bhomBossIdleTimer = 0;
			bhomBossIdleFrame = (bhomBossIdleFrame + 1) % 7;
		}
	}
	else {
		// walk animation
		bhomBossWalkTimer++;
		if (bhomBossWalkTimer > 5) {
			bhomBossWalkTimer = 0;
			bhomBossWalkFrame = (bhomBossWalkFrame + 1) % 12;
		}
	}

	if (playerHealth <= 0) {
		playerHealth = 0;
		gameOver = true;
	}
	
}


// Draw
void drawBhomBoss() {
	if (!bhomBoss.alive) return;

	// attacking
	if (bhomBossAttacking) {
		int img;
		if (bhomBossFacingRight) {
			img = bhomBossAttackR[bhomBossAttackFrame];
		}
		else {
			img = bhomBossAttack[bhomBossAttackFrame];
		}
		iShowImage(bhomBoss.x, bhomBoss.y, bhomBossWidth, bhomBossHeight, img);
		return;
	}

	// idle vs walk
	if (bhomBossLastStep == 0) {
		int img;
		if (bhomBossFacingRight) {
			
			img = bhomBossHurtR[bhomBossIdleFrame];
		}
		else {
			
			img = bhomBossHurt[bhomBossIdleFrame];
		}
		iShowImage(bhomBoss.x, bhomBoss.y, bhomBossWidth, bhomBossHeight, img);
		return;
	}

	// walking
	int walkImg;
	if (bhomBossFacingRight) {
		walkImg = bhomBossMoveR[bhomBossWalkFrame];
	}
	else {
		walkImg = bhomBossMove[bhomBossWalkFrame];
	}
	iShowImage(bhomBoss.x, bhomBoss.y, bhomBossWidth, bhomBossHeight, walkImg);
}

#endif 

