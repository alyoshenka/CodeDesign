#pragma once

#include <string>
#include "raylib.h"

class item
{
public:

	std::string type;
	// 0 - 100;
	int quality;
	int range; // 0 = melee
	Texture2D texture;
	int damage;

	item();
	~item();

	void draw(int x, int y);
};

