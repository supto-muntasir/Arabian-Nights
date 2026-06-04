#ifndef Draw_HPP
#define Draw_HPP
#include "LoadImage.hpp"
#include "Algefrasoor.hpp"
#include "Boss.hpp"
#include "Bhombola.hpp"
#include "BhomBoss.hpp"
#include "BoomeraSoor.hpp"
#include "final.hpp"
#include "BoomBoss.hpp"
#include "BoomMeteors.hpp"




//To stop animation
int stop = 1;

//Loading animation
int frame = 0;

//Function declare
void drawLandingPage();
void drawLoadingPage();
void framechange();
void drawMenuPage();
void drawStartPage();
void drawStoryPage();
void drawOptionsOnPage();
void drawOptionsOffPage();
void drawCreditPage();
void drawCutscenePage();
void drawGameLevelPage();
void drawAlgefrasoorPage();
void drawBhombolaPage();
void drawBhombolaCreeps();
void drawBoomerasoorPage();
void drawFinalPage();
void updatePlayerFrame();



//Button click handler function
void landingPageButtonClickHandler();
void startButtonClickHandler();
void storyButtonClickHandler();
void optionsOnButtonClickHandler();
void optionsOffButtonClickHandler();
void creditButtonClickHandler();
void algefrasoorButtonClickHandler();
void bhombolaButtonClickHandler();
void boomerasoorButtonClickHandler();
void finalPageButtonClickHandler();

//

//Value for pages
int landingPage = 1;
int loadingPage = 0;
int menuPage = 0, startPage = 0, storyPage = 0, optionOnPage = 0, creditPage = 0, optionsOffPage = 0, cutscenePage = 0;
int screenTime = 0;
int gameLevel = 0;
int algefrasoor = 0, bhombola = 0;
int boomerasoor = 0, finalPage = 0;


bool music = true;

//Health Bar
int playerHealth = 100;         // Prince health
int playerMaxHealth = 100;   
bool gameOver = false;
bool bossDefeated = false;
//Music
bool isMusicPlaying = false;




//Draw pages

//Landing page
void drawLandingPage()
{
	iShowImage(0, 0, 1050, 700, landingPageBackground);
}
//

//Loading page
void drawLoadingPage()
{
	iShowImage(0, 0, 1050, 700, loadingPageBackground[frame]);
}
void framechange()
{
	frame++;
	stop++;
}
//

//Start page
void drawStartPage()
{
	iShowImage(0, 0, 1050, 700, startPageBackground);
}
//

void drawMenuPage()
{
	iShowImage(0, 0, 1050, 700, menuPageBackground);
}
//

void drawCreditPage()
{
	iShowImage(0, 0, 1050, 700, creditPageBackground);
}
//

void drawOptionsOnPage()
{
	iShowImage(0, 0, 1050, 700, optionsOnPageBackground);
}
//

void drawOptionsOffPage()
{
	iShowImage(0, 0, 1050, 700, optionsOffPageBackground);
}
//

void drawStoryPage()
{
	iShowImage(0, 0, 1050, 700, storyPageBackground);
}


//Cutscene page

void drawCutscenePage()
{
	// index of the cut scene should stay in the number of cutscene image
	if (currentCutsceneIndex < 0) currentCutsceneIndex = 0;
	if (currentCutsceneIndex >= totalCutsceneImages) currentCutsceneIndex = totalCutsceneImages - 1;

	iShowImage(0, 0, 1050, 700, cutsceneImages[currentCutsceneIndex]);
}

void updateCutsceneImage()
{
	if (cutscenePage && !cutsceneFinished)
	{
		if (currentCutsceneIndex < totalCutsceneImages - 1)
		{
			currentCutsceneIndex++;
		}
		else
		{
			// Last frame reached  finish cutscene and go to start page
			cutsceneFinished = true;
			cutscenePage = 0;
			gameLevel = 1;

		
		}
	}
}

//
//Game level page
void drawGameLevelPage()
{
	iShowImage(0, 0, 1050, 700, gameLevelbg);
}

//
//Algefrasoor page

