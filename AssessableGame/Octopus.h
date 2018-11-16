#pragma once
#include "raylib.h"
class Octopus
{
	Texture2D sprite;
	int currentFrameItr;
	int currentFrame;
	int animationSpeed;
	Rectangle sourceRec;
	int spriteHeight;
	int frameCount;

	Vector2 pos;
	float speed;
	float waterGravity;

public:
	Octopus();
	~Octopus();

	void draw();
	void update();
};

