#ifndef BOOMBOSS_HPP
#define BOOMBOSS_HPP

#include "final.hpp"
#include "LoadImage.hpp"

// Boss state
struct BoomBoss {
	int  x;
	int  y;
	int  hp;
	bool alive;
};
BoomBoss boomBoss;

int  boomBossMaxHP = 30;
bool boomBossSpawned = false;

// Size / speed
int boomBossW = 200;
int boomBossH = 250;
int boomBossFootOffset = 20;
int boomBossSpeed = 3;

// Ranges
int boomBossFollowDeadzone = 8;
int boomBossAttackRangeX = 180;
int boomBossAttackRangeY = 180;

// Flags
bool boomBossAttacking = false;
bool boomBossFacingRight = false;
bool boomBossGettingHit = false;
bool boomBossDying = false;
bool boomBossDeathPending = false;
bool boomBossMoved = false;
bool boomBossHitLatched = false;

// Animation frames/timers
int boomBossWalkFrame = 0, boomBossWalkTimer = 0;   // 6 frames
int boomBossAttackFrame = 0, boomBossAttackTimer = 0;   // 16 frames
int boomBossHurtFrame = 0, boomBossHurtTimer = 0;   // 5 frames
int boomBossDeathFrame = 0, boomBossDeathTimer = 0;   // 20 frames
int boomBossDeathTickMax = 4;

// Fire VFX (pre-attack)
bool boomBossFireActive = false;
int  boomBossFireFrame = 0;
int  boomBossFireTimer = 0;
int  boomBossFireOffsetY = 100;
int  boomBossFireOffsetX_R = 120;
int  boomBossFireOffsetX_L = -60;
int  boomBossFireRangeX = 180 + 140; // attack range + padding
int  boomBossFireRangeY = 180 + 100;

// Setup
void initBoomBoss() {
	bool spawnRight = (x < (screenwidth / 2));
	if (spawnRight) {
		boomBoss.x = screenwidth + 200;
		boomBossFacingRight = false;
	}
	else {
		boomBoss.x = -200;
		boomBossFacingRight = true;
	}
	boomBoss.y = gY - boomBossFootOffset;

	boomBoss.hp = boomBossMaxHP;
	boomBoss.alive = true;

	boomBossAttacking = false;
	boomBossGettingHit = false;
	boomBossDying = false;
	boomBossDeathPending = false;

	boomBossWalkFrame = boomBossWalkTimer = 0;
	boomBossAttackFrame = boomBossAttackTimer = 0;
	boomBossHurtFrame = boomBossHurtTimer = 0;
	boomBossDeathFrame = boomBossDeathTimer = 0;

	boomBossMoved = false;
	boomBossHitLatched = false;

	boomBossFireActive = false;
	boomBossFireFrame = 0;
	boomBossFireTimer = 0;

	boomBossSpawned = true;
}

