#pragma once
#include "raylib.h"
class Enemy
{
	Rectangle * fishies;
	// alotted number of fish
	int fishPool;
	// number of fish on screen
	int idx;
	Texture2D fish;
	float currentSize;
	float speed;

public:
	Enemy();
	~Enemy();

	// add new fish to arr
	void add();
	void update();
	void draw();
};

