#pragma once
#include "Fish.h"

class FishManager
{
	// main fish array
	Fish * fishArr;
	// how much arr can hold
	size_t arrCapacity;
	// how much of arr is "used"
	size_t arrSize;
	// fish factory array
	Fish * fishPrototypes;
	// number of prototype fish
	size_t prototypeCount;
	// used to indicate types and sizes of fish;
	int level;

public:


	FishManager();
	~FishManager();

	void addFish();

	void pop(size_t i);

	void update();
	void draw();

	// 0 = none, 1 = enemy smaller, 2 = enemy bigger
	int checkForCollision(Rectangle player);

	// useful, yes, but not what i need right now
	// iterates through array and performs all needed functions
	void go();
};

