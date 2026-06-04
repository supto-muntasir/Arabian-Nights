#ifndef Bhallagena_HPP
#define Bhallagena_HPP
#include "LoadImage.hpp"
#include "DrawPages.hpp"
#include "Algefrasoor.hpp"


void drawPl();
void plMovesRight();
void plMovesLeft();
void plJump();
void checkRedLineCollision();
void respawnPlayer();
void checkPlatformCollision();


int plX = 63;
int plY = 185;
int plWidth = 50;
int plHeight = 50;
int grounY = plY;
int jumpStren = 9;
float grav = -0.3;


int redLine1StartX = 165;
int redLine1EndX = 210;
int redLine1Y = 185;

int redLine2StartX = 618;
int redLine2EndX = 1050;
int redLine2Y = 185;


int groundPlatformY = 185;


int middlePlatformY = 308;
int middleGreenStartX1 = 243;
int middleGreenEndX1 = 364;
int middleGreenStartX2 = 427;
int middleGreenEndX2 = 994;
int middleRedStartX1 = 0;
int middleRedEndX1 = 237;
int middleRedStartX2 = 372;
int middleRedEndX2 = 418;


int highPlatformY = 360;
int highGreenStartX = 0;
int highGreenEndX = 188;
int highRedStartX = 190;
int highRedEndX = 1050;


int finalPlatformY = 460;
int finalGreenStartX1 = 0;
int finalGreenEndX1 = 198;
int finalGreenStartX2 = 249;
int finalGreenEndX2 = 994;
int finalRedStartX = 200;
int finalRedEndX = 248;

//Health
int boomPlayerHealth = 100;     
int boomPlayerMaxHealth = 100;
int boomPlayerDamageCooldown = 0;

//Armor
int playerArmor = 50;     
int playerMaxArmor = 50;   

//Flash
bool showHitImage = false;
int hitImageTimer = 0;
const int hitImageDuration = 8;  
//final
bool gameWon = false;



bool onMiddlePlatform = false;
bool onHighPlatform = false;
bool onFinalPlatform = false;


void checkPlatformCollision() {
	
	if (playerVelocityY < 0 && (plY + plHeight) >= finalPlatformY && plY <= finalPlatformY) {
		
		if ((plX + plWidth >= finalGreenStartX1 && plX <= finalGreenEndX1) ||
			(plX + plWidth >= finalGreenStartX2 && plX <= finalGreenEndX2)) {
			
			plY = finalPlatformY - plHeight;
			playerJumping = false;
			playerVelocityY = 0;
			onFinalPlatform = true;
			onHighPlatform = false;
			onMiddlePlatform = false;
			return;
		}
		
		else if (plX + plWidth >= finalRedStartX && plX <= finalRedEndX) {
			
			onFinalPlatform = false;
			
		}
	}

	
	if (playerVelocityY < 0 && (plY + plHeight) >= highPlatformY && plY <= highPlatformY && !onFinalPlatform) {
		
		if (plX + plWidth >= highGreenStartX && plX <= highGreenEndX) {
			
			plY = highPlatformY - plHeight;
			playerJumping = false;
			playerVelocityY = 0;
			onHighPlatform = true;
			onFinalPlatform = false;
			onMiddlePlatform = false;
			return;
		}
		
		else if (plX + plWidth >= highRedStartX && plX <= highRedEndX) {
			
			onHighPlatform = false;
		}
	}

	
	if (playerVelocityY < 0 && (plY + plHeight) >= middlePlatformY && plY <= middlePlatformY && !onFinalPlatform && !onHighPlatform) {
		
		if ((plX + plWidth >= middleGreenStartX1 && plX <= middleGreenEndX1) ||
			(plX + plWidth >= middleGreenStartX2 && plX <= middleGreenEndX2)) {
			
			plY = middlePlatformY - plHeight;
			playerJumping = false;
			playerVelocityY = 0;
			onMiddlePlatform = true;
			onFinalPlatform = false;
			onHighPlatform = false;
			return;
		}
		
		else if ((plX + plWidth >= middleRedStartX1 && plX <= middleRedEndX1) ||
			(plX + plWidth >= middleRedStartX2 && plX <= middleRedEndX2)) {
			
			onMiddlePlatform = false;
		}
	}

	
	if (onFinalPlatform && playerJumping == false) {
		bool onSolidGround = false;

		
		if ((plX + plWidth >= finalGreenStartX1 && plX <= finalGreenEndX1) ||
			(plX + plWidth >= finalGreenStartX2 && plX <= finalGreenEndX2)) {
			onSolidGround = true;
		}

		
		if (onSolidGround == false) {
			playerJumping = true;
			playerVelocityY = 0;
			onFinalPlatform = false;
		}
	}

	
	if (onHighPlatform && playerJumping == false && onFinalPlatform == false) {
		bool onSolidGround = false;

		
		if (plX + plWidth >= highGreenStartX && plX <= highGreenEndX) {
			onSolidGround = true;
		}

		
		if (onSolidGround == false) {
			playerJumping = true;
			playerVelocityY = 0;
			onHighPlatform = false;
		}
	}

	
	if (onMiddlePlatform && playerJumping == false && onFinalPlatform == false && onHighPlatform == false) {
		bool onSolidGround = false;

		
		if ((plX + plWidth >= middleGreenStartX1 && plX <= middleGreenEndX1) ||
			(plX + plWidth >= middleGreenStartX2 && plX <= middleGreenEndX2)) {
			onSolidGround = true;
		}

		
		if (onSolidGround == false) {
			playerJumping = true;
			playerVelocityY = 0;
			onMiddlePlatform = false;
		}
	}

	
	if (playerVelocityY < 0 && plY <= groundPlatformY && !onMiddlePlatform && onHighPlatform == false && onFinalPlatform == false) {
		plY = groundPlatformY;
		playerJumping = false;
		playerVelocityY = 0;
	}
}

