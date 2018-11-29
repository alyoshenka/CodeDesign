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

public:


	FishManager();
	~FishManager();

	void addFish(size_t level);

	void pop(size_t i);

	void update();
	void draw();

	// 0 = none, 1 = enemy smaller, 2 = enemy bigger
	int checkForCollision(Rectangle player);
};

