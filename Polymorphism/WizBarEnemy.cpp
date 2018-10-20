#include "WizBarEnemy.h"


WizBarEnemy::WizBarEnemy(const std::string & fileName)
{
	mySprite = LoadTexture(fileName.c_str());
}

WizBarEnemy::WizBarEnemy()
{
	mySprite = LoadTexture("assets/chort1.png");
}


WizBarEnemy::~WizBarEnemy(){
	UnloadTexture(mySprite);
}

bool WizBarEnemy::moveTo(const Vector2 & dest)
{
	// do nothing, override in subclass
	return false;
}

void WizBarEnemy::draw()
{
	// if alive
	if (isActive) {
		// offset for size
		DrawTexture(mySprite, position.x - 4, position.y - 8, WHITE);
	}	
}
