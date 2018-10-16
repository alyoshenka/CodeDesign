#include "Wizard.h"



Wizard::Wizard()
{
	type = "Wizard";
	sprite = LoadTexture("assets/wizzy.png");
	speed = 10.0f; // should be sort of fast
	// resize here? yes
}


Wizard::~Wizard()
{
	UnloadTexture(sprite); // here or in superclass?
}

void Wizard::draw() {
	DrawTextureV(sprite, position, WHITE);
}

//void Wizard::update(float deltaTime)
//{
//	// no update, stationary
//}

void Wizard::resize(Vector2 scale) // should this be in the constructor?
{
	Image sprite_i = LoadImage("assets/wizzy.png");
	ImageResize(&sprite_i, scale.x, scale.y);
	UnloadTexture(sprite);
	sprite = LoadTextureFromImage(sprite_i);
	UnloadImage(sprite_i);
}
