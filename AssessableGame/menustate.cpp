#include "menustate.h"

menustate::menustate()
{
	// button size
	int size = 100;

	// center buttons
	start.x = GetScreenWidth() / 2 - size;
	start.y = GetScreenHeight() / 2.0f - size / 2 - 50;
	start.width = size * 2;
	start.height = size / 2;

	controls = start;
	controls.y = start.y + size;	
}


menustate::~menustate()
{
}

void menustate::update()
{
}

void menustate::draw()
{
	// background
	// dark pruple
	ClearBackground({ 30, 0, 26, 0 });
	for (int y = 0; y < GetScreenHeight(); y += 20) {
		for (int x = 0; x < GetScreenWidth(); x += 20) {
			DrawCircle(x, y, 5, BLACK);
		}
	}

	// buttons
	DrawRectangleRec(start, BLUE);
	DrawRectangleRec(controls, BLUE);

	// UI Text
	DrawText("Start Game", start.x+10, start.y+8, 30, BLACK);
	DrawText("Controls", controls.x+35, controls.y+8, 27, BLACK);
}

GameStates menustate::next()
{
	// if click
	if (IsMouseButtonPressed(0)) {
		// if within start bounds
		if (CheckCollisionPointRec(GetMousePosition(), start)) {
			return GameStates::LEVEL1;
		}
		// if within detail bounds
		if (CheckCollisionPointRec(GetMousePosition(), controls)) {
			return GameStates::DETAIL;
		}
	}

	// else
	// return same state
	return GameStates::MENU;
}