void respawnPlayer() {
	plX = 63;
	plY = 185;
}

void checkRedLineCollision() {
	
	if (plY == grounY && plX >= redLine1StartX && plX <= redLine1EndX) {
		respawnPlayer();
	}
	
	if (plY == grounY && plX >= redLine2StartX && plX <= redLine2EndX) {
		respawnPlayer();
	}
}



void drawPl(){
	if (playerRunning == false){
		if (playerAttacking == true) {
			if (attackFrame == 0) iShowImage(plX, plY, plWidth, plHeight, attack[0]);
			else if (attackFrame == 1) iShowImage(plX, plY, plWidth, plHeight, attack[1]);
			else if (attackFrame == 2) iShowImage(plX, plY, plWidth, plHeight, attack[2]);
			else if (attackFrame == 3) iShowImage(plX, plY, plWidth, plHeight, attack[3]);
			else if (attackFrame == 4) iShowImage(plX, plY, plWidth, plHeight, attack[4]);
			else if (attackFrame == 5) iShowImage(plX, plY, plWidth, plHeight, attack[5]);
		}
		else iShowImage(plX, plY, plWidth, plHeight, idle);
	}

	else if (playerRunning == true) {
		if (playerMovingRight == true) {
			if (playerFrame == 0) iShowImage(plX, plY, plWidth, plHeight, run[0]);
			else if (playerFrame == 1) iShowImage(plX, plY, plWidth, plHeight, run[1]);
			else if (playerFrame == 2) iShowImage(plX, plY, plWidth, plHeight, run[2]);
			else if (playerFrame == 3) iShowImage(plX, plY, plWidth, plHeight, run[3]);
			else if (playerFrame == 4) iShowImage(plX, plY, plWidth, plHeight, run[4]);
			else if (playerFrame == 5) iShowImage(plX, plY, plWidth, plHeight, run[5]);
			else if (playerFrame == 6) iShowImage(plX, plY, plWidth, plHeight, run[6]);
			else if (playerFrame == 7) iShowImage(plX, plY, plWidth, plHeight, run[7]);
		}
		else if (playerMovingRight == false){
			if (playerFrame == 0) iShowImage(plX, plY, plWidth, plHeight, left[0]);
			else if (playerFrame == 1) iShowImage(plX, plY, plWidth, plHeight, left[1]);
			else if (playerFrame == 2) iShowImage(plX, plY, plWidth, plHeight, left[2]);
			else if (playerFrame == 3) iShowImage(plX, plY, plWidth, plHeight, left[3]);
			else if (playerFrame == 4) iShowImage(plX, plY, plWidth, plHeight, left[4]);
			else if (playerFrame == 5) iShowImage(plX, plY, plWidth, plHeight, left[5]);
			else if (playerFrame == 6) iShowImage(plX, plY, plWidth, plHeight, left[6]);
			else if (playerFrame == 7) iShowImage(plX, plY, plWidth, plHeight, left[7]);
		}
	}
}

void plMovesRight(){
	playerRunning = true;
	playerMovingRight = true;
	if (plX > 980) plX = plX;
	else plX = plX + 5;
}

void plMovesLeft(){
	playerRunning = true;
	playerMovingRight = false;
	if (plX < 0) plX = plX;
	else plX = plX - 5;
}

void plJump() {
	if (playerJumping == false && !isKeyPressed('w')) {
		return;
	}

	if (playerJumping == false && isKeyPressed('w')) {
		playerJumping = true;
		playerVelocityY = jumpStren;
		onMiddlePlatform = false; 
		onHighPlatform = false;
		onFinalPlatform = false;
		return;
	}

	if (playerJumping == true) {
		plY += playerVelocityY;
		playerVelocityY += grav;

		
		checkPlatformCollision();

		
		if (plY <= groundPlatformY && !onMiddlePlatform && !onHighPlatform && !onFinalPlatform) {
			plY = groundPlatformY;
			playerJumping = false;
			playerVelocityY = 0;
		}
	}

	


}

#endif