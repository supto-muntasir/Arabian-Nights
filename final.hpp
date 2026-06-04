#ifndef Final_HPP
#define Final_HPP

//Declare
void drawP();
void plMoveRight();
void plMoveLeft();
void pJump();

//Player position
int x = 40; 
int y = 119;
int plW = 130;
int plH = 130;
int jump = 10;
float gra = -0.3;
int gY = y;

void drawP(){
	if (playerRunning == false){
		if (playerAttacking == true) {
			if (attackFrame == 0) iShowImage(x, y, plW, plH, attack[0]);
			else if (attackFrame == 1) iShowImage(x, y, plW, plH, attack[1]);
			else if (attackFrame == 2) iShowImage(x, y, plW, plH, attack[2]);
			else if (attackFrame == 3) iShowImage(x, y, plW, plH, attack[3]);
			else if (attackFrame == 4) iShowImage(x, y, plW, plH, attack[4]);
			else if (attackFrame == 5) iShowImage(x, y, plW, plH, attack[5]);
		}
		else iShowImage(x, y, plW, plH, idle);
	}

	else if (playerRunning == true) {
		if (playerMovingRight == true) {
			if (playerFrame == 0) iShowImage(x, y, plW, plH, run[0]);
			else if (playerFrame == 1) iShowImage(x, y, plW, plH, run[1]);
			else if (playerFrame == 2) iShowImage(x, y, plW, plH, run[2]);
			else if (playerFrame == 3) iShowImage(x, y, plW, plH, run[3]);
			else if (playerFrame == 4) iShowImage(x, y, plW, plH, run[4]);
			else if (playerFrame == 5) iShowImage(x, y, plW, plH, run[5]);
			else if (playerFrame == 6) iShowImage(x, y, plW, plH, run[6]);
			else if (playerFrame == 7) iShowImage(x, y, plW, plH, run[7]);
		}
		else if (playerMovingRight == false){
			if (playerFrame == 0) iShowImage(x, y, plW, plH, left[0]);
			else if (playerFrame == 1) iShowImage(x, y, plW, plH, left[1]);
			else if (playerFrame == 2) iShowImage(x, y, plW, plH, left[2]);
			else if (playerFrame == 3) iShowImage(x, y, plW, plH, left[3]);
			else if (playerFrame == 4) iShowImage(x, y, plW, plH, left[4]);
			else if (playerFrame == 5) iShowImage(x, y, plW, plH, left[5]);
			else if (playerFrame == 6) iShowImage(x, y, plW, plH, left[6]);
			else if (playerFrame == 7) iShowImage(x, y, plW, plH, left[7]);
		}
	}
}

void plMoveRight(){
		playerRunning = true;
		playerMovingRight = true;
		if (x > 980) x = x;
		else x = x + 5;
}

void plMoveLeft(){
	playerRunning = true;
	playerMovingRight = false;
	if (x < 0) x = x;
	else x = x - 5;
}

void pJump(){
	if (playerJumping == false)
	{
		if (isKeyPressed('w'))
		{
			playerJumping = true;
			playerVelocityY = jump;
		}
	}
	if (playerJumping == true) {
		y = y + playerVelocityY;
		playerVelocityY = playerVelocityY + gra;


		if (y <= gY) {
			y = gY;
			playerJumping = false;
			playerVelocityY = 0;
		}
	}
}

//Armor

#endif