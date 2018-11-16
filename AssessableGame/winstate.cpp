#include "winstate.h"



winstate::winstate()
{
}


winstate::~winstate()
{
}

void winstate::draw()
{
	ClearBackground(GREEN);
	DrawText("You Win", 10, 10, 40, BLACK);
	DrawText("[ ESC ] to exit, [ ENTER ] to play again", 10, 60, 20, BLACK);
}

GameStates winstate::next()
{
	if (IsKeyPressed(KEY_ENTER)) { // careful of overlapping keys
		return GameStates::MENU;
	}

	return GameStates::WIN;
}
