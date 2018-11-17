#include "level1.h"

level1::level1()
{
	background = LoadTexture("ocean.png");
}

level1::~level1()
{
	UnloadTexture(background);
}

void level1::update()
{
	player.update();
	enemies.update();

	// check for collisions
	for (int i = 0; i < enemies.idx; i++) {
		if (CheckCollisionRecs(enemies.fishies[i], {player.pos.x, player.pos.y,
			player.destRec.width, player.destRec.height})) {
			
			// compare sizes
			if (enemies.fishies[i].height > player.destRec.height) {
				player.shrink();
			}
			else {
				// grow
				player.grow();
				// delete enemy
				enemies.pop(i);				
			}
		}
	}
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
	enemies.draw();
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
