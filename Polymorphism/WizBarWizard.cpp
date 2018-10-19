#include "WizBarWizard.h"



WizBarWizard::WizBarWizard()
{
	mySprite = LoadTexture("assets/wiz1.png");
	blastRadius = 10.0f;
	blastTime = 1.0f;
	speed = 0.0f;
}


WizBarWizard::~WizBarWizard()
{
}

bool WizBarWizard::moveTo(const Vector2 &dest) {
	position = dest;
	return true;
}

bool WizBarWizard::attack(Rectangle enemy) {

	// reset
	if (elapsedTime >= blastTime) { // possibly wrong order
		elapsedTime = 0.0f;
	}

	// add time
	elapsedTime += GetFrameTime();
	// check collision and time
	if (elapsedTime < blastTime &&
		CheckCollisionCircleRec({position.x - 8, position.y - 16},
			blastRadius, enemy)) {

		DrawCircle(position.x, position.y, blastRadius, BLUE);	
		return true;
	}	

	// else
	return false;
}

