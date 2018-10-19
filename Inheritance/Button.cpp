#include "Button.h"



Button::Button()
{
	activeCount = 2;
	activeCells = new Texture2D[activeCount];
	activeCells[0] = LoadTexture("assest/blue_button07.png");
	activeCells[1] = LoadTexture("assest/blue_button08.png");

	currentFrame = 0;
}


Button::~Button()
{
	// unload
	for (int i = 0; i < activeCount; i++) {
		UnloadTexture(activeCells[i]);
	}

	delete[] activeCells;
	// delete all?
}

void Button::update() {
	return;
}

void Button::draw() { // ???
	DrawTexture(activeCells[currentFrame], x, y, WHITE);
}

