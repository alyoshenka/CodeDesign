#pragma once
#include "raylib.h"
class Ninja
{
public:

	Texture2D sprite;
	Vector2 position;
	float speed;

	Ninja();
	~Ninja();

	void draw();
	void update(float dt);
};

