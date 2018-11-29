#include "FishManager.h"


void FishManager::addFish(size_t level) // ADD LEVEL QUALIFIER HERE
{
	// if space
	if (arrSize < arrCapacity - 1) {
		// gets a random fish within level qualifications
		fishArr[arrSize++] = fishPrototypes[GetRandomValue(0, level - 1)];
	}
	// else nothing
}

FishManager::FishManager()
{
	arrCapacity = 20;
	arrSize = 0;
	fishArr = new Fish[arrCapacity];
	prototypeCount = 4;
	fishPrototypes = new Fish[prototypeCount];
	fishPrototypes[0] = *(new Fish()); // default fish
	fishPrototypes[1] = *(new Fish("assets/fishB.png", 250.0f, 1.0f));
	fishPrototypes[2] = *(new Fish("assets/fishY.png", 250.0f, 1.5f));
	fishPrototypes[3] = *(new Fish("assets/fishG.png", 250.0f, 2.0f));

	// populate arr with level 1 fish
	for (size_t i = 0; i < arrCapacity; i++) {
		fishArr[i] = fishPrototypes[0];
		// randomize values
		fishArr[i].randomizeValues();
	}
}


FishManager::~FishManager()
{
	delete[] fishArr;
	delete[] fishPrototypes;
	// assuming this calls Fish deconstructor and taks care of unloading textures
}

void FishManager::pop(size_t i)
{
	// deletes by swapping in end Fish and decrementing size
	// this implementation caused odd skips, does order really matter here?
	if (arrSize > 0) {
		fishArr[i] = fishArr[arrSize--];
	}
}

void FishManager::update()
{
	// stagger new fish
	if (GetRandomValue(0, 10) == 0) {
		arrSize++;
	}
	// bounds
	if (arrSize >= arrCapacity) {
		arrSize = arrCapacity - 1;
	}

	for (size_t i = 0; i <= arrSize; i++) {
		// update individual fish positions
		fishArr[i].update();

		// make better implementation
		// bounds checking
		if (fishArr[i].position.x < -50) {
			pop(i);
		}
	}
}

void FishManager::draw()
{
	for (size_t i = 0; i <= arrSize; i++) {
		fishArr[i].draw();
	}
}

int FishManager::checkForCollision(Rectangle player)
{
	for (size_t i = 0; i <= arrSize; i++) {

		if (CheckCollisionRecs(fishArr[i].boundingBox(), player)) {
			if (player.height >= fishArr[i].boundingBox().height) {

				// get rid of this specific fish
				pop(i);
				// player bigger
				return 1;
			}
			else {
				// enemy bigger
				return 2;
			}
		}
	}
	// no collision
	return 0;
}