void drawAlgefrasoorPage()
{
	iShowImage(0, 0, 1050, 700, algefrasoorBg);

	if (levelComplete == false){
    for (int i = 0; i < creepCount; i++) {
        if (creeps[i].alive == true) {
            iShowImage(creeps[i].x, creeps[i].y, 80, 80, creepRun[creeps[i].frame]);
        }
    }
}

// draw boss only after creeps are done
if (levelComplete == true) {
    drawBoss();
}



	if (playerRunning == false){
		if (playerAttacking == true) {
			if (attackFrame == 0) iShowImage(playerX, playerY, playerWidth, playerHeight, attack[0]);
			else if (attackFrame == 1) iShowImage(playerX, playerY, playerWidth, playerHeight, attack[1]);
			else if (attackFrame == 2) iShowImage(playerX, playerY, playerWidth, playerHeight, attack[2]);
			else if (attackFrame == 3) iShowImage(playerX, playerY, playerWidth, playerHeight, attack[3]);
			else if (attackFrame == 4) iShowImage(playerX, playerY, playerWidth, playerHeight, attack[4]);
			else if (attackFrame == 5) iShowImage(playerX, playerY, playerWidth, playerHeight, attack[5]);
		}
		else iShowImage(playerX, playerY, playerWidth, playerHeight, idle);
	}

	else if (playerRunning == true) {
		if (playerMovingRight == true) {
			if (playerFrame == 0) iShowImage(playerX, playerY, playerWidth, playerHeight, run[0]);
			else if (playerFrame == 1) iShowImage(playerX, playerY, playerWidth, playerHeight, run[1]);
			else if (playerFrame == 2) iShowImage(playerX, playerY, playerWidth, playerHeight, run[2]);
			else if (playerFrame == 3) iShowImage(playerX, playerY, playerWidth, playerHeight, run[3]);
			else if (playerFrame == 4) iShowImage(playerX, playerY, playerWidth, playerHeight, run[4]);
			else if (playerFrame == 5) iShowImage(playerX, playerY, playerWidth, playerHeight, run[5]);
			else if (playerFrame == 6) iShowImage(playerX, playerY, playerWidth, playerHeight, run[6]);
			else if (playerFrame == 7) iShowImage(playerX, playerY, playerWidth, playerHeight, run[7]);
		}
		else if (playerMovingRight == false){
			if (playerFrame == 0) iShowImage(playerX, playerY, playerWidth, playerHeight, left[0]);
			else if (playerFrame == 1) iShowImage(playerX, playerY, playerWidth, playerHeight, left[1]);
			else if (playerFrame == 2) iShowImage(playerX, playerY, playerWidth, playerHeight, left[2]);
			else if (playerFrame == 3) iShowImage(playerX, playerY, playerWidth, playerHeight, left[3]);
			else if (playerFrame == 4) iShowImage(playerX, playerY, playerWidth, playerHeight, left[4]);
			else if (playerFrame == 5) iShowImage(playerX, playerY, playerWidth, playerHeight, left[5]);
			else if (playerFrame == 6) iShowImage(playerX, playerY, playerWidth, playerHeight, left[6]);
			else if (playerFrame == 7) iShowImage(playerX, playerY, playerWidth, playerHeight, left[7]);
		}
	}
}

void updatePlayerFrame() {

	if (playerAttacking == true) {
		attackFrame++;
		if (attackFrame >= 6) {
			attackFrame = 0;
			playerAttacking = false;
		}
	}
	else if (playerRunning == true) {
		playerFrame = (playerFrame + 1) % 8;
	}
}


//Health Bar
void drawHealthBar(int x, int y, int width, int height) {
	iShowImage(-9, 640, 40, 40, heartImage);
	// Border background (gray)
	iSetColor(80, 80, 80);
	iRectangle(x, y, width, height);

	// Health percent
	float healthPercent = (float)playerHealth / playerMaxHealth;
	int currentWidth = (int)(width * healthPercent);

	// Color changes depending on health
	if (healthPercent > 0.5f)
		iSetColor(0, 200, 0);   // Green
	else if (healthPercent > 0.25f)
		iSetColor(255, 165, 0); // Orange
	else
		iSetColor(200, 0, 0);   // Red

	iFilledRectangle(x, y, currentWidth, height);

	// White outline
	iSetColor(255, 255, 255);
	iRectangle(x, y, width, height);
}

//Bhombola Page

void drawBhombolaCreeps()
{
	for (int i = 0; i < bhombolaCreepCount; i++) {
		if (bhombolaCreeps[i].alive) {
			iShowImage(bhombolaCreeps[i].x, bhombolaCreeps[i].y, 40, 40, creepR[bhombolaCreeps[i].frame]);
		}
	}
}

void drawBhombolaPage()
{
	// Draw the background at the current scroll position
	iShowImage(bgXBhom, 0, bgWidthBhom, screenheight, bhombolaBg);

	drawBhombolaCreeps();
	drawBhomBoss();
	drawPlayerMovement();
}

void drawBoomerasoorPage()
{
	iShowImage(0, 0, screenwidth, screenheight, boomerBg);
	drawBoomMeteors();
	drawPl();

}

void drawFinalPage(){
	iShowImage(0, 0, screenwidth, screenheight, finalBg);
	drawBoomBoss();
	drawP();
}







//Button click handler

void landingPageButtonClickHandler()
{
	landingPage = 0;
	loadingPage = 1;

}

void startButtonClickHandler()
{
	menuPage = 0;
	startPage = 0;
	cutscenePage = 1;
	screenTime = 0;
	
}

void storyButtonClickHandler()
{
	menuPage = 0;
	storyPage = 1;
	screenTime = 1;
}

void optionsOnButtonClickHandler()
{
	menuPage = 0;
	optionOnPage = 1;
	screenTime = 2;
}

void optionsOffButtonClickHandler()
{
	menuPage = 0;
	optionsOffPage = 1;
	screenTime = 4;
}

void creditButtonClickHandler()
{
	menuPage = 0;
	creditPage = 1;
	screenTime = 3;
}

void algefrasoorButtonClickHandler()
{
	gameLevel = 0;
	algefrasoor = 1;
	//Initialize creep properties
	initCreeps();
}

void bhombolaButtonClickHandler()
{
	gameLevel = 0;
	bhombola = 1;
}

void boomerasoorButtonClickHandler(){
	gameLevel = 0;
	boomerasoor = 1;
}

void finalPageButtonClickHandler(){
	boomerasoor = 0;
	finalPage = 1;
}


//Music
void stopMusic() {
	PlaySound(NULL, NULL, 0);
	isMusicPlaying = false;
}
void playBackgroundMusic() {
	if (music && !isMusicPlaying) {   // play only if ON and not already playing
		PlaySound("menuMusic.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		isMusicPlaying = true;
	}
}

void stopBackgroundMusic() {
	if (isMusicPlaying) {
		PlaySound(NULL, 0, 0);  // stops any sound
		isMusicPlaying = false;
	}
}





#endif