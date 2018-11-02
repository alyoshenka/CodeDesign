#include "Game.h"

Game::Game()
{
	windowW = 800;
	windowH = 450;
	floorH = 100;

	spriteW = 30;
	spriteH = 50;

	health = 100;

	x = windowW / 2;
	y = windowH - floorH - spriteH;
	speed = 5.0f;

	// blockIdx = 0;
	blockSpeed = 2;
	blockDamage = 1;
	blockW = 10;
	blockH = blockW;
	// make random blocks
	for (int i = 0; i < blockCount; i++) {
		// random rectangle
		blocks[i] = { (float)GetRandomValue(0, windowW - blockW),
			(float)GetRandomValue(0, (-1 * windowH)), (float)blockW, (float)blockH };
	}

	// default
	Image s = LoadImage("elf.png");
	ImageResize(&s, spriteW, spriteH);
	sprite = LoadTextureFromImage(s);
	UnloadImage(s);
	// sprite = LoadTexture("elf.png");
}


Game::~Game()
{
	UnloadTexture(sprite);
	// delete[] blocks;
}

Game & Game::GetInstance()
{
	static Game instance;
	return instance;
}

void Game::mainMenu()
{
	// draw and update?
	// update first, then draw
	ClearBackground(BLACK);

	DrawText("This is a game", 10, 10, 20, WHITE);

	DrawText("Press [ space ] to start", 10, 40, 50, WHITE);

	// if button pressed switch state

	if (IsKeyPressed(KEY_SPACE)) {
		GameState::GetInstance().setState(PlayerSelect);
	}
}

void Game::playerSelect()
{
	ClearBackground(BLUE);

	DrawText("This is where you would select your player", 10, 10, 20, BLACK);

	DrawText(" [ 1 ] for Elf, [ 2 ] for Wogol", 10, 40, 20, BLACK);

	// update
	if (IsKeyPressed(KEY_ONE)) {
		GameState::GetInstance().setState(InGame);
	}
	if (IsKeyPressed(KEY_TWO)) {
		// new sprite
		Image s = LoadImage("wogol.png");
		ImageResize(&s, spriteW, spriteH);
		sprite = LoadTextureFromImage(s);
		UnloadImage(s);
		GameState::GetInstance().setState(InGame);
		// sprite = LoadTexture("worol.png");
	}

}

void Game::inGame()
{
	ClearBackground(DARKGREEN);

	std::string output = "Health: " + std::to_string(health) + "%";
	DrawText(output.c_str(), 10, 10, 20, BLACK);

	DrawRectangle(0, windowH - floorH, windowW, floorH, BLACK);

	DrawTexture(sprite, x, y, WHITE);

	// update
	if (IsKeyDown(KEY_A)) {
		x -= speed;
	}
	if (IsKeyDown(KEY_D)) {
		x += speed;
	}
	if (x < 0) {
		x = 0;
	}
	if (x + spriteW > windowW) {
		x = windowW - spriteW;
	}

	// blocks
	for (int i = 0; i < blockCount; i++) {

		DrawRectangleRec(blocks[i], BLUE);

		blocks[i].y += blockSpeed;

		// if hit player
		if (CheckCollisionRecs(blocks[i], { (float)x, (float)y, (float)spriteW, (float)spriteH })) {
			health -= blockDamage;
		}

		// if past screen
		if (blocks[i].y > windowH) {
			// new value
			blocks[i] = {(float)GetRandomValue(0, windowW - blockW),
				(float)GetRandomValue(0, (-1 * windowH)), (float)blockW, (float)blockH};
		}
	}

	// game over
	if (health <= 0) {
		GameState::GetInstance().setState(GameOver);
	}
}

void Game::gameOver()
{
	ClearBackground(RED);

	DrawText("Game Over", 10, 10, 20, BLACK);

	DrawText(" [ Esc ] to exit", 10, 40, 20, BLACK);
}

void Game::dropBlocks()
{

}

void Game::go()
{
	switch (GameState::GetInstance().getState()) {

	case(MainMenu):
		mainMenu();
		break;
	case(PlayerSelect):
		playerSelect();
		break;
	case(InGame):
		inGame();
		break;
	case(GameOver):
		gameOver();
		break;
	default:
		mainMenu();
	}
}
