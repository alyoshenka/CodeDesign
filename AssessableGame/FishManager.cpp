#include "FishManager.h"

FishManager::FishManager()
{
	arrCapacity = 40; 
	fishArr = new Fish[arrCapacity];
	free = new bool[arrCapacity];
	
	prototypeCount = 4;
	fishPrototypes = new Fish[prototypeCount];
	fishPrototypes[0] = *(new Fish()); // default fish
	fishPrototypes[1] = *(new Fish("assets/fishB.png", 250.0f, 1.0f));
	fishPrototypes[2] = *(new Fish("assets/fishY.png", 250.0f, 1.5f));
	fishPrototypes[3] = *(new Fish("assets/fishG.png", 250.0f, 2.0f));

	for (int i = 0; i < arrCapacity; i++) {
		free[i] = false;
		fishArr[i] = fishPrototypes[0];
		fishArr[i].randomizeValues();
	}
}

FishManager::~FishManager()
{
	// manually unload prototype textures?
	delete[] fishArr;
	delete[] fishPrototypes;
	delete[] free;
	// assuming this calls Fish deconstructor and taks care of unloading textures
}

void FishManager::addFish(size_t level)
{
	// if space
	for (int i = 0; i < arrCapacity; i++) {
		if (free[i]) {
			// make smaller fish slightly more probable
			int f = GetRandomValue(1, level + prototypeCount);
			if (f > level) {
				fishArr[i] = fishPrototypes[0];
			}
			else {
				fishArr[i] = fishPrototypes[f];
			}
			free[i] = false;
		}
	}
	// else nothing
}

void FishManager::pop(size_t i)
{	
	free[i] = true;
}

void FishManager::update()
{
	
	for (size_t i = 0; i < arrCapacity; i++) {

		if (! free[i]) {
			// update individual fish positions
			fishArr[i].update();
		}
		
		// make better implementation
		// bounds checking
		if (! free[i] && fishArr[i].position.x < -150) {
			pop(i);
		}
	}
}

void FishManager::draw()
{
	for (size_t i = 0; i <= arrCapacity; i++) {
		if (! free[i]) {
			fishArr[i].draw();
		}		
	}
}

float FishManager::checkForCollision(Rectangle player)
{
	for (size_t i = 0; i < arrCapacity; i++) {

		if (! free[i] && 
			CheckCollisionRecs(fishArr[i].boundingBox(), player)) {

			if (player.height >= fishArr[i].boundingBox().height) {

				// store val
				int temp = fishArr[i].boundingBox().height;
				// get rid of this specific fish
				pop(i);
				// player bigger
				return temp;
			}
			else {
				// enemy bigger
				return 0.0f;
			}
		}
	}
	// no collision
	return -1.0f;
}

