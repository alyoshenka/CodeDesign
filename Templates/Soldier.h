#pragma once
#include "raylib.h"
class Soldier
{
public:

	Texture2D sprite;
	Vector2 position;
	float speed;

	Soldier();
	~Soldier();

	void draw();
	void update(float dt);
};
