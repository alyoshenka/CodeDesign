#pragma once
#include "raylib.h"
#include <math.h>

class Octopus
{

	// left 
	Texture2D spriteL;
	// right
	Texture2D spriteR;
	// current
	Texture2D spriteC;
	
	float speed;
	// speed downwards due to gravity
	float waterGravity;	

	// size to win
	// growth each time
	float modifier;

public:

	float size;	
	Rectangle sourceRec;
	Vector2 position;

	Octopus();
	~Octopus();

	void draw();
	void update();
	// get bigger by modifier value
	void grow(float mod);
	// grow smaller by set value
	void shrink();

	// return bounding box (to test for collision)
	Rectangle boundingBox();
};

