#pragma once
#include "raylib.h"
// #include  "Octopus.h"
#include <math.h>

class Enemy
{
	
	Texture2D fish;
	float currentSize;
	float speed;
	Rectangle startSize;

	// Octupus player;

public:

	Rectangle * fishies;
	// alotted number of fish
	int fishPool;
	// number of fish on screen
	int idx;

	Enemy();
	~Enemy();

	// add new fish to arr
	void add();
	void update();
	void draw();
	void pop(int i);
};

