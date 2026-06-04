#ifndef Logic_HPP
#define Logic_HPP
#include "Algefrasoor.hpp"

//Player position
int playerXBhom = 235;
int playerYBhom = 255;
int groundYBhom = playerYBhom;
int playerWidthBhom = 70;
int playerHeightBhom = 70;
const int jumpStr = 10;
int playerAttackCooldown = 0;  
int playerDamageCooldown = 0; 

//Bg rendering
int bgXBhom = 0;  // Background position
const int bgWidthBhom = 3000;

// Bhombola creeps
struct BhombolaCreep {
	int x, y;
	int hp;
	bool alive;
	int frame;
};

const int bhombolaCreepCount = 6;
BhombolaCreep bhombolaCreeps[bhombolaCreepCount];
int bhombolaCreepFrameTimer = 0;
int bhombolaCreepsKilled = 0;
int activeBhombolaCreeps = 0;
int bhomCreepWidth = 65;   
int bhomCreepHeight = 70;  

//Function 
void playerMovesRight();
void playerMovesLeft();
void drawPlayerMovement();
void playerJump();
void initBhombolaCreeps();
void updateBhombolaCreeps();

void playerMovesRight()
{
	playerRunning = true;
	playerMovingRight = true;

	// Move background instead of player if we're not at the right edge
	if (playerXBhom > 500 && bgXBhom > -(bgWidthBhom - screenwidth)) {
		bgXBhom -= 5;
	}
	// Otherwise move the player if they're not at the right edge
	else if (playerXBhom < 980) {
		playerXBhom = playerXBhom + 5;
	}
}

void playerMovesLeft()
{
	playerRunning = true;
	playerMovingRight = false;

	// Move background instead of player if we're not at the left edge
	if (playerXBhom < 500 && bgXBhom < 0) {
		bgXBhom += 5;
	}
	// Otherwise move the player if they're not at the left edge
	else if (playerXBhom > 0) {
		playerXBhom = playerXBhom - 5;
	}
}

void drawPlayerMovement()
{
	if (playerRunning == false){
		if (playerAttacking == true) {
			if (attackFrame == 0) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, attack[0]);
			else if (attackFrame == 1) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, attack[1]);
			else if (attackFrame == 2) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, attack[2]);
			else if (attackFrame == 3) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, attack[3]);
			else if (attackFrame == 4) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, attack[4]);
			else if (attackFrame == 5) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, attack[5]);
		}
		else iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, idle);
	}

	else if (playerRunning == true) {
		if (playerMovingRight == true) {
			if (playerFrame == 0) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, run[0]);
			else if (playerFrame == 1) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, run[1]);
			else if (playerFrame == 2) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, run[2]);
			else if (playerFrame == 3) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, run[3]);
			else if (playerFrame == 4) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, run[4]);
			else if (playerFrame == 5) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, run[5]);
			else if (playerFrame == 6) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, run[6]);
			else if (playerFrame == 7) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, run[7]);
		}
		else if (playerMovingRight == false){
			if (playerFrame == 0) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, left[0]);
			else if (playerFrame == 1) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, left[1]);
			else if (playerFrame == 2) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, left[2]);
			else if (playerFrame == 3) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, left[3]);
			else if (playerFrame == 4) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, left[4]);
			else if (playerFrame == 5) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, left[5]);
			else if (playerFrame == 6) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, left[6]);
			else if (playerFrame == 7) iShowImage(playerXBhom, playerYBhom, playerWidthBhom, playerHeightBhom, left[7]);
		}
	}
}

void playerJump()
{
	if (playerJumping == false)
	{
		if (isKeyPressed('w'))
		{
			playerJumping = true;
			playerVelocityY = jumpStr;
		}
	}
	if (playerJumping == true) {
		playerYBhom = playerYBhom + playerVelocityY;
		playerVelocityY = playerVelocityY + gravity;


		if (playerYBhom <= groundYBhom) {
			playerYBhom = groundYBhom;
			playerJumping = false;
			playerVelocityY = 0;
		}
	}
}



