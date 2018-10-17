#pragma once
#include "raylib.h"
#include <iostream>
class Sprite : public Vector2
{
public:
	// ALL the sprites
	Texture2D * spriteCells = NULL;
	// speed at which frames iterate
	float frameRate = 5.0; 
	// not quite sure
	int framesCounter = 0;
	// number of frames
	int frameCount = 0;
	int direction = 1; // possibly covered by velocity?
	// current frame being drawn
	int currentFrame = 0;
	// lowest idx of frame within movement state
	int minFrame = 0;
	// highest idx of frame within movement state
	int maxFrame = 0;

	Vector2 velocity; // + & - in x & y
	// various movement positions
	bool standing;
	bool walking;
	bool climbing;


	void draw();
	void update();

	Sprite(const std::string *filename, const  int cellCount, const float _frameRate);
	Sprite();
	~Sprite();
};

