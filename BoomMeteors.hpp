#ifndef BOOMMETEORS_HPP
#define BOOMMETEORS_HPP

#include <stdlib.h>      // rand
#include "BoomeraSoor.hpp" // for screenheight (your page globals)
#include "LoadImage.hpp"   // for boomMeteor[] and iShowImage

// 4-lane meteors (Meteor1..3), very slow & desynced
const int METEOR_N = 4;

// state
int meteorX[METEOR_N] = { 120, 360, 640, 900 };
int meteorY[METEOR_N];
int meteorDelay[METEOR_N]; // frames per 1px move (bigger = slower)
int meteorTick[METEOR_N];  // frame counter
int meteorImg[METEOR_N];   // 0..2
int meteorsInited = 0;


void drawBoomMeteors() {
	if (!meteorsInited) {
		for (int i = 0; i < METEOR_N; i++) {
			meteorY[i] = screenheight + (rand() % 400);
			meteorDelay[i] = 12 + (rand() % 8);
			meteorTick[i] = rand() % meteorDelay[i];
			meteorImg[i] = rand() % 3;
		}
		meteorsInited = 1;
	}

	for (int i = 0; i < METEOR_N; i++) {
		// move
		meteorTick[i]++;
		if (meteorTick[i] >= meteorDelay[i]) {
			meteorTick[i] = 0;
			meteorY[i] -= 1;
			if ((rand() % (7 + i)) == 0) meteorY[i] -= 1;
		}

		//Collision
		if (meteorX[i] < plX + plWidth &&
			meteorX[i] + 64 > plX &&
			meteorY[i] < plY + plHeight &&
			meteorY[i] + 64 > plY)
		{
			// If player is not currently invulnerable, apply damage
			if (boomPlayerDamageCooldown == 0) {
				const int DAMAGE_PER_HIT = 40;
				boomPlayerHealth -= DAMAGE_PER_HIT;
				// Trigger hit image
				showHitImage = true;
				hitImageTimer = hitImageDuration;
				if (boomPlayerHealth < 0) boomPlayerHealth = 0;

				
				boomPlayerDamageCooldown = 30; 
			}



			// Respawn meteor
			meteorY[i] = screenheight + (rand() % 400);
			meteorDelay[i] = 12 + (rand() % 8);
			meteorTick[i] = rand() % meteorDelay[i];
			meteorImg[i] = rand() % 3;
		}

		// respawn when off bottom of screen
		if (meteorY[i] < -64) {
			meteorY[i] = screenheight + (rand() % 400);
			meteorDelay[i] = 12 + (rand() % 8);
			meteorTick[i] = rand() % meteorDelay[i];
			meteorImg[i] = rand() % 3;
		}

		// draw meteor
		iShowImage(meteorX[i], meteorY[i], 64, 64, boomMeteor[meteorImg[i]]);
	}
}

#endif // BOOMMETEORS_HPP
