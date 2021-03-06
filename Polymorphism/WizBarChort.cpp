#include "WizBarChort.h"

WizBarChort::WizBarChort() :WizBarEnemy()
{
	speed = 20.0f;
}


WizBarChort::~WizBarChort()
{
}

bool WizBarChort::moveTo(const Vector2 & dest)
{
	// if very close
	if (dest.x - position.x >= -1 && dest.x - position.x <= 1
		&& position.y - dest.y >= -1 && dest.y - position.y <= position.y) {

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

	return false;
}


// test!!
//void WizBarChort::draw()
//{
//	// if alive
//	if (isActive) {
//		// offset for size
//		DrawTexture(mySprite, position.x - 4, position.y - 8, WHITE);
//	}
//}
