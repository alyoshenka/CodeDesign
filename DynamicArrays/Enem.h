#pragma once
#include "raylib.h"
class Enem
{
public:

	Texture2D mySprite;
	Vector2 speed;
	Vector2 position;
	// Vector2 destination;
	bool isActive;
	// Vector2 velocity;


	Enem();
	~Enem();

	void update();
	void draw();
};

