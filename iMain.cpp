#include "iGraphics.h"
#include "LoadImage.hpp"
#include "DrawPages.hpp"
#include "Algefrasoor.hpp"
#include "Boss.hpp"
#include "Bhombola.hpp"
#include "BoomeraSoor.hpp"
#include "final.hpp"

//Armor
void drawArmorBar(int x, int y, int width, int height, int armor, int maxArmor) {
	// Background 
	iSetColor(50, 50, 50);
	iFilledRectangle(x, y, width, height);

	// Armor 
	int armorWidth = (int)((float)armor / maxArmor * width);
	iSetColor(0, 0, 255); 
	iFilledRectangle(x, y, armorWidth, height);

	// Border
	iSetColor(255, 255, 255);
	iRectangle(x, y, width, height);
}

void playerTakeDamage(int dmg) {
	if (playerDamageCooldown > 0) return;

	if (playerArmor > 0) {
		int remainingDamage = dmg - playerArmor;
		playerArmor -= dmg;
		if (playerArmor < 0) playerArmor = 0;
		if (remainingDamage > 0) {
			playerHealth -= remainingDamage;
		}
	}
	else {
		playerHealth -= dmg;
	}

	if (playerHealth < 0) playerHealth = 0;
	playerDamageCooldown = 70; 
	if (playerHealth == 0) {
		gameOver = true;
	}
}


void iDraw()
{
	iClear();
	if (music) {
		playBackgroundMusic();
	}
	else {
		stopBackgroundMusic();
	}
	
	if (landingPage == 1)
	{
		drawLandingPage();
	}
	if (loadingPage == 1)
	{
		drawLoadingPage();
		if (stop > 7)
		{
			loadingPage = 0;
			menuPage = 1;
		}
	}
	if (menuPage == 1)
	{
		drawMenuPage();
	}
	if (startPage == 1)
	{
		drawStartPage();
	}
	if (storyPage == 1)
	{
		drawStoryPage();
	}
	if (creditPage == 1)
	{
		drawCreditPage();
	}
	if (optionOnPage == 1)
	{
		drawOptionsOnPage();
	}
	if (optionsOffPage == 1)
	{
		drawOptionsOffPage();
	}
	
	if (cutscenePage == 1) {
		drawCutscenePage();
	}
	if (gameLevel == 1)
	{
		drawGameLevelPage();
	}
	if (algefrasoor == 1)
	{
		drawAlgefrasoorPage();
		drawHealthBar(24, 650, 200, 20);

		if (gameOver) {
			iShowImage(0, 0, screenwidth, screenheight, gameOverImage);
			iSetColor(255, 255, 255);
		}
		if (bossDefeated) {
			iShowImage(0, 0, screenwidth, screenheight, bossDieImage);
			iText(429, 107, "Press M to return to Menu", GLUT_BITMAP_HELVETICA_18);
		}
	}
	if (bhombola == 1) {
		drawBhombolaPage();
		drawHealthBar(24, 650, 200, 20); 

		if (bhomBossSpawned && bhomBoss.alive) {
			drawBossHealthBar(700, 650, 300, 20, bhomBoss.hp, bhomBossMaxHP); 
		}
		// Health bars for each alive minion
		for (int i = 0; i < bhombolaCreepCount; i++) {
			if (bhombolaCreeps[i].alive) {
				drawMiniHealthBar(
					bhombolaCreeps[i].x,
					bhombolaCreeps[i].y + playerHeightBhom + 5, // above the creep
					50,  // width of mini bar
					5,   // height of mini bar
					bhombolaCreeps[i].hp,
					2    // max HP of minion
					);
			}
		}

		 if (bhomBossSpawned && !bhomBoss.alive) {
			// Boss defeated - show Level Complete
			iSetColor(0, 255, 0); 
			iText(450, 350, "Level Complete!", GLUT_BITMAP_HELVETICA_18);
			iText(400, 320, "Press M to return to Menu", GLUT_BITMAP_HELVETICA_18);
		}

		if (gameOver) {
			iShowImage(0, 0, screenwidth, screenheight, gameOverImage);
			iSetColor(255, 255, 255);
		}
		if (gameWon) {
			iShowImage(0, 0, screenwidth, screenheight, gameWinImage);
			iSetColor(255, 255, 255);
		}
	}

	if (boomerasoor == 1) {
		drawBoomerasoorPage();
		playerHealth = boomPlayerHealth;
		playerMaxHealth = boomPlayerMaxHealth;
		drawHealthBar(24, 650, 200, 20);

		//HITIMMAGE
		if (showHitImage) {
			iShowImage(0, 0, screenwidth, iScreenHeight, bossHitImage);
		}


		if (gameOver) {
			iShowImage(0, 0, screenwidth, screenheight, gameOverImage);
			iSetColor(255, 255, 255);
			iText(429, 107, "Press M to return to Menu", GLUT_BITMAP_HELVETICA_18);
			iText(400, 80, "Press R to Restart Level", GLUT_BITMAP_HELVETICA_18);
		}


	}
	if (finalPage == 1) {
		drawFinalPage();
		drawBoomBoss();

		// Draw player health bar 
		drawHealthBar(24, screenheight - 40, 200, 20);

		// Draw player armor bar just above health
		drawArmorBar(24, screenheight - 70, 200, 15, playerArmor, playerMaxArmor);

		// Draw boss health bar
		drawBossHealthBar(screenwidth / 2 - 150, screenheight - 40, 300, 20, boomBoss.hp, boomBossMaxHP);

		// HIT IMAGE
		if (finalPage == 1 && showHitImage) {
			iShowImage(0, 0, screenwidth, iScreenHeight, bossHitImage);
		}

		if (gameOver) {
			iShowImage(0, 0, screenwidth, screenheight, gameOverImage);
			iSetColor(255, 255, 255);
			iText(429, 107, "Press M to return to Menu", GLUT_BITMAP_HELVETICA_18);
			iText(400, 80, "Press R to Restart Level", GLUT_BITMAP_HELVETICA_18);
		}
		else if (!boomBoss.alive) {  // CHANGED: Added "else" to make this mutually exclusive with gameOver
			// Show boss death image (victory)
			iShowImage(0, 0, screenwidth, screenheight, gameWinImage);
			// Stop player actions
			playerHealth = 0;
			if (isKeyPressed('m') || isKeyPressed('M')) {
				finalPage = 0;
				menuPage = 1;

				// Reset player stats
				playerHealth = playerMaxHealth;
				playerArmor = playerMaxArmor;

				// Reset boss stats
				boomBoss.alive = true;
				boomBoss.hp = boomBossMaxHP;

				// Reset cutscene so it can play next time
				cutscenePage = 0;
				cutsceneFinished = false;
			}
		}
	}
}

