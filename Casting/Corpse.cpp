#include "Corpse.h"



Corpse::Corpse()
{
	type = "Corpse";
	sprite = LoadTexture("assets/zomb.png");
	// speed already 0
}

// not sure how to reduce redundancy here
Corpse::Corpse(Wizard a) {
	// doesn't neeed speed and health
	name = a.name;
	type = "Dead " + a.type;
	gold = a.gold;
	position = a.position;
	size = a.size;
	sprite = a.sprite; // where to unload now?
	// should I delete a????
}

Corpse::Corpse(Barbarian a) {
	// doesn't neeed speed and health
	name = a.name;
	type = "Dead " + a.type;
	gold = a.gold;
	position = a.position;
	size = a.size;
	sprite = a.sprite; // where to unload now?
					   // should I delete a????
}


Corpse::~Corpse()
{
	// unload when object is deleted?????
	// UnloadTexture(sprite);
}

void Corpse::draw() {
	DrawTextureV(sprite, position, WHITE);
}

void Corpse::resize(Vector2 scale) // should this be in the constructor?
{
	Image sprite_i = LoadImage("assets/zomb.png");
	ImageResize(&sprite_i, scale.x, scale.y);
	UnloadTexture(sprite);
	sprite = LoadTextureFromImage(sprite_i);
	UnloadImage(sprite_i);
}
