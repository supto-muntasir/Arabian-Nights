#ifndef Load_HPP
#define Load_HPP


//Variables to load image
int landingPageBackground,menuPageBackground;
int loadingPageBackground[7];
int startPageBackground;
int storyPageBackground;
int creditPageBackground;
int optionsOnPageBackground;
int optionsOffPageBackground;
int gameLevelbg;
int totalCutsceneImages;
int cutsceneImages[8];       
int currentCutsceneIndex;
bool cutsceneFinished;
int algefrasoorBg;
int heartImage;
int gameOverImage;
int bossDieImage;
int bhombolaBg;
int boomerBg;
int finalBg;

//Player movement
int idle;
int run[8];
int left[8];
int attack[6];
int creepRun[8];
int bossWalk[12];
int bossAttack[15];
int bossGetHit[5];
int bossDeath[17];
int bossWalkR[12];
int bossAttackR[15];
int bossGetHitR[5];
int bossDeathR[17];
int creepR[8];

int bhomBossMove[12];
int bhomBossAttack[16];
int bhomBossHurt[7];

int bhomBossMoveR[12];     
int bhomBossAttackR[16];   
int bhomBossHurtR[7];      

// ===== Boomerasour Boss sprites (no Idle) =====
int boomBossWalkL[6], boomBossWalkR[6];
int boomBossAttackL[16], boomBossAttackR[16];
int boomBossHurtL[5], boomBossHurtR[5];
int boomBossDeathL[20], boomBossDeathR[20];
int boomFire1[8]; // fire VFX (8 frames)
// BoomBoss idle (2 frames, L/R)
int boomIdleL, boomIdleR;

int boomMeteor[3];

//blood

int bossHitImage;
int gameWinImage;





//Function declare
void loadResources();

