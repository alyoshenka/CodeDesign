#include "detailstate.h"

detailstate::detailstate()
{
	// get file input
	std::ifstream file;
	// open
	file.open("assets/fishyGame.txt", std::ios::in);
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


detailstate::~detailstate()
{
}

void detailstate::draw()
{
	ClearBackground(LIGHTGRAY);

	DrawText(fileText.c_str(), 10, 10, 15, DARKBLUE);

	DrawText("[ ENTER ] to return", 100, 300, 30, BLACK);
}

GameStates detailstate::next()
{
	if (IsKeyPressed(KEY_ENTER)) {
		return GameStates::MENU;
	}

	return GameStates::DETAIL;
}
