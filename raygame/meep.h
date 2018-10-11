#pragma once
#include "raylib.h"
#include <iostream>
#include "item.h"

struct TextureWithPosition {

	Texture2D texture;
	Vector2 position;

};

class meep
{
public:

	bool enabled;
	Texture2D texture; // stack, automatic	
	Vector2 position;

	Texture2D * dTexture = new Texture2D; // heap, needs help
	bool * playerControlled = new bool;
	
	item mainWeapon;
	bool holdingWeapon;

	meep();
	meep(bool _enabled);
	~meep();

	void refresh();
	void giveWeapon(item weapon);
};

