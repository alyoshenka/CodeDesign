#include "item.h"

item::item()
{
	type = "defaultWeapon";
	quality = 10; // low, but still usable
	range = 2; // close combat
	texture = LoadTexture("assets/sword.png");
}

item::~item()
{
	UnloadTexture(texture);
}


void item::draw(int x, int y) {
	DrawTexture(texture, x, y, WHITE);
}