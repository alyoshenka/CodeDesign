#pragma once
#include "raylib.h"

// reset timer on getting hit

class Octopus
{

	// left 
	Texture2D spriteL;
	// right
	Texture2D spriteR;
	// current
	Texture2D spriteC;
	int currentFrameItr;
	int currentFrame;
	int animationSpeed;
	Rectangle sourceRec;
	int spriteHeight;
	int frameCount;
	
	float speed;
	// speed downwards due to gravity
	float waterGravity;	

	// size to win
	// growth each time
	float modifier;

public:

	float currentSize;
	float goalSize;
	// float modifier;

	Rectangle destRec;
	Vector2 position;

	int health;

	Octopus();
	~Octopus();

	void draw();
	void update();
	// get bigger or smaller
	void grow();
	void shrink();

	// return bounding box (to test for collision)
	Rectangle boundingBox();
};

