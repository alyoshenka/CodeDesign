#pragma once
#include "Fish.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

class FishManager
{
	// main fish array
	Fish * fishArr;
	// how much arr can hold
	size_t arrCapacity;
	// if space is "free"
	bool * free;
	// number of prototype fish
	size_t prototypeCount;

	Texture2D f1;
	Texture2D f2;
	Texture2D f3;
	Texture2D f4;

public:

	// fish factory array
	Fish * fishPrototypes;

	FishManager();
	~FishManager();

	// add a fish within level range
	void addFish(size_t level);

	// remove from index
	void pop(size_t i);

	void update();
	void draw();

	// -1 = none, 0 = fish smaller, other = modifier
	float checkForCollision(Rectangle player);
};

