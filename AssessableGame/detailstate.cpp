#include "detailstate.h"



detailstate::detailstate()
{
}


detailstate::~detailstate()
{
}

void detailstate::draw()
{
	ClearBackground(WHITE);
	DrawText("Space to return", 100, 100, 30, BLACK);
}

GameStates detailstate::next()
{
	if (IsKeyPressed(KEY_SPACE)) {
		return GameStates::MENU;
	}

	return GameStates::DETAIL;
}