// Initialize Bhombola creeps
void initBhombolaCreeps()
{
    for (int i = 0; i < bhombolaCreepCount; i++) {
        bhombolaCreeps[i].x = screenwidth + 100;
        bhombolaCreeps[i].y = 280;
        bhombolaCreeps[i].hp = 2;
        bhombolaCreeps[i].alive = false;
        bhombolaCreeps[i].frame = 0;
    }
    bhombolaCreepsKilled = 0;
    activeBhombolaCreeps = 0;
    
    // Spawn the first creep
    if (bhombolaCreepCount > 0) {
        bhombolaCreeps[0].alive = true;
        activeBhombolaCreeps = 1;
    }
}
//Creeps Health Bar
void drawMiniHealthBar(int x, int y, int width, int height, int currentHP, int maxHP) {
	float hpPercent = (float)currentHP / maxHP;
	if (hpPercent < 0) hpPercent = 0;

	// Outline
	iSetColor(255, 255, 255);
	iRectangle(x, y, width, height);

	// Health fill
	iSetColor(0, 255, 0); // green for minion
	iFilledRectangle(x, y, width * hpPercent, height);
}

// Update Bhombola creeps
void updateBhombolaCreeps()
{
	
	// Move creeps

	for (int i = 0; i < bhombolaCreepCount; i++) {
		if (bhombolaCreeps[i].alive) {
			bhombolaCreeps[i].x -= 3;

			// Reset if off-screen
			if (bhombolaCreeps[i].x < -100) {
				bhombolaCreeps[i].x = screenwidth + 100;
			}
		}
	}


	// Creep animation

	bhombolaCreepFrameTimer++;
	if (bhombolaCreepFrameTimer > 5) {
		for (int i = 0; i < bhombolaCreepCount; i++) {
			if (bhombolaCreeps[i].alive) {
				bhombolaCreeps[i].frame = (bhombolaCreeps[i].frame + 1) % 8;
			}
		}
		bhombolaCreepFrameTimer = 0;
	}

	// Player attacking creeps
	
	if (playerAttacking) {
		for (int i = 0; i < bhombolaCreepCount; i++) {
			if (bhombolaCreeps[i].alive) {
				if (playerXBhom < bhombolaCreeps[i].x + bhomCreepWidth &&
					playerXBhom + playerWidthBhom > bhombolaCreeps[i].x &&
					playerYBhom < bhombolaCreeps[i].y + bhomCreepHeight &&
					playerYBhom + playerHeightBhom > bhombolaCreeps[i].y)
				{
					bhombolaCreeps[i].hp--;
					if (bhombolaCreeps[i].hp <= 0) {
						bhombolaCreeps[i].alive = false;
						bhombolaCreepsKilled++;
						activeBhombolaCreeps--;

						// Spawn next creep if needed
						if (bhombolaCreepsKilled < bhombolaCreepCount) {
							for (int j = 0; j < bhombolaCreepCount; j++) {
								if (!bhombolaCreeps[j].alive && bhombolaCreepsKilled + activeBhombolaCreeps < bhombolaCreepCount) {
									bhombolaCreeps[j].alive = true;
									bhombolaCreeps[j].x = screenwidth + 100;
									bhombolaCreeps[j].hp = 2;
									activeBhombolaCreeps++;
									break;
								}
							}
						}
					}
				}
			}
		}
	}

	
	// Player taking damage from creeps
	
	if (playerDamageCooldown == 0) {  
		for (int i = 0; i < bhombolaCreepCount; i++) {
			if (bhombolaCreeps[i].alive) {
				// Check collision with player
				if (playerXBhom < bhombolaCreeps[i].x + bhomCreepWidth &&
					playerXBhom + playerWidthBhom > bhombolaCreeps[i].x &&
					playerYBhom < bhombolaCreeps[i].y + bhomCreepHeight &&
					playerYBhom + playerHeightBhom > bhombolaCreeps[i].y)
				{
					playerHealth -= 1;           
					if (playerHealth < 0) playerHealth = 0;
					playerDamageCooldown = 80;    
				}
			}
		}
	}


	// Decrement damage cooldown
	if (playerDamageCooldown > 0)
		playerDamageCooldown--;
}
void drawBossHealthBar(int x, int y, int width, int height, int currentHP, int maxHP) {
	float hpPercent = (float)currentHP / maxHP;
	if (hpPercent < 0) hpPercent = 0;

	// Outline
	iSetColor(255, 255, 255);
	iRectangle(x, y, width, height);

	// Health fill
	iSetColor(255, 0, 0);
	iFilledRectangle(x, y, width * hpPercent, height);

}


#endif