#include "WizBarNecromancer.h"


WizBarNecromancer::WizBarNecromancer() : WizBarEnemy()
{
	mySprite = LoadTexture("assets/necro1.png");
	speed = 40.0f;
}

WizBarNecromancer::WizBarNecromancer(std::string & fileName) : WizBarEnemy(fileName)
{
}

WizBarNecromancer::~WizBarNecromancer()
{
}

bool WizBarNecromancer::moveTo(const Vector2 & dest) 
{	// if very close
	if (dest.x - position.x >= -1 && dest.x - position.x <= 1
		&& position.y - dest.y >= -1 && dest.y - position.y <= position.y) {
		// ^ pos and dest were flipped

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
