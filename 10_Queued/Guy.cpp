#include "Guy.h"



bool Guy::moveTo(const Vector2 & dest)
{
	// if very close
	if (dest.x - position.x >= -1 && dest.x - position.x <= 1
		&& dest.y - position.y >= -1 && dest.y - position.y <= 1) {

		// do nothing
		return true;
	}

	// else
	// move to dest at speed
	Vector2 direction = { 1,1 };

	// set negative directions
	if (dest.x < position.x) {
		direction.x = -1;
	}
	if (dest.y > position.y) {
		direction.y = -1;
	}

	// move
	position.x += speed * direction.x * GetFrameTime();
	position.y -= speed * direction.y * GetFrameTime();

	// truncate to get rid of shaky thing
	/*(int)position.x;
	(int)position.y;*/

	return false;
}

Guy::Guy()
{
	mySprite = LoadTexture("elf1.png");
	speed = 200.0f;
	destination = { 0, 0 };
}

Guy::~Guy()
{
	UnloadTexture(mySprite);
}

void Guy::draw()
{
	// offset for size
	DrawTexture(mySprite, position.x - 8, position.y - 16, WHITE);
}

void Guy::update()
{
	// on mouse click
	if (IsMouseButtonPressed(0)) {
		// update destination
		destination = GetMousePosition();
	}

	moveTo(destination);
}
