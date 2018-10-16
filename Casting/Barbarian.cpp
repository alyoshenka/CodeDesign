#include "Barbarian.h"



Barbarian::Barbarian()
{
	type = "Barbaran";
	sprite = LoadTexture("assets/barb.png");
	speed = 5.0f; // slower
}


Barbarian::~Barbarian()
{
	UnloadTexture(sprite);
}

void Barbarian::draw() {
	DrawTextureV(sprite, position, WHITE);
}

//void Barbarian::update(float deltaTime) {
//	// superclass??
//}

void Barbarian::resize(Vector2 scale) // should this be in the constructor?
{
	Image sprite_i = LoadImage("assets/barb.png");
	ImageResize(&sprite_i, scale.x, scale.y);
	UnloadTexture(sprite);
	sprite = LoadTextureFromImage(sprite_i);
	UnloadImage(sprite_i);
}
