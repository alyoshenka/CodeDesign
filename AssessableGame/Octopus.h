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

	Rectangle sourceRec;
	
	float speed;
	// speed downwards due to gravity
	float waterGravity;	

	// size to win
	// growth each time
	float modifier;

public:

	float size;

	Vector2 position;

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