void iMouseMove(int mx, int my)
{
	
}

void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("%d %d\n", mx, my);
		if (menuPage == 1 && (mx >= 93 && mx <= 315) && (my >= 404 && my <= 441))
		{
			startButtonClickHandler();
		}
		else if (menuPage == 1 && (mx >= 93 && mx <= 313) && (my >= 266 && my <= 305))
		{
			storyButtonClickHandler();
		}
		else if (menuPage == 1 && music == false && (mx >= 93 && mx <= 313) && (my >= 337 && my <= 367))
		{
			optionsOffButtonClickHandler();
		}
		else if (menuPage == 1 && music == true && (mx >= 93 && mx <= 313) && (my >= 337 && my <= 367))
		{
			optionsOnButtonClickHandler();
		}
		else if (menuPage == 1 && (mx >= 93 && mx <= 313) && (my >= 194 && my <= 233))
		{
			creditButtonClickHandler();
		}
		else if ((screenTime == 0 || screenTime == 1 || screenTime == 2 || screenTime == 3 || screenTime == 4) && (mx >= 835 && mx <= 1031) && (my >= 20 && my <= 51))
		{
			landingPageButtonClickHandler();
			menuPage = 1, startPage = 0, storyPage = 0, optionOnPage = 0, creditPage = 0,optionsOffPage = 0;
		}
		else if (screenTime == 2 && (mx >= 792 && mx <= 916) && (my >= 481 && my <= 528))
		{
			optionsOffButtonClickHandler();
			menuPage = 0, startPage = 0, storyPage = 0, optionOnPage = 0, creditPage = 0,optionsOffPage= 1;
			music = false;
			music = 1;
			playBackgroundMusic();
		}
		else if (screenTime == 4 && (mx >= 792 && mx <= 916) && (my >= 481 && my <= 528))
		{
			optionsOnButtonClickHandler();
			menuPage = 0, startPage = 0, storyPage = 0, optionOnPage = 1, creditPage = 0, optionsOffPage = 0;
			music = true;
			music = 0;
			stopBackgroundMusic();
		}
		else if (gameLevel == 1 && (mx >= 367 && mx <= 684) && (my >= 404 && my <= 467))
		{
			algefrasoorButtonClickHandler();
		}
		else if (gameLevel == 1 && (mx >= 367 && mx <= 684) && (my >= 286 && my <= 350))
		{
			bhombolaButtonClickHandler();
			initBhombolaCreeps();
		}
		else if (gameLevel == 1 && (mx >= 367 && mx <= 684) && (my >= 164 && my <= 229))
		{
			boomerasoorButtonClickHandler();
		}
		
		
	}
	if (algefrasoor == 1)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			playerAttacking = true;
		}
		else playerAttacking = false;	
	}
	if (bhombola == 1)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			playerAttacking = true;
		}
		else playerAttacking = false;
	}
	if (boomerasoor == 1)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			playerAttacking = true;
		}
		else playerAttacking = false;
	}
	if (finalPage == 1)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			playerAttacking = true;
		}
		else playerAttacking = false;
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

