#include "levelstate.h"

levelstate::levelstate()
{
	level = 1;
	healthSprite = LoadTexture("assets/fishR.png");
	hSize = 0.5f;
	// enemyInstance = FishManager();

	seaweedP = LoadTexture("assets/seaweedP.png");
	seaweedG = LoadTexture("assets/seaweedG.png");
	seaweedCount = GetRandomValue(3, 13);
	seaweedPos = new int[seaweedCount];
	isGreen = new bool[seaweedCount];

	// randomize
	for (int i = 0; i < seaweedCount; i++) {
		seaweedPos[i] = GetRandomValue(0, GetScreenWidth() - seaweedP.width);
		isGreen[i] = GetRandomValue(0, 1) == 0;
	}
}

levelstate::~levelstate()
{
	UnloadTexture(healthSprite);
	UnloadTexture(seaweedG);
	UnloadTexture(seaweedP);

	delete[] seaweedPos;
	delete[] isGreen;
}

void levelstate::update()
{
	player.update();
	enemyInstance.update();

	enemyInstance.addFish(level);

	// increase level given fish size
	// makes it so there is always one level of fish the player can't eat
	level = player.size / 0.5;

	int temp = enemyInstance.checkForCollision(player.boundingBox());

	if (temp == 0) {
		player.shrink();
	}
	else if (temp > 0) {
		player.grow(temp);
	}
}

void levelstate::draw()
{
	// just in case
	ClearBackground({ 20, 231, 255, 0 });
	DrawRectangleGradientV(0, 0, GetScreenWidth(), GetScreenHeight(), 
		{ 50, 230, 240, 255 }, { 0, 60, 200, 255 }); // light to dark blue

	// fish we can eat
	DrawText("Fish you can eat:", 520, 20, 20, BLACK);
	Color offWhite = { 255, 255, 255, 240 }; // slightly opaque
	DrawTexture(enemyInstance.fishPrototypes[0].sprite, 700, 5, offWhite);
	if (level > 1.0) {
		DrawTexture(enemyInstance.fishPrototypes[1].sprite, 770, 5, offWhite);
	}
	if (level > 2.0) {
		DrawTexture(enemyInstance.fishPrototypes[2].sprite, 840, 5, offWhite);
	}
	if (level > 3.0) {
		DrawTexture(enemyInstance.fishPrototypes[3].sprite, 910, 5, offWhite);
	}
	
	// health
	for (int i = 0; i < level; i ++) {
		// DrawTexture(player.spriteC, i * 20 + 10, 5, WHITE);
		DrawTexturePro(healthSprite, 
			{ 0, 0, (float)healthSprite.width, (float)healthSprite.height },
			{ 0, 0, healthSprite.width * hSize, healthSprite.height * hSize},
			{ (i * -30.0f) - 10, -30.0f }, 0, { 255, 70, 70, 240 }); // red tint
	}

	DrawText("Health:", 10, 10, 20, BLACK);
	player.draw();

	// seaweed
	for (int i = 0; i < seaweedCount; i++) {
		if (isGreen[i]) {
			DrawTexture(seaweedG, seaweedPos[i], GetScreenHeight() - seaweedG.height, WHITE);
		}
		else {
			DrawTexture(seaweedP, seaweedPos[i], GetScreenHeight() - seaweedP.height, WHITE);
		}
	}

	enemyInstance.draw();
}

GameStates levelstate::next()
{
	if (player.size < 0.4) {
		return GameStates::LOSE;
	}

	if (player.size > 5) { // 2.5
		// gamestate::score = player.currentSize;
		return GameStates::WIN;
	}

	return GameStates::LEVEL;
}
