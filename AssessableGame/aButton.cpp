#include "aButton.h"

aButton::aButton()
{
	delayTime = 0.2f;
	elapsedTime = 0.0f;
	isClicked = false;
	upTexture = LoadTexture("blue_button04.png");
	downTexture = LoadTexture("blue_button05.png");
	resetting = false;

	bounds = { 0.0f, 0.0f, (float)upTexture.width, (float)upTexture.height };
}

aButton::aButton(const std::string up, const std::string down) : aButton()
{
	UnloadTexture(upTexture);
	UnloadTexture(downTexture);

	upTexture = LoadTexture(up.c_str());
	downTexture = LoadTexture(down.c_str());

	bounds = { 0.0f, 0.0f, (float)upTexture.width, (float)upTexture.height };
}


aButton::~aButton()
{
	UnloadTexture(upTexture);
	UnloadTexture(downTexture);
}

void aButton::update(Vector2 click)
{
	if (CheckCollisionPointRec(click, bounds) && IsMouseButtonPressed(0)) {
		isClicked = true;
		elapsedTime = 0.0f;
		resetting = true;
	}
	else {
		resetting = false;
	}

	// update
	elapsedTime += GetFrameTime();

	// wait to change animation
	if (elapsedTime >= delayTime) {
		isClicked = false;
		elapsedTime = 0.0f;
	}
}

void aButton::draw()
{
	if (isClicked) {
		DrawTexture(downTexture, bounds.x, bounds.y, WHITE);
	}
	else {
		DrawTexture(upTexture, bounds.x, bounds.y, WHITE);
	}
}

