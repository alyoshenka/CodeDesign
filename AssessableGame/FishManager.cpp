#include "FishManager.h"

FishManager::FishManager()
{
	arrCapacity = 40; 
	fishArr = new Fish[arrCapacity];
	free = new bool[arrCapacity];
	
	f1 = LoadTexture("assets/fishP.png");
	f2 = LoadTexture("assets/fishB.png");
	f3 = LoadTexture("assets/fishY.png");
	f4 = LoadTexture("assets/fishG.png");

	prototypeCount = 4;
	fishPrototypes = new Fish[prototypeCount];

	fishPrototypes[0] = Fish(); // default fish
	fishPrototypes[1] = Fish(250.0f, 1.0f);
	fishPrototypes[2] = Fish(250.0f, 1.5f);
	fishPrototypes[3] = Fish(250.0f, 2.0f);

	fishPrototypes[0].sprite = f1;
	fishPrototypes[1].sprite = f2;
	fishPrototypes[2].sprite = f3;
	fishPrototypes[3].sprite = f4;

	for (size_t i = 0; i < arrCapacity; i++) {
		free[i] = false;
		fishArr[i] = fishPrototypes[0];
		fishArr[i].randomizeValues();
	}
}

FishManager::~FishManager()
{
	// manually unload prototype textures
	UnloadTexture(f1);
	UnloadTexture(f2);
	UnloadTexture(f3);
	UnloadTexture(f4);

	delete[] fishArr;
	delete[] fishPrototypes;
	delete[] free;
	// assuming this calls Fish deconstructor and taks care of unloading textures

	// after changing to statically allocated fishPrototypes, fish 
	// deconstructor will be called and textures will unload (in theory)
}

void FishManager::addFish(size_t level)
{
	// if space
	for (int i = 0; i < arrCapacity; i++) {
		if (free[i]) {
			// make one size smaller fish slightly more probable
			int f = GetRandomValue(1, level + prototypeCount * 2);
			if (f > level + prototypeCount - 2) {
				// one size smaller
				fishArr[i] = fishPrototypes[level - 1];
			}
			else if(f > level - 1){
				// one size larger
				fishArr[i] = fishPrototypes[level];
			}
			else {
				// random
				fishArr[i] = fishPrototypes[f];
				// fishArr[i] = fishPrototypes[level];
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
				int temp = fishArr[i].boundingBox().height * (fishArr[i].boundingBox().height / player.height);
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

