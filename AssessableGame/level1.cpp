#include "level1.h"

level1::level1()
{
	level = 1;
	healthSprite = LoadTexture("assets/fishR.png");
	hSize = 0.5f;
	// enemyInstance = FishManager();
}

level1::~level1()
{
	UnloadTexture(healthSprite);
}

void level1::update()
{
	player.update();
	enemyInstance.update();

	enemyInstance.addFish(level);

	// increase level given fish size
	// makes it so there is always one level of fish the player can't eat
	level = player.size / 0.5 + 1;

	int temp = enemyInstance.checkForCollision(player.boundingBox());

	if (temp == 0) {
		player.shrink();
	}
	else if (temp > 0) {
		player.grow(temp);
	}
}

void level1::draw()
{
	ClearBackground({ 20, 231, 255, 0 });

	// fish we can eat
	DrawText("Fish you can eat:", 520, 20, 20, BLACK);
	DrawTexture(enemyInstance.fishPrototypes[0].sprite, 700, 5, WHITE);
	if (level > 2.0) {
		DrawTexture(enemyInstance.fishPrototypes[1].sprite, 770, 5, WHITE);
	}
	if (level > 3.0) {
		DrawTexture(enemyInstance.fishPrototypes[2].sprite, 840, 5, WHITE);
	}
	if (level > 4.0) {
		DrawTexture(enemyInstance.fishPrototypes[3].sprite, 910, 5, WHITE);
	}

	// health
	for (int i = 1; i < level; i ++) {
		// DrawTexture(player.spriteC, i * 20 + 10, 5, WHITE);
		DrawTexturePro(healthSprite, 
			{ 0, 0, (float)healthSprite.width, (float)healthSprite.height },
			{ 0, 0, healthSprite.width * hSize, healthSprite.height * hSize},
			{(i * -30.0f) + 25, -30.0f}, 0, WHITE);
	}

	DrawText("Health:", 10, 10, 20, BLACK);
	player.draw();
	enemyInstance.draw();
}

GameStates level1::next()
{
	if (player.size < 0.4) {
		return GameStates::LOSE;
	}

	if (player.size > 2.5) {
		// gamestate::score = player.currentSize;
		return GameStates::WIN;
	}

	return GameStates::LEVEL1;
}
