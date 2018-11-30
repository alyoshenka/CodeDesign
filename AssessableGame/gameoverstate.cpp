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
	ClearBackground({ 120, 0, 0, 0 });
	DrawText("GAME OVER", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 100, 50, BLACK);
	DrawText("[ ESC ] to exit, [ ENTER ] to play again", 300, 300, 20, BLACK);
}

GameStates gameoverstate::next()
{
	if (IsKeyPressed(KEY_ENTER)) {
		return GameStates::MENU;
	}

	return GameStates::LOSE;
}
