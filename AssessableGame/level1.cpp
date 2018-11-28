#include "level1.h"

level1::level1()
{
	background = LoadTexture("ocean.png");
	// enemyInstance = FishManager();
	// you're dumb this was initialized in .h 
	// but also look into this one??
}

level1::~level1()
{
	UnloadTexture(background);
}

void level1::update()
{
	player.update();
	enemyInstance.update();

	if (enemyInstance.checkForCollision(player.boundingBox()) == 2) {
		// make player smaller
		player.shrink();
	}
	if (enemyInstance.checkForCollision(player.boundingBox()) == 1) {
		// make player smaller
		player.grow();
	}

	// check for collisions
	// enemyInstance.checkForCollision();
	//for (int i = 0; i < enemies.idx; i++) {
	//	if (CheckCollisionRecs(enemies.fishies[i], {player.pos.x, player.pos.y,
	//		player.destRec.width, player.destRec.height})) {
	//		
	//		// compare sizes
	//		if (enemies.fishies[i].height > player.destRec.height) {
	//			player.shrink();
	//		}
	//		else {
	//			// grow
	//			player.grow();
	//			// delete enemy
	//			enemies.pop(i);				
	//		}
	//	}
	//}

	// update level given size of player
	// add win condition
}

void level1::draw()
{
	Rectangle source = { 0, 0, background.width, background.height };
	Rectangle dest = { 0, 0, GetScreenWidth(), GetScreenHeight() };
	// DrawTexturePro(background, source, dest, { 0, 0 }, 0, WHITE);
	// light blue
	ClearBackground({ 20, 231, 255, 0 });
	DrawText(std::to_string(player.health).c_str(), 10, 10, 20, BLACK);
	player.draw();
	enemyInstance.draw();
}

GameStates level1::next()
{
	if (player.health <= 0) {
		return GameStates::LOSE;
	}

	if (IsMouseButtonPressed(1)) {
		return GameStates::WIN;
	}

	return GameStates::LEVEL1;
}