//Load images
void loadResources()
{
	//booshit
	bossHitImage = iLoadImage("Asset\\blood.png");
	//final
   gameWinImage = iLoadImage("Asset\\victory.png");

	landingPageBackground = iLoadImage("Asset\\landingPageBg.png");
	loadingPageBackground[0] = iLoadImage("Asset\\loadingPage1.png");
	loadingPageBackground[1] = iLoadImage("Asset\\loadingPage2.png");
	loadingPageBackground[2] = iLoadImage("Asset\\loadingPage3.png");
	loadingPageBackground[3] = iLoadImage("Asset\\loadingPage4.png");
	loadingPageBackground[4] = iLoadImage("Asset\\loadingPage5.png");
	loadingPageBackground[5] = iLoadImage("Asset\\loadingPage6.png");
	loadingPageBackground[6] = iLoadImage("Asset\\loadingPage7.png");
	menuPageBackground = iLoadImage("Asset\\mainMenuBg.png");
	startPageBackground = iLoadImage("Asset\\startPageBackground.jpg");
	storyPageBackground = iLoadImage("Asset\\story.png");
	optionsOnPageBackground = iLoadImage("Asset\\musicOn.png");
	creditPageBackground = iLoadImage("Asset\\credit.png");
	optionsOffPageBackground = iLoadImage("Asset\\musicOff.png");

	totalCutsceneImages = 8;
	cutsceneImages[0] = iLoadImage("Asset\\Cut\\cutscene1.png");
	cutsceneImages[1] = iLoadImage("Asset\\Cut\\cutscene2.png");
	cutsceneImages[2] = iLoadImage("Asset\\Cut\\cutscene3.png");
	cutsceneImages[3] = iLoadImage("Asset\\Cut\\cutscene4.png");
	cutsceneImages[4] = iLoadImage("Asset\\Cut\\cutscene5.png");
	cutsceneImages[5] = iLoadImage("Asset\\Cut\\cutscene6.png");
	cutsceneImages[6] = iLoadImage("Asset\\Cut\\cutscene7.png");
	cutsceneImages[7] = iLoadImage("Asset\\Cut\\cutscene8.png");
	gameLevelbg = iLoadImage("Asset\\gameLevelBg.png");
	algefrasoorBg = iLoadImage("Asset\\algefrasoorBg.jpg");

	//Player related
	idle = iLoadImage("Asset\\idle.png");
	run[0] = iLoadImage("Asset\\run1.png");
	run[1] = iLoadImage("Asset\\run2.png");
	run[2] = iLoadImage("Asset\\run3.png");
	run[3] = iLoadImage("Asset\\run4.png");
	run[4] = iLoadImage("Asset\\run5.png");
	run[5] = iLoadImage("Asset\\run6.png");
	run[6] = iLoadImage("Asset\\run7.png");
	run[7] = iLoadImage("Asset\\run8.png");

	left[0] = iLoadImage("Asset\\brun1.png");
	left[1] = iLoadImage("Asset\\brun2.png");
	left[2] = iLoadImage("Asset\\brun3.png");
	left[3] = iLoadImage("Asset\\brun4.png");
	left[4] = iLoadImage("Asset\\brun5.png");
	left[5] = iLoadImage("Asset\\brun6.png");
	left[6] = iLoadImage("Asset\\brun7.png");
	left[7] = iLoadImage("Asset\\brun8.png");

	attack[0] = iLoadImage("Asset\\attack1.png");
	attack[1] = iLoadImage("Asset\\attack2.png");
	attack[2] = iLoadImage("Asset\\attack3.png");
	attack[3] = iLoadImage("Asset\\attack4.png");
	attack[4] = iLoadImage("Asset\\attack5.png");
	attack[5] = iLoadImage("Asset\\attack6.png");

	creepRun[0] = iLoadImage("Asset\\creepRun1.png");
	creepRun[1] = iLoadImage("Asset\\creepRun2.png");
	creepRun[2] = iLoadImage("Asset\\creepRun3.png");
	creepRun[3] = iLoadImage("Asset\\creepRun4.png");
	creepRun[4] = iLoadImage("Asset\\creepRun5.png");
	creepRun[5] = iLoadImage("Asset\\creepRun6.png");
	creepRun[6] = iLoadImage("Asset\\creepRun7.png");
	creepRun[7] = iLoadImage("Asset\\creepRun8.png");


	// Boss walk (12 frames)
	bossWalk[0] = iLoadImage("Asset\\BossWalk1.png");
	bossWalk[1] = iLoadImage("Asset\\BossWalk2.png");
	bossWalk[2] = iLoadImage("Asset\\BossWalk3.png");
	bossWalk[3] = iLoadImage("Asset\\BossWalk4.png");
	bossWalk[4] = iLoadImage("Asset\\BossWalk5.png");
	bossWalk[5] = iLoadImage("Asset\\BossWalk6.png");
	bossWalk[6] = iLoadImage("Asset\\BossWalk7.png");
	bossWalk[7] = iLoadImage("Asset\\BossWalk8.png");
	bossWalk[8] = iLoadImage("Asset\\BossWalk9.png");
	bossWalk[9] = iLoadImage("Asset\\BossWalk10.png");
	bossWalk[10] = iLoadImage("Asset\\BossWalk11.png");
	bossWalk[11] = iLoadImage("Asset\\BossWalk12.png");

	// Boss walkR (12 frames)
	bossWalkR[0] = iLoadImage("Asset\\BossWalkR1.png");
	bossWalkR[1] = iLoadImage("Asset\\BossWalkR2.png");
	bossWalkR[2] = iLoadImage("Asset\\BossWalkR3.png");
	bossWalkR[3] = iLoadImage("Asset\\BossWalkR4.png");
	bossWalkR[4] = iLoadImage("Asset\\BossWalkR5.png");
	bossWalkR[5] = iLoadImage("Asset\\BossWalkR6.png");
	bossWalkR[6] = iLoadImage("Asset\\BossWalkR7.png");
	bossWalkR[7] = iLoadImage("Asset\\BossWalkR8.png");
	bossWalkR[8] = iLoadImage("Asset\\BossWalkR9.png");
	bossWalkR[9] = iLoadImage("Asset\\BossWalkR10.png");
	bossWalkR[10] = iLoadImage("Asset\\BossWalkR11.png");
	bossWalkR[11] = iLoadImage("Asset\\BossWalkR12.png");

	// Boss attack (15 frames)
	bossAttack[0] = iLoadImage("Asset\\BossAttack\\BossAttack1.png");
	bossAttack[1] = iLoadImage("Asset\\BossAttack\\BossAttack2.png");
	bossAttack[2] = iLoadImage("Asset\\BossAttack\\BossAttack3.png");
	bossAttack[3] = iLoadImage("Asset\\BossAttack\\BossAttack4.png");
	bossAttack[4] = iLoadImage("Asset\\BossAttack\\BossAttack5.png");
	bossAttack[5] = iLoadImage("Asset\\BossAttack\\BossAttack6.png");
	bossAttack[6] = iLoadImage("Asset\\BossAttack\\BossAttack7.png");
	bossAttack[7] = iLoadImage("Asset\\BossAttack\\BossAttack8.png");
	bossAttack[8] = iLoadImage("Asset\\BossAttack\\BossAttack9.png");
	bossAttack[9] = iLoadImage("Asset\\BossAttack\\BossAttack10.png");
	bossAttack[10] = iLoadImage("Asset\\BossAttack\\BossAttack11.png");
	bossAttack[11] = iLoadImage("Asset\\BossAttack\\BossAttack12.png");
	bossAttack[12] = iLoadImage("Asset\\BossAttack\\BossAttack13.png");
	bossAttack[13] = iLoadImage("Asset\\BossAttack\\BossAttack14.png");
	bossAttack[14] = iLoadImage("Asset\\BossAttack\\BossAttack15.png");

	// Boss attackR (15 frames)
	bossAttackR[0] = iLoadImage("Asset\\BossAttack\\BossAttackR1.png");
	bossAttackR[1] = iLoadImage("Asset\\BossAttack\\BossAttackR2.png");
	bossAttackR[2] = iLoadImage("Asset\\BossAttack\\BossAttackR3.png");
	bossAttackR[3] = iLoadImage("Asset\\BossAttack\\BossAttackR4.png");
	bossAttackR[4] = iLoadImage("Asset\\BossAttack\\BossAttackR5.png");
	bossAttackR[5] = iLoadImage("Asset\\BossAttack\\BossAttackR6.png");
	bossAttackR[6] = iLoadImage("Asset\\BossAttack\\BossAttackR7.png");
	bossAttackR[7] = iLoadImage("Asset\\BossAttack\\BossAttackR8.png");
	bossAttackR[8] = iLoadImage("Asset\\BossAttack\\BossAttackR9.png");
	bossAttackR[9] = iLoadImage("Asset\\BossAttack\\BossAttackR10.png");
	bossAttackR[10] = iLoadImage("Asset\\BossAttack\\BossAttackR11.png");
	bossAttackR[11] = iLoadImage("Asset\\BossAttack\\BossAttackR12.png");
	bossAttackR[12] = iLoadImage("Asset\\BossAttack\\BossAttackR13.png");
	bossAttackR[13] = iLoadImage("Asset\\BossAttack\\BossAttackR14.png");
	bossAttackR[14] = iLoadImage("Asset\\BossAttack\\BossAttackR15.png");

	// Boss GetHit (5 frames)
	bossGetHit[0] = iLoadImage("Asset\\BossGetHit1.png");
	bossGetHit[1] = iLoadImage("Asset\\BossGetHit2.png");
	bossGetHit[2] = iLoadImage("Asset\\BossGetHit3.png");
	bossGetHit[3] = iLoadImage("Asset\\BossGetHit4.png");
	bossGetHit[4] = iLoadImage("Asset\\BossGetHit5.png");

	// Boss GetHitR (5 frames)
	bossGetHitR[0] = iLoadImage("Asset\\BossGetHitR1.png");
	bossGetHitR[1] = iLoadImage("Asset\\BossGetHitR2.png");
	bossGetHitR[2] = iLoadImage("Asset\\BossGetHitR3.png");
	bossGetHitR[3] = iLoadImage("Asset\\BossGetHitR4.png");
	bossGetHitR[4] = iLoadImage("Asset\\BossGetHitR5.png");


	// Boss Death (17 frames)
	bossDeath[0] = iLoadImage("Asset\\BossDeath\\BossDeath1.png");
	bossDeath[1] = iLoadImage("Asset\\BossDeath\\BossDeath2.png");
	bossDeath[2] = iLoadImage("Asset\\BossDeath\\BossDeath3.png");
	bossDeath[3] = iLoadImage("Asset\\BossDeath\\BossDeath4.png");
	bossDeath[4] = iLoadImage("Asset\\BossDeath\\BossDeath5.png");
	bossDeath[5] = iLoadImage("Asset\\BossDeath\\BossDeath6.png");
	bossDeath[6] = iLoadImage("Asset\\BossDeath\\BossDeath7.png");
	bossDeath[7] = iLoadImage("Asset\\BossDeath\\BossDeath8.png");
	bossDeath[8] = iLoadImage("Asset\\BossDeath\\BossDeath9.png");
	bossDeath[9] = iLoadImage("Asset\\BossDeath\\BossDeath10.png");
	bossDeath[10] = iLoadImage("Asset\\BossDeath\\BossDeath11.png");
	bossDeath[11] = iLoadImage("Asset\\BossDeath\\BossDeath12.png");
	bossDeath[12] = iLoadImage("Asset\\BossDeath\\BossDeath13.png");
	bossDeath[13] = iLoadImage("Asset\\BossDeath\\BossDeath14.png");
	bossDeath[14] = iLoadImage("Asset\\BossDeath\\BossDeath15.png");
	bossDeath[15] = iLoadImage("Asset\\BossDeath\\BossDeath16.png");
	bossDeath[16] = iLoadImage("Asset\\BossDeath\\BossDeath17.png");

	// Boss DeathR (17 frames)
	bossDeathR[0] = iLoadImage("Asset\\BossDeath\\BossDeathR1.png");
	bossDeathR[1] = iLoadImage("Asset\\BossDeath\\BossDeathR2.png");
	bossDeathR[2] = iLoadImage("Asset\\BossDeath\\BossDeathR3.png");
	bossDeathR[3] = iLoadImage("Asset\\BossDeath\\BossDeathR4.png");
	bossDeathR[4] = iLoadImage("Asset\\BossDeath\\BossDeathR5.png");
	bossDeathR[5] = iLoadImage("Asset\\BossDeath\\BossDeathR6.png");
	bossDeathR[6] = iLoadImage("Asset\\BossDeath\\BossDeathR7.png");
	bossDeathR[7] = iLoadImage("Asset\\BossDeath\\BossDeathR8.png");
	bossDeathR[8] = iLoadImage("Asset\\BossDeath\\BossDeathR9.png");
	bossDeathR[9] = iLoadImage("Asset\\BossDeath\\BossDeathR10.png");
	bossDeathR[10] = iLoadImage("Asset\\BossDeath\\BossDeathR11.png");
	bossDeathR[11] = iLoadImage("Asset\\BossDeath\\BossDeathR12.png");
	bossDeathR[12] = iLoadImage("Asset\\BossDeath\\BossDeathR13.png");
	bossDeathR[13] = iLoadImage("Asset\\BossDeath\\BossDeathR14.png");
	bossDeathR[14] = iLoadImage("Asset\\BossDeath\\BossDeathR15.png");
	bossDeathR[15] = iLoadImage("Asset\\BossDeath\\BossDeathR16.png");
	bossDeathR[16] = iLoadImage("Asset\\BossDeath\\BossDeathR17.png");

	heartImage = iLoadImage("Asset\\heart.png");
	gameOverImage = iLoadImage("Asset\\princeDie.png");
	bossDieImage = iLoadImage("Asset\\bossDie.png");

	bhombolaBg = iLoadImage("Asset\\bhomBg.png");

	//Bhombola creep
	creepR[0] = iLoadImage("Asset\\bhombola creep\\creepR1.png");
	creepR[1] = iLoadImage("Asset\\bhombola creep\\creepR2.png");
	creepR[2] = iLoadImage("Asset\\bhombola creep\\creepR3.png");
	creepR[3] = iLoadImage("Asset\\bhombola creep\\creepR4.png");
	creepR[4] = iLoadImage("Asset\\bhombola creep\\creepR5.png");
	creepR[5] = iLoadImage("Asset\\bhombola creep\\creepR6.png");
	creepR[6] = iLoadImage("Asset\\bhombola creep\\creepR7.png");
	creepR[7] = iLoadImage("Asset\\bhombola creep\\creepR8.png");


	// ===== Bhombola Boss (new sprites, no zero padding) =====

	// Attack (16 frames): atk_1_1.png … atk_1_16.png
	bhomBossAttack[0] = iLoadImage("Asset\\atk_1_1.png");
	bhomBossAttack[1] = iLoadImage("Asset\\atk_1_2.png");
	bhomBossAttack[2] = iLoadImage("Asset\\atk_1_3.png");
	bhomBossAttack[3] = iLoadImage("Asset\\atk_1_4.png");
	bhomBossAttack[4] = iLoadImage("Asset\\atk_1_5.png");
	bhomBossAttack[5] = iLoadImage("Asset\\atk_1_6.png");
	bhomBossAttack[6] = iLoadImage("Asset\\atk_1_7.png");
	bhomBossAttack[7] = iLoadImage("Asset\\atk_1_8.png");
	bhomBossAttack[8] = iLoadImage("Asset\\atk_1_9.png");
	bhomBossAttack[9] = iLoadImage("Asset\\atk_1_10.png");
	bhomBossAttack[10] = iLoadImage("Asset\\atk_1_11.png");
	bhomBossAttack[11] = iLoadImage("Asset\\atk_1_12.png");
	bhomBossAttack[12] = iLoadImage("Asset\\atk_1_13.png");
	bhomBossAttack[13] = iLoadImage("Asset\\atk_1_14.png");
	bhomBossAttack[14] = iLoadImage("Asset\\atk_1_15.png");
	bhomBossAttack[15] = iLoadImage("Asset\\atk_1_16.png");

	// Walk (12 frames): walk_1.png … walk_12.png
	bhomBossMove[0] = iLoadImage("Asset\\walk_1.png");
	bhomBossMove[1] = iLoadImage("Asset\\walk_2.png");
	bhomBossMove[2] = iLoadImage("Asset\\walk_3.png");
	bhomBossMove[3] = iLoadImage("Asset\\walk_4.png");
	bhomBossMove[4] = iLoadImage("Asset\\walk_5.png");
	bhomBossMove[5] = iLoadImage("Asset\\walk_6.png");
	bhomBossMove[6] = iLoadImage("Asset\\walk_7.png");
	bhomBossMove[7] = iLoadImage("Asset\\walk_8.png");
	bhomBossMove[8] = iLoadImage("Asset\\walk_9.png");
	bhomBossMove[9] = iLoadImage("Asset\\walk_10.png");
	bhomBossMove[10] = iLoadImage("Asset\\walk_11.png");
	bhomBossMove[11] = iLoadImage("Asset\\walk_12.png");

	// Idle (7 frames): idle_1.png … idle_7.png
	bhomBossHurt[0] = iLoadImage("Asset\\idle_1.png");
	bhomBossHurt[1] = iLoadImage("Asset\\idle_2.png");
	bhomBossHurt[2] = iLoadImage("Asset\\idle_3.png");
	bhomBossHurt[3] = iLoadImage("Asset\\idle_4.png");
	bhomBossHurt[4] = iLoadImage("Asset\\idle_5.png");
	bhomBossHurt[5] = iLoadImage("Asset\\idle_6.png");
	bhomBossHurt[6] = iLoadImage("Asset\\idle_7.png");



	// ===== Bhombola Boss: Attack Right (16 frames) =====
	bhomBossAttackR[0] = iLoadImage("Asset\\atk_1_1R.png");
	bhomBossAttackR[1] = iLoadImage("Asset\\atk_1_2R.png");
	bhomBossAttackR[2] = iLoadImage("Asset\\atk_1_3R.png");
	bhomBossAttackR[3] = iLoadImage("Asset\\atk_1_4R.png");
	bhomBossAttackR[4] = iLoadImage("Asset\\atk_1_5R.png");
	bhomBossAttackR[5] = iLoadImage("Asset\\atk_1_6R.png");
	bhomBossAttackR[6] = iLoadImage("Asset\\atk_1_7R.png");
	bhomBossAttackR[7] = iLoadImage("Asset\\atk_1_8R.png");
	bhomBossAttackR[8] = iLoadImage("Asset\\atk_1_9R.png");
	bhomBossAttackR[9] = iLoadImage("Asset\\atk_1_10R.png");
	bhomBossAttackR[10] = iLoadImage("Asset\\atk_1_11R.png");
	bhomBossAttackR[11] = iLoadImage("Asset\\atk_1_12R.png");
	bhomBossAttackR[12] = iLoadImage("Asset\\atk_1_13R.png");
	bhomBossAttackR[13] = iLoadImage("Asset\\atk_1_14R.png");
	bhomBossAttackR[14] = iLoadImage("Asset\\atk_1_15R.png");
	bhomBossAttackR[15] = iLoadImage("Asset\\atk_1_16R.png");

	// ===== Bhombola Boss: Walk Right (12 frames) =====
	bhomBossMoveR[0] = iLoadImage("Asset\\walk_1R.png");
	bhomBossMoveR[1] = iLoadImage("Asset\\walk_2R.png");
	bhomBossMoveR[2] = iLoadImage("Asset\\walk_3R.png");
	bhomBossMoveR[3] = iLoadImage("Asset\\walk_4R.png");
	bhomBossMoveR[4] = iLoadImage("Asset\\walk_5R.png");
	bhomBossMoveR[5] = iLoadImage("Asset\\walk_6R.png");
	bhomBossMoveR[6] = iLoadImage("Asset\\walk_7R.png");
	bhomBossMoveR[7] = iLoadImage("Asset\\walk_8R.png");
	bhomBossMoveR[8] = iLoadImage("Asset\\walk_9R.png");
	bhomBossMoveR[9] = iLoadImage("Asset\\walk_10R.png");
	bhomBossMoveR[10] = iLoadImage("Asset\\walk_11R.png");
	bhomBossMoveR[11] = iLoadImage("Asset\\walk_12R.png");

	// ===== Bhombola Boss: Idle/Hurt Right (7 frames) =====
	bhomBossHurtR[0] = iLoadImage("Asset\\idle_1R.png");
	bhomBossHurtR[1] = iLoadImage("Asset\\idle_2R.png");
	bhomBossHurtR[2] = iLoadImage("Asset\\idle_3R.png");
	bhomBossHurtR[3] = iLoadImage("Asset\\idle_4R.png");
	bhomBossHurtR[4] = iLoadImage("Asset\\idle_5R.png");
	bhomBossHurtR[5] = iLoadImage("Asset\\idle_6R.png");
	bhomBossHurtR[6] = iLoadImage("Asset\\idle_7R.png");


	//LAST

	boomerBg = iLoadImage("Asset\\boomerBg.png");
	finalBg = iLoadImage("Asset\\finalBg.jpg");


	// --- BoomBoss Idle ---
	boomIdleL = iLoadImage("Asset\\BoomIdleL.png");
	boomIdleR = iLoadImage("Asset\\BoomIdleR.png");

	// --- BoomBoss Walk ---
	boomBossWalkL[0] = iLoadImage("Asset\\BoomWalkL1.png");
	boomBossWalkL[1] = iLoadImage("Asset\\BoomWalkL2.png");
	boomBossWalkL[2] = iLoadImage("Asset\\BoomWalkL3.png");
	boomBossWalkL[3] = iLoadImage("Asset\\BoomWalkL4.png");
	boomBossWalkL[4] = iLoadImage("Asset\\BoomWalkL5.png");
	boomBossWalkL[5] = iLoadImage("Asset\\BoomWalkL6.png");

	boomBossWalkR[0] = iLoadImage("Asset\\BoomWalkR1.png");
	boomBossWalkR[1] = iLoadImage("Asset\\BoomWalkR2.png");
	boomBossWalkR[2] = iLoadImage("Asset\\BoomWalkR3.png");
	boomBossWalkR[3] = iLoadImage("Asset\\BoomWalkR4.png");
	boomBossWalkR[4] = iLoadImage("Asset\\BoomWalkR5.png");
	boomBossWalkR[5] = iLoadImage("Asset\\BoomWalkR6.png");


	// --- BoomBoss Attack ---
	boomBossAttackL[0] = iLoadImage("Asset\\BoomBossAttackL1.png");
	boomBossAttackL[1] = iLoadImage("Asset\\BoomBossAttackL2.png");
	boomBossAttackL[2] = iLoadImage("Asset\\BoomBossAttackL3.png");
	boomBossAttackL[3] = iLoadImage("Asset\\BoomBossAttackL4.png");
	boomBossAttackL[4] = iLoadImage("Asset\\BoomBossAttackL5.png");
	boomBossAttackL[5] = iLoadImage("Asset\\BoomBossAttackL6.png");
	boomBossAttackL[6] = iLoadImage("Asset\\BoomBossAttackL7.png");
	boomBossAttackL[7] = iLoadImage("Asset\\BoomBossAttackL8.png");
	boomBossAttackL[8] = iLoadImage("Asset\\BoomBossAttackL9.png");
	boomBossAttackL[9] = iLoadImage("Asset\\BoomBossAttackL10.png");
	boomBossAttackL[10] = iLoadImage("Asset\\BoomBossAttackL11.png");
	boomBossAttackL[11] = iLoadImage("Asset\\BoomBossAttackL12.png");
	boomBossAttackL[12] = iLoadImage("Asset\\BoomBossAttackL13.png");
	boomBossAttackL[13] = iLoadImage("Asset\\BoomBossAttackL14.png");
	boomBossAttackL[14] = iLoadImage("Asset\\BoomBossAttackL15.png");
	boomBossAttackL[15] = iLoadImage("Asset\\BoomBossAttackL16.png");

	boomBossAttackR[0] = iLoadImage("Asset\\BoomBossAttackR1.png");
	boomBossAttackR[1] = iLoadImage("Asset\\BoomBossAttackR2.png");
	boomBossAttackR[2] = iLoadImage("Asset\\BoomBossAttackR3.png");
	boomBossAttackR[3] = iLoadImage("Asset\\BoomBossAttackR4.png");
	boomBossAttackR[4] = iLoadImage("Asset\\BoomBossAttackR5.png");
	boomBossAttackR[5] = iLoadImage("Asset\\BoomBossAttackR6.png");
	boomBossAttackR[6] = iLoadImage("Asset\\BoomBossAttackR7.png");
	boomBossAttackR[7] = iLoadImage("Asset\\BoomBossAttackR8.png");
	boomBossAttackR[8] = iLoadImage("Asset\\BoomBossAttackR9.png");
	boomBossAttackR[9] = iLoadImage("Asset\\BoomBossAttackR10.png");
	boomBossAttackR[10] = iLoadImage("Asset\\BoomBossAttackR11.png");
	boomBossAttackR[11] = iLoadImage("Asset\\BoomBossAttackR12.png");
	boomBossAttackR[12] = iLoadImage("Asset\\BoomBossAttackR13.png");
	boomBossAttackR[13] = iLoadImage("Asset\\BoomBossAttackR14.png");
	boomBossAttackR[14] = iLoadImage("Asset\\BoomBossAttackR15.png");
	boomBossAttackR[15] = iLoadImage("Asset\\BoomBossAttackR16.png");


	// --- BoomBoss Hurt ---
	boomBossHurtL[0] = iLoadImage("Asset\\BoomBossHurtL1.png");
	boomBossHurtL[1] = iLoadImage("Asset\\BoomBossHurtL2.png");
	boomBossHurtL[2] = iLoadImage("Asset\\BoomBossHurtL3.png");
	boomBossHurtL[3] = iLoadImage("Asset\\BoomBossHurtL4.png");
	boomBossHurtL[4] = iLoadImage("Asset\\BoomBossHurtL5.png");

	boomBossHurtR[0] = iLoadImage("Asset\\BoomBossHurtR1.png");
	boomBossHurtR[1] = iLoadImage("Asset\\BoomBossHurtR2.png");
	boomBossHurtR[2] = iLoadImage("Asset\\BoomBossHurtR3.png");
	boomBossHurtR[3] = iLoadImage("Asset\\BoomBossHurtR4.png");
	boomBossHurtR[4] = iLoadImage("Asset\\BoomBossHurtR5.png");


	// --- BoomBoss Death ---
	boomBossDeathL[0] = iLoadImage("Asset\\BoomBossDeathL1.png");
	boomBossDeathL[1] = iLoadImage("Asset\\BoomBossDeathL2.png");
	boomBossDeathL[2] = iLoadImage("Asset\\BoomBossDeathL3.png");
	boomBossDeathL[3] = iLoadImage("Asset\\BoomBossDeathL4.png");
	boomBossDeathL[4] = iLoadImage("Asset\\BoomBossDeathL5.png");
	boomBossDeathL[5] = iLoadImage("Asset\\BoomBossDeathL6.png");
	boomBossDeathL[6] = iLoadImage("Asset\\BoomBossDeathL7.png");
	boomBossDeathL[7] = iLoadImage("Asset\\BoomBossDeathL8.png");
	boomBossDeathL[8] = iLoadImage("Asset\\BoomBossDeathL9.png");
	boomBossDeathL[9] = iLoadImage("Asset\\BoomBossDeathL10.png");
	boomBossDeathL[10] = iLoadImage("Asset\\BoomBossDeathL11.png");
	boomBossDeathL[11] = iLoadImage("Asset\\BoomBossDeathL12.png");
	boomBossDeathL[12] = iLoadImage("Asset\\BoomBossDeathL13.png");
	boomBossDeathL[13] = iLoadImage("Asset\\BoomBossDeathL14.png");
	boomBossDeathL[14] = iLoadImage("Asset\\BoomBossDeathL15.png");
	boomBossDeathL[15] = iLoadImage("Asset\\BoomBossDeathL16.png");
	boomBossDeathL[16] = iLoadImage("Asset\\BoomBossDeathL17.png");
	boomBossDeathL[17] = iLoadImage("Asset\\BoomBossDeathL18.png");
	boomBossDeathL[18] = iLoadImage("Asset\\BoomBossDeathL19.png");
	boomBossDeathL[19] = iLoadImage("Asset\\BoomBossDeathL20.png");

	boomBossDeathR[0] = iLoadImage("Asset\\BoomBossDeathR1.png");
	boomBossDeathR[1] = iLoadImage("Asset\\BoomBossDeathR2.png");
	boomBossDeathR[2] = iLoadImage("Asset\\BoomBossDeathR3.png");
	boomBossDeathR[3] = iLoadImage("Asset\\BoomBossDeathR4.png");
	boomBossDeathR[4] = iLoadImage("Asset\\BoomBossDeathR5.png");
	boomBossDeathR[5] = iLoadImage("Asset\\BoomBossDeathR6.png");
	boomBossDeathR[6] = iLoadImage("Asset\\BoomBossDeathR7.png");
	boomBossDeathR[7] = iLoadImage("Asset\\BoomBossDeathR8.png");
	boomBossDeathR[8] = iLoadImage("Asset\\BoomBossDeathR9.png");
	boomBossDeathR[9] = iLoadImage("Asset\\BoomBossDeathR10.png");
	boomBossDeathR[10] = iLoadImage("Asset\\BoomBossDeathR11.png");
	boomBossDeathR[11] = iLoadImage("Asset\\BoomBossDeathR12.png");
	boomBossDeathR[12] = iLoadImage("Asset\\BoomBossDeathR13.png");
	boomBossDeathR[13] = iLoadImage("Asset\\BoomBossDeathR14.png");
	boomBossDeathR[14] = iLoadImage("Asset\\BoomBossDeathR15.png");
	boomBossDeathR[15] = iLoadImage("Asset\\BoomBossDeathR16.png");
	boomBossDeathR[16] = iLoadImage("Asset\\BoomBossDeathR17.png");
	boomBossDeathR[17] = iLoadImage("Asset\\BoomBossDeathR18.png");
	boomBossDeathR[18] = iLoadImage("Asset\\BoomBossDeathR19.png");
	boomBossDeathR[19] = iLoadImage("Asset\\BoomBossDeathR20.png");


	boomFire1[0] = iLoadImage("Asset\\Fire1.png");
	boomFire1[1] = iLoadImage("Asset\\Fire2.png");
	boomFire1[2] = iLoadImage("Asset\\Fire3.png");
	boomFire1[3] = iLoadImage("Asset\\Fire4.png");
	boomFire1[4] = iLoadImage("Asset\\Fire5.png");
	boomFire1[5] = iLoadImage("Asset\\Fire6.png");
	boomFire1[6] = iLoadImage("Asset\\Fire7.png");
	boomFire1[7] = iLoadImage("Asset\\Fire8.png");

	boomMeteor[0] = iLoadImage("Asset\\Meteor1.png");
	boomMeteor[1] = iLoadImage("Asset\\Meteor2.png");
	boomMeteor[2] = iLoadImage("Asset\\Meteor3.png");


}
#endif