#ifndef BOSS_HPP
#define BOSS_HPP


// From player / global values

extern int  playerHealth;
extern int  playerDamageCooldown;
extern int  playerX;
extern int  playerY;
extern bool gameOver;
extern bool bossDefeated;


// Boss state

struct Boss {
	int  x;
	int  y;
	int  hp;
	bool alive;
};

Boss boss;
bool bossSpawned = false;

// Size / speed

int bossWidth = 260;
int bossHeight = 340;
int bossFootOffset = 20;
int bossSpeed = 3;

// Combat values

int  bossMaxHP = 30;
bool bossHitLatched = false;


// Ranges

int bossAttackRangeX = 180;
int bossAttackRangeY = 180;


// Flags

bool bossAttacking = false;
bool bossGettingHit = false;
bool bossDeathPending = false;
bool bossDying = false;
bool bossFacingRight = false;


// Animation counters

int bossWalkFrame = 0, bossWalkTimer = 0;
int bossAttackFrame = 0, bossAttackTimer = 0;
int bossGetHitFrame = 0, bossGetHitTimer = 0;
int bossDeathFrame = 0, bossDeathTimer = 0;


// Spawn / chase helpers

int bossFollowDeadzone = 8;
int bossSpawnLock = 60;
int bossSpawnLockTimer = 0;


// Timings

int bossAttackLock = 0, bossAttackLockMax = 10;
int bossGetHitLock = 0, bossGetHitLockMax = 20;
int bossDeathTimerMax = 4;


// Setup

void initBoss() {
	boss.x = screenwidth + 400;
	boss.y = groundY - bossFootOffset;
	boss.hp = bossMaxHP;
	boss.alive = true;

	bossAttacking = false;
	bossGettingHit = false;
	bossDeathPending = false;
	bossDying = false;
	bossHitLatched = false;
	bossFacingRight = false;
	bossSpawnLockTimer = bossSpawnLock;

	bossWalkFrame = bossWalkTimer = 0;
	bossAttackFrame = bossAttackTimer = 0;
	bossGetHitFrame = bossGetHitTimer = 0;
	bossGetHitLock = 0;
	bossDeathFrame = bossDeathTimer = 0;

	bossAttackLock = 0;

	bossSpawned = true;
}


// Update

void updateBoss() {
	if (!bossSpawned) return;
	if (!boss.alive)  return;

	boss.y = groundY - bossFootOffset;

	// Damage taken from player
	if (playerAttacking) {
		if (!bossHitLatched &&
			abs(playerX - boss.x) < 250 &&
			abs(playerY - boss.y) < 320) {

			boss.hp--;
			bossHitLatched = true;

			bossGettingHit = true;
			bossGetHitFrame = 0;
			bossGetHitTimer = 0;
			bossGetHitLock = bossGetHitLockMax;

			if (boss.hp <= 0) {
				bossDeathPending = true;
				bossGetHitLock = 1;
			}
			
		}
	}
	else {
		bossHitLatched = false;
	}

	// Get-Hit animation
	if (bossGettingHit) {
		bossGetHitTimer++;
		if (bossGetHitTimer > 4) {
			bossGetHitTimer = 0;
			bossGetHitFrame = (bossGetHitFrame + 1) % 5;
		}

		if (bossGetHitLock > 0) bossGetHitLock--;
		if (bossGetHitLock == 0) {
			bossGettingHit = false;

			if (bossDeathPending) {
				bossDying = true;
				bossDeathFrame = 0;
				bossDeathTimer = 0;
				return;
			}
		}
		return;
	}

	// Death animation
	if (bossDying) {
		bossDeathTimer++;
		if (bossDeathTimer > bossDeathTimerMax) {
			bossDeathTimer = 0;
			if (bossDeathFrame < 16) {
				bossDeathFrame++;
			}
			else {
				boss.alive = false;   
				bossDying = false;
				bossDefeated = true;    
				return;
			}
		}
		return;
	}

	// Attack / walk switch
	bool nearForAttack =
		(abs(playerX - boss.x) < bossAttackRangeX) &&
		(abs(playerY - boss.y) < bossAttackRangeY);

	if (!bossAttacking && nearForAttack) {
		bossAttacking = true;
		bossAttackLock = bossAttackLockMax;
		bossFacingRight = (playerX - boss.x) > 0;
	}

	if (bossAttacking) {
		if (bossAttackLock > 0) bossAttackLock--;
		if (bossAttackLock == 0) {
			if (nearForAttack) bossAttackLock = bossAttackLockMax;
			else {
				bossAttacking = false;
				bossAttackFrame = 0;
				bossAttackTimer = 0;
			}
		}
	}

	// Player damage from boss
	if (playerDamageCooldown > 0) playerDamageCooldown--;

	if (bossAttacking) {
		if (bossAttackFrame >= 6 && bossAttackFrame <= 9) {
			int bossCenterX = boss.x + bossWidth / 2;
			int bossCenterY = boss.y + (bossHeight / 3);

			if (abs(playerX - bossCenterX) < bossAttackRangeX &&
				abs(playerY - bossCenterY) < bossAttackRangeY) {

				if (playerDamageCooldown == 0) {
					playerHealth -= 20;
					playerDamageCooldown = 40;
					if (playerHealth < 0) playerHealth = 0;
				}
			}
			if (playerHealth <= 0) {
				playerHealth = 0;
				gameOver = true;
			}
		}
	}

	// Walk / attack animation advance and movement
	if (!bossAttacking) {
		bool moved = false;

		if (bossSpawnLockTimer > 0) {
			boss.x -= bossSpeed;
			bossFacingRight = false;
			bossSpawnLockTimer--;
			moved = true;
		}
		else {
			int dx = playerX - boss.x;

			if (dx > bossFollowDeadzone) {
				boss.x += bossSpeed;
				bossFacingRight = true;
				moved = true;
			}
			else if (dx < -bossFollowDeadzone) {
				boss.x -= bossSpeed;
				bossFacingRight = false;
				moved = true;
			}
		}

		if (moved) {
			bossWalkTimer++;
			if (bossWalkTimer > 5) {
				bossWalkTimer = 0;
				bossWalkFrame = (bossWalkFrame + 1) % 12;
			}
		}
	}
	else {
		bossAttackTimer++;
		if (bossAttackTimer > 4) {
			bossAttackTimer = 0;
			bossAttackFrame = (bossAttackFrame + 1) % 15;
		}
	}

	// Despawn safety
	if (!bossDying && boss.x < -200) {
		boss.alive = false;
		return;
	}
}


// Draw
void drawBoss() {
	if (!boss.alive && !bossDying) return;

	if (bossDying) {
		int id;
		if (bossFacingRight) {
			id = bossDeathR[bossDeathFrame];
		}
		else {
			id = bossDeath[bossDeathFrame];
		}
		iShowImage(boss.x, boss.y, bossWidth, bossHeight, id);
		return;
	}

	if (bossGettingHit) {
		int id;
		if (bossFacingRight) {
			id = bossGetHitR[bossGetHitFrame];
		}
		else {
			id = bossGetHit[bossGetHitFrame];
		}
		iShowImage(boss.x, boss.y, bossWidth, bossHeight, id);
		return;
	}

	if (bossAttacking) {
		int id;
		if (bossFacingRight) {
			id = bossAttackR[bossAttackFrame];
		}
		else {
			id = bossAttack[bossAttackFrame];
		}
		iShowImage(boss.x, boss.y, bossWidth, bossHeight, id);
		return;
	}

	int id;
	if (bossFacingRight) {
		id = bossWalkR[bossWalkFrame];
	}
	else {
		id = bossWalk[bossWalkFrame];
	}
	iShowImage(boss.x, boss.y, bossWidth, bossHeight, id);
}

#endif

