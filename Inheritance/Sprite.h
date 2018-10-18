#pragma once
#include "raylib.h"
#include <iostream>
class Sprite : public Vector2
{
public:
	// ALL the sprites
	Texture2D * spriteCells = NULL;
	int frameCount;
	// standing animation
	Texture2D * standingCells = NULL;
	int standingCount;
	// walking animation
	Texture2D * walkingCells = NULL;
	int walkingCount;
	// climbing animation
	Texture2D * climbingCells = NULL;
	int climbingCount;

	// which is in use at any given time
	Texture2D *activeCells = NULL;
	int activeCount;

	// speed at which frames iterate
	float frameRate = 1.0f; 
	float totalTime = 0.0f;

	// current frame being drawn
	int currentFrame = 0;

	Vector2 velocity; // + & - in x & y

	// various movement positions
	// is standing still
	bool standing;
	// is walking
	bool walking;
	// is climbing
	bool climbing;

	// frame speed things
	// float timeBetweenFrames;


	void draw();
	void update(float deltaTime);
	// add new movement position
	void add(); // define later

	// 0 = default
	// 1 = standing
	// 2 = walking
	// 3 = climbing
	Sprite(const std::string *filename, const  int cellCount, const float _frameRate);
	Sprite();
	~Sprite();
};