// Update (no player HP damage)
void updateBoomBoss() {
	if (!boomBossSpawned) return;
	if (!boomBoss.alive && !boomBossDying) return;

	// stick to ground
	boomBoss.y = gY - boomBossFootOffset;

	// face player
	boomBossFacingRight = (x - boomBoss.x) > 0;

	// boss gets hit by player (one hit per swing)
	if (playerAttacking) {
		if (!boomBossHitLatched &&
			abs(x - boomBoss.x) < 250 &&
			abs(y - boomBoss.y) < 320) {

			if (boomBoss.hp > 0) boomBoss.hp -= 1;
			boomBossHitLatched = true;

			boomBossGettingHit = true;
			boomBossHurtFrame = 0;
			boomBossHurtTimer = 0;

			if (boomBoss.hp == 0) boomBossDeathPending = true;
		}
	}
	else {
		boomBossHitLatched = false;
	}

	// hurt
	if (boomBossGettingHit) {
		boomBossHurtTimer++;
		if (boomBossHurtTimer > 4) {
			boomBossHurtTimer = 0;
			if (boomBossHurtFrame < 4) boomBossHurtFrame++;
			else {
				boomBossGettingHit = false;
				if (boomBossDeathPending) {
					boomBossDying = true;
					boomBossDeathPending = false;
					boomBossDeathFrame = 0;
					boomBossDeathTimer = 0;
				}
			}
		}
		return;
	}

	// death
	if (boomBossDying) {
		boomBossDeathTimer++;
		if (boomBossDeathTimer > boomBossDeathTickMax) {
			boomBossDeathTimer = 0;
			if (boomBossDeathFrame < 19) boomBossDeathFrame++;
			else {
				boomBoss.alive = false;
				boomBossDying = false;
			}
		}
		return;
	}

	// attack (visual only)
	bool nearForAttack =
		(abs(x - boomBoss.x) < boomBossAttackRangeX) &&
		(abs(y - boomBoss.y) < boomBossAttackRangeY);
	boomBossAttacking = nearForAttack;

	// Fire VFX while approaching (not yet in attack)
	bool onScreen = (boomBoss.x + boomBossW > 0) && (boomBoss.x < screenwidth);
	int dx = x - boomBoss.x;
	int dy = y - boomBoss.y;
	bool inPreAttack =
		(abs(dx) < boomBossFireRangeX) &&
		(abs(dy) < boomBossFireRangeY);

	boomBossFireActive = onScreen &&
		inPreAttack &&
		!boomBossAttacking &&
		!boomBossGettingHit &&
		!boomBossDying;

	if (boomBossFireActive) {
		if (++boomBossFireTimer > 3) {
			boomBossFireTimer = 0;
			boomBossFireFrame = (boomBossFireFrame + 1) % 8;
		}
	}
	else {
		boomBossFireFrame = 0;
		boomBossFireTimer = 0;
	}

	// movement (chase when not attacking)
	boomBossMoved = false;
	if (!boomBossAttacking) {
		int ddx = x - boomBoss.x;
		if (ddx > boomBossFollowDeadzone) { boomBoss.x += boomBossSpeed; boomBossMoved = true; }
		else if (ddx < -boomBossFollowDeadzone) { boomBoss.x -= boomBossSpeed; boomBossMoved = true; }
	}

	// animation clocks
	if (boomBossAttacking) {
		if (++boomBossAttackTimer > 4) {
			boomBossAttackTimer = 0;
			boomBossAttackFrame = (boomBossAttackFrame + 1) % 16;
		}
	}
	else if (boomBossMoved) {
		if (++boomBossWalkTimer > 5) {
			boomBossWalkTimer = 0;
			boomBossWalkFrame = (boomBossWalkFrame + 1) % 6;
		}
	}
}

// Draw
void drawBoomBoss() {
	if (!boomBossSpawned) return;
	if (!boomBoss.alive && !boomBossDying) return;

	// death
	if (boomBossDying) {
		int id = boomBossFacingRight ? boomBossDeathR[boomBossDeathFrame]
			: boomBossDeathL[boomBossDeathFrame];
		iShowImage(boomBoss.x, boomBoss.y, boomBossW, boomBossH, id);
		return;
	}

	// hurt
	if (boomBossGettingHit) {
		int id = boomBossFacingRight ? boomBossHurtR[boomBossHurtFrame]
			: boomBossHurtL[boomBossHurtFrame];
		iShowImage(boomBoss.x, boomBoss.y, boomBossW, boomBossH, id);
		return;
	}

	// attack
	if (boomBossAttacking) {
		int id = boomBossFacingRight ? boomBossAttackR[boomBossAttackFrame]
			: boomBossAttackL[boomBossAttackFrame];
		iShowImage(boomBoss.x, boomBoss.y, boomBossW, boomBossH, id);
		return;
	}

	// walk (default when not attacking/hurt/dead)
	int id = boomBossFacingRight ? boomBossWalkR[boomBossWalkFrame]
		: boomBossWalkL[boomBossWalkFrame];
	iShowImage(boomBoss.x, boomBoss.y, boomBossW, boomBossH, id);

	// Fire (draw in front)
	if (boomBossFireActive) {
		int fx = boomBossFacingRight
			? (boomBoss.x + boomBossFireOffsetX_R)
			: (boomBoss.x + boomBossFireOffsetX_L);
		int fy = boomBoss.y + boomBossFireOffsetY;
		iShowImage(fx, fy, 120, 120, boomFire1[boomBossFireFrame]);
	}
}


#endif // BOOMBOSS_HPP
