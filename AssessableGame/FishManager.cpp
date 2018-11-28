#include "FishManager.h"


void FishManager::addFish() // ADD LEVEL QUALIFIER HERE
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
	arrCapacity = 50;
	arrSize = 1;
	fishArr = new Fish[arrCapacity];
	level = 1;
	prototypeCount = 2;
	fishPrototypes = new Fish[prototypeCount];
	fishPrototypes[0] = *(new Fish()); // default fish
	fishPrototypes[1] = *(new Fish("fishE.png", 250.0f, 1.0f));

	// populate arr with level 1 fish
	for (size_t i = 0; i < arrCapacity; i++) {
		fishArr[i] = fishPrototypes[0];
		// randomize pos
		fishArr[i].randomizePosition();
	}
}


FishManager::~FishManager()
{
	delete[] fishArr;
	delete[] fishPrototypes;
	// assuming this calls Fish deconstructor and taks care f unloading textures
}

void FishManager::pop(size_t i)
{
	// deletes by swapping in end Fish and decrementing size
	// fishArr[i] = fishArr[arrSize--];

	fishArr[i] = fishArr[arrSize];
	arrSize--;
}

void FishManager::update()
{
	// stagger new fish
	if (GetRandomValue(0, 20) == 0) {
		arrSize++;
	}
	// bounds
	if (arrSize >= arrCapacity) {
		arrSize = arrCapacity - 1;
	}

	for (size_t i = 0; i <= arrSize; i++) {
		fishArr[i].update();
		
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
		// enemy bounding box
		Rectangle temp = {fishArr[i].position.x, fishArr[i].position.y, 
			fishArr[i].sprite.width * fishArr[i].size, 
			fishArr[i].sprite.height * fishArr[i].size};

		if (CheckCollisionRecs(temp, player)) {
			if (player.height > temp.height) {
				pop(i);
				// player bigger
				return 2;
			}
			else {
				// enemy bigger
				return 1;
			}
		}
	}
	// no collision
	return 0;
}

void FishManager::go()
{
	for (size_t i = 0; i <= arrSize; i++) {
		fishArr[i].update();
		// if Fish is bigger than enemy, pop()
		fishArr[i].draw();
	}
}
