#include "Button2.h"

Button2::Button2()
{
	delayTime = 0.2f;
	elapsedTime = 0.0f;
	isClicked = false;
	upTexture = LoadTexture("assets/blue_button00.png");
	downTexture = LoadTexture("assets/blue_button13.png");
	resetting = false;

	bounds = { 0.0f, 0.0f, (float)upTexture.width, (float)upTexture.height };
}

Button2::Button2(const std::string up, const std::string down) : Button2()
{
	UnloadTexture(upTexture);
	UnloadTexture(downTexture);

	upTexture = LoadTexture(up.c_str());
	downTexture = LoadTexture(down.c_str());

	bounds = { 0.0f, 0.0f, (float)upTexture.width, (float)upTexture.height };
}


Button2::~Button2()
{
	UnloadTexture(upTexture);
	UnloadTexture(downTexture);
}

void Button2::update(Vector2 click)
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

void Button2::draw()
{
	if (isClicked) {
		DrawTexture(downTexture, bounds.x, bounds.y, WHITE);
	}
	else {
		DrawTexture(upTexture, bounds.x, bounds.y, WHITE);
	}
}
