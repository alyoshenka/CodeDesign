#include "level1.h"

level1::level1()
{
	level = 1;
	// enemyInstance = FishManager();
	// you're dumb this was initialized in .h 
	// but also look into this one??
}

level1::~level1()
{
}

void level1::update()
{
	player.update();
	enemyInstance.update();

	enemyInstance.addFish(level);

	// increase level given fish size
	// BETTER WAY TO DO THIS
	// makes it so there is always one level of fish the player can't eat
	level = player.size / 0.5 + 1;

	/*if (player.currentSize < 0.5) {
		level = 1;
	}else if (player.currentSize < 1.0) {
		level = 2;
	}else if (player.currentSize < 1.5) {
		level = 3;
	}else if (player.currentSize < 2.0) {
		level = 4;
	}*/

	int temp = enemyInstance.checkForCollision(player.boundingBox());

	if (temp == 2) {
		player.shrink();
	} 
	if (temp == 1) {
		player.grow();
	}
}

void level1::draw()
{
	ClearBackground({ 20, 231, 255, 0 });

	// fish we can eat


	DrawText(std::to_string(player.size).c_str(), 10, 10, 20, BLACK);
	player.draw();
	enemyInstance.draw();
}

GameStates level1::next()
{
	if (player.size < 0.4) {
		return GameStates::LOSE;
	}

	if (player.size > 2) {
		// gamestate::score = player.currentSize;
		return GameStates::WIN;
	}

	return GameStates::LEVEL1;
}
