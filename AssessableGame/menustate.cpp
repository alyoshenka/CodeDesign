#include "menustate.h"

menustate::menustate()
{
	// button size
	int size = startButton.upTexture.width;;

	// center buttons
	// aButton = aButton();
	// startButton = aButton("green_button04.png", "green_button05.png"); // test
	startButton.bounds.x = GetScreenWidth() / 2 - size / 2.0f;
	startButton.bounds.y = GetScreenHeight() / 2.0f - size / 2,
	detailButton = aButton("green_button04.png", "green_button05.png");
	detailButton.bounds.x = startButton.bounds.x;
	detailButton.bounds.y = startButton.bounds.y + size / 2.0f;	
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
	ClearBackground(DARKPURPLE);

	// buttons
	startButton.draw();
	detailButton.draw();

	// UI Text
	DrawText("Start Game", startButton.bounds.x+10, startButton.bounds.y+8, 30, BLACK);
	DrawText("Controls", detailButton.bounds.x+30, detailButton.bounds.y+8, 30, BLACK);

}

GameStates menustate::next()
{
	// if click
	if (IsMouseButtonPressed(0)) {
		// if within start bounds
		if (CheckCollisionPointRec(GetMousePosition(), startButton.bounds)) {
			return GameStates::LEVEL1;
		}
		// if within detail bounds
		if (CheckCollisionPointRec(GetMousePosition(), detailButton.bounds)) {
			return GameStates::DETAIL;
		}
	}

	// else
	// return same state
	return GameStates::MENU;
}
