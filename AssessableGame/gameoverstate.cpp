#include "gameoverstate.h"



gameoverstate::gameoverstate()
{
}


gameoverstate::~gameoverstate()
{
}

void gameoverstate::update()
{
}

void gameoverstate::draw()
{
	// dark red
	ClearBackground({ 80, 0, 0, 0 });
	DrawText("GAME OVER", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 50, 50, BLACK);
	DrawText("[ ESC ] to exit, [ ENTER ] to play again", 10, 60, 20, BLACK);
}

GameStates gameoverstate::next()
{
	if (IsKeyPressed(KEY_ENTER)) {
		return GameStates::MENU;
	}

	return GameStates::LOSE;
}
