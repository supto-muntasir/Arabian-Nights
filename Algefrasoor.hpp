#ifndef Boss_HPP
#define Boss_HPP
#include "DrawPages.hpp"

//Screen width and height
const int screenwidth = 1050;
const int screenheight = 700;

//Player position
int playerX = 78;
int playerY = 63;
int playerWidth = 150;
int playerHeight = 150;
int playerFrame = 0;
bool playerRunning = false;
bool playerMovingRight = true;
bool playerAttacking = false;
int attackFrame = 0;
bool playerJumping = false;
float playerVelocityY = 0;
const float gravity = -0.7;
const float jumpStrength = 15;
const int groundY = playerY;


//Function
void initCreeps();

//Creep
struct Creep {
	int x, y;           
	int hp;             
	bool alive;         
	int frame;
};

const int creepCount = 2;
Creep creeps[creepCount];

int creepFrameTimer = 0;
int totalCreepsKilled = 0;
bool levelComplete = false;

void initCreeps() {
	for (int i = 0; i < creepCount; i++) {
		creeps[i].x = screenwidth + (i * 150);
		creeps[i].y = 130;
		creeps[i].hp = 2;
		creeps[i].alive = true;
		creeps[i].frame = 0;
	}	
}

#endif