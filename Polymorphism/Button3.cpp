#include "Button3.h"

myButton::myButton()
{
	delayTime = 0.3f;
	elapsedTime = 0.0f;
	isClicked = false;
	upTexture = LoadTexture("assets/blue_button00.png");
	downTexture = LoadTexture("assets/blue_button13.png");

	bounds = { 0.0f, 0.0f, (float)upTexture.width, (float)upTexture.height };
}

myButton::myButton(const std::string up, const std::string down) : myButton()
{
	UnloadTexture(upTexture);
	UnloadTexture(downTexture);

	upTexture = LoadTexture(up.c_str());
	downTexture = LoadTexture(down.c_str());

	bounds = { 0.0f, 0.0f, (float)upTexture.width, (float)upTexture.height };
}


myButton::~myButton()
{
	UnloadTexture(upTexture);
	UnloadTexture(downTexture);
}

void myButton::update(Vector2 click)
{
	if (CheckCollisionPointRec(click, bounds) && IsMouseButtonPressed(0)) {
		isClicked = true;
	}

	// update
	elapsedTime += GetFrameTime();
	if (elapsedTime > delayTime) {
		isClicked = false;
		elapsedTime = 0.0f;
	}
}

void myButton::draw()
{
	if (isClicked) {
		DrawTexture(downTexture, bounds.x, bounds.y, WHITE);
	}
	else{
		DrawTexture(upTexture, bounds.x, bounds.y, WHITE);
	}
}
