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

	// DrawText("Press [ SPACE ] if you would like to save your name and score", 10, 150, 18, BLACK);
}

GameStates winstate::next()
{
	if (IsKeyPressed(KEY_SPACE)) {
		// return GameStates::SCORE;
	}
	if (IsKeyPressed(KEY_ENTER)){
		return GameStates::MENU;
	}

	return GameStates::WIN;
}