// Special Keys:
// GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
// GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT

void fixedUpdate()
{

	

	if (landingPage == 1){
		if (isKeyPressed('\r'))
		{
			landingPageButtonClickHandler();
		}
	}
	if (algefrasoor == 1){
		if (isKeyPressed('m'))
		{
			algefrasoor = 0;
			gameLevel = 1;
			drawGameLevelPage();
		}
	}
	if (bhombola == 1){
		if (isKeyPressed('m'))
		{
			bhombola = 0;
			algefrasoor = 0;
			gameLevel = 1;
			drawGameLevelPage();
		}
	}
	if (isKeyPressed('w') || isSpecialKeyPressed(GLUT_KEY_UP))
	{

	}
	if (isKeyPressed('a') || isSpecialKeyPressed(GLUT_KEY_LEFT))
	{

	}
	if (isKeyPressed('s') || isSpecialKeyPressed(GLUT_KEY_DOWN))
	{

	}
	
	if (bhombola == 1)
	{
		if (isKeyPressed('m'))
		{
			algefrasoor = 0;
			gameLevel = 1;
			drawGameLevelPage();
		}
		if (isKeyPressed('d'))
		{
			playerMovesRight();
		}
		else if (isKeyPressed('a'))
		{
			playerMovesLeft();
		}
		else
		{
			playerRunning = false;
		}
		playerJump();

		updateBhombolaCreeps();

		//Spawn boss after creeps killed
		if (!bhomBossSpawned && bhombolaCreepsKilled >= bhombolaCreepCount) {
			initBhomBoss();
		}

		//Update boss logic (movement, damage, attacks)
		updateBhomBoss();
		if (gameOver) {
			if (isKeyPressed('m') || isKeyPressed('M')) {
				gameOver = false;
				finalPage = 0;
				menuPage = 1;

				// Reset player stats
				playerHealth = playerMaxHealth;
				playerArmor = playerMaxArmor;

				// Reset boss stats
				boomBoss.alive = true;
				boomBoss.hp = boomBossMaxHP;

				// Reset cutscene so it plays again next time
				cutscenePage = 1;      // allow cutscene to show when re-entering level
				cutsceneFinished = false;
			}

			if (isKeyPressed('r') || isKeyPressed('R')) {
				gameOver = false;

				// Restart BoomeraSoor level
				boomPlayerHealth = boomPlayerMaxHealth;
				boomPlayerDamageCooldown = 0;
				meteorsInited = 0;
				respawnPlayer();

				boomerasoor = 1;
				menuPage = 0;
			}
		}
	}

	if (algefrasoor == 1){
		if (isKeyPressed('d'))
		{
			playerRunning = true;
			playerMovingRight = true;
			if (playerX > 980) playerX = playerX;
			else playerX = playerX + 5;
		}
		else if (isKeyPressed('a')) {
			playerRunning = true;
			playerMovingRight = false;
			if (playerX < 0) playerX = playerX;
			else playerX = playerX - 5;
		}

		else {
			playerRunning = false;
		}

		if (playerJumping == false)
		{
			if (isKeyPressed('w'))
			{
				playerJumping = true;
				playerVelocityY = jumpStrength;
			}
		}
		if (playerJumping == true) {
			playerY = playerY + playerVelocityY;
			playerVelocityY = playerVelocityY + gravity;


			if (playerY <= groundY) {
				playerY = groundY;
				playerJumping = false;
				playerVelocityY = 0;
			}
		}
		if (gameOver) {
			if (isKeyPressed('m') || isKeyPressed('M')) {
				gameOver = false;
				algefrasoor = 0;
				menuPage = 1;

				// Reset stats
				playerHealth = playerMaxHealth;
				totalCreepsKilled = 0;
				levelComplete = false;
				bossSpawned = false;

				// Reset cutscene so it plays again
				cutscenePage = 0;
				cutsceneFinished = false;
				gameLevel = 0;
			}

			//RESTART directly 
			if (isKeyPressed('r') || isKeyPressed('R')) {
				gameOver = false;
				algefrasoor = 1;
				menuPage = 0;

				// Reset stats
				playerHealth = playerMaxHealth;
				totalCreepsKilled = 0;
				levelComplete = false;
				bossSpawned = false;

				// Restart level directly 
				cutscenePage = 0;
				cutsceneFinished = true;
				gameLevel = 1;
			}
		}


		if (levelComplete == false) {
			//Moving creeeps
			for (int i = 0; i < creepCount; i++) {
				if (creeps[i].alive == true) {
					creeps[i].x = creeps[i].x - 3;

					if (creeps[i].x < 0) {
						creeps[i].x = screenwidth;
						creeps[i].hp = 2;
					}
				}
			}

			//Creep movement animation
			creepFrameTimer++;
			if (creepFrameTimer > 5) {
				for (int i = 0; i < creepCount; i++) {
					if (creeps[i].alive == true) {
						creeps[i].frame = (creeps[i].frame + 1) % 8;
					}
				}
				creepFrameTimer = 0;
			}

			//Attack logic
			if (playerAttacking == true) {
				for (int i = 0; i < creepCount; i++) {
					if (creeps[i].alive == true) {
						if (abs(playerX - creeps[i].x) < 150 && abs(playerY - creeps[i].y) < 250) {
							creeps[i].hp--;
							if (creeps[i].hp <= 0) {
								creeps[i].alive = false;
								totalCreepsKilled++;



								if (totalCreepsKilled < 6) {
									creeps[i].x = screenwidth;
									creeps[i].hp = 2;
									creeps[i].alive = true;
								}


							}
						}
					}
				}
			}
			//Prince Damage Logic 
			if (playerDamageCooldown > 0) {
				playerDamageCooldown--;
			}

			for (int i = 0; i < creepCount; i++) {
				if (creeps[i].alive == true) {
					//check collision
					if (abs(playerX - creeps[i].x) < 80 && abs(playerY - creeps[i].y) < 500) {
						if (playerDamageCooldown == 0) {
							playerHealth -= 10;
							if (playerHealth < 0) playerHealth = 0;
							playerDamageCooldown = 30;
						}
					}
					if (playerHealth <= 0) {
						playerHealth = 0;
						gameOver = true;
					}
				}
			}




			//Level completion
			if (totalCreepsKilled >= 6) {
				levelComplete = true;
			}



		}
		if (levelComplete && !bossSpawned) {
			initBoss();
		}

		updateBoss();


	}
	if (isKeyPressed(' '))
	{
		if (cutscenePage && !cutsceneFinished)
		{
			cutsceneFinished = true;
			cutscenePage = 0;
			gameLevel = 1;
		}

	}

	if (boomerasoor == 1){
		if (isKeyPressed('d'))
		{
			plMovesRight();
		}
		else if (isKeyPressed('a'))
		{
			plMovesLeft();
			if ((plX >= 900 && plX <= 920) && (plY >= 400 && plY <= 420)){
				finalPageButtonClickHandler();
			}
		}
		else
		{
			playerRunning = false;
		}
		plJump();

		checkRedLineCollision();
		checkPlatformCollision();
		if (boomPlayerDamageCooldown > 0) {
			boomPlayerDamageCooldown--;
		}

		//Game-over check 
		if (boomPlayerHealth <= 0) {
			boomPlayerHealth = 0;
			gameOver = true;
		}
		if (showHitImage) {
			hitImageTimer--;
			if (hitImageTimer <= 0) {
				showHitImage = false;
			}
		}

		// M to return to menu or R to restart 
		if (gameOver) {
			if (isKeyPressed('m') || isKeyPressed('M')) {
				gameOver = false;
				boomerasoor = 0;
				menuPage = 1;
				// Reset stats
				playerHealth = playerMaxHealth;
				levelComplete = false;

				// Restart level directly 
				cutscenePage = 0;
				cutsceneFinished = true;
				gameLevel = 1;

				// Reset BoomeraSoor state
				boomPlayerHealth = boomPlayerMaxHealth;
				boomPlayerDamageCooldown = 0;
				meteorsInited = 0;   
				respawnPlayer();
			}

			if (isKeyPressed('r') || isKeyPressed('R')) {
				gameOver = false;

				// Restart BoomeraSoor level
				boomPlayerHealth = boomPlayerMaxHealth;
				boomPlayerDamageCooldown = 0;
				meteorsInited = 0;
				respawnPlayer();

				boomerasoor = 1;
				menuPage = 0;
			}
		}
	}
	if (finalPage == 1) {

		// Spawn boss if not spawned
		if (!boomBossSpawned) initBoomBoss();
		updateBoomBoss(); 

		// Player movement
		if (isKeyPressed('d')) plMoveRight();
		else if (isKeyPressed('a')) plMoveLeft();
		else playerRunning = false;

		pJump();

		// Boss attack logic
		if (finalPage == 1 && boomBoss.alive) {
			int dx = abs(x - boomBoss.x);
			int dy = abs(y - boomBoss.y);

			if (boomBossAttacking && dx < boomBossAttackRangeX && dy < boomBossAttackRangeY) {
				// Only trigger damage and hit image if not already in damage cooldown
				if (playerDamageCooldown == 0) {
					playerTakeDamage(10);
					// Trigger hit image
					showHitImage = true;
					hitImageTimer = hitImageDuration;
				}
			}
			if (playerDamageCooldown > 0) {
				playerDamageCooldown--;
			}
		}
		if (showHitImage) {
			hitImageTimer--;
			if (hitImageTimer <= 0) {
				showHitImage = false;
				hitImageTimer = 0;
			}
		}

		// Reduce damage cooldown
		if (playerDamageCooldown > 0) playerDamageCooldown--;

		// Handle game over
		if (gameOver) {
			if (isKeyPressed('m') || isKeyPressed('M')) {
				// Return to menu
				gameOver = false;
				finalPage = 0;
				menuPage = 1;

				playerHealth = playerMaxHealth;
				playerArmor = playerMaxArmor;
				bool healthBoostUsed = false;

				boomBoss.alive = true;
				boomBoss.hp = boomBossMaxHP;

				cutscenePage = 0;
				cutsceneFinished = true;
			}

			if (isKeyPressed('r') || isKeyPressed('R')) {
				// Restart final level
				gameOver = false;

				playerHealth = playerMaxHealth;
				playerArmor = playerMaxArmor;


				boomBoss.alive = true;
				boomBoss.hp = boomBossMaxHP;

				finalPage = 1;
				cutscenePage = 0;
				cutsceneFinished = true;
			}

			return; 
		}
	}

}


int main()
{
	iSetTimer(1000, framechange);
	iSetTimer(1500, updateCutsceneImage);
	iSetTimer(50, updatePlayerFrame);
	
	iInitialize(screenwidth, screenheight, "Arabian Nights : Story of Prince Ed");
	loadResources();
	if (music) {
		playBackgroundMusic();
	}
	
	

	iStart();
	return 0;
}