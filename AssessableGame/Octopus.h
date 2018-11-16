#pragma once
#include "raylib.h"
class Octopus
{
	// left and right directional textures?

	Texture2D sprite;
	int currentFrameItr;
	int currentFrame;
	int animationSpeed;
	Rectangle sourceRec;
	Rectangle destRec;
	Vector2 pos;

	int spriteHeight;
	int frameCount;
	
	float speed;
	// speed downwards due to gravity
	float waterGravity;	

	// size to win
	float goalSize;
	// current size
	float currentSize;
	// growth each time
	float modifier;

public:

	int health;

	Octopus();
	~Octopus();

	void draw();
	void update();
	void grow();
};

