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

	// get file input
	std::ifstream file;
	// open
	file.open("fishyGame.txt", std::ios::in);
	// verify
	if (file.fail()) {
		std::cerr << "File not found" << std::endl;
	}
	
	// iterate through
	std::string cur;
	while (std::getline(file, cur)) {
		fileText += cur;
		fileText += "\n";
	}

	// reset
	file.clear();
	file.close();
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
	startButton.draw();
	detailButton.draw();

	// UI Text
	DrawText("Start Game", startButton.bounds.x+10, startButton.bounds.y+8, 30, BLACK);
	DrawText("Controls", detailButton.bounds.x+30, detailButton.bounds.y+8, 30, BLACK);

	DrawText(fileText.c_str(), 10, 450, 10, WHITE);
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
