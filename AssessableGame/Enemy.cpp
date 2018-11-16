#include "Enemy.h"



Enemy::Enemy()
{
	fish = LoadTexture("fish.png");
	fishPool = 50;
	fishies = new Rectangle[fishPool];
	// populate with starting size
	Rectangle startSize = { 0, 0, fish.width, fish.height };
	for (int i = 0; i < fishPool; i++) {
		fishies[i] = startSize;
	}
	idx = 0;
	currentSize = 1.0f;
	speed = 100.0f;
}


Enemy::~Enemy()
{
	// does order matter here?
	UnloadTexture(fish);
	delete[] fishies;
}

void Enemy::add()
{
	if (idx < fishPool) {
		fishies[idx] = { (float)GetScreenWidth(), (float)GetRandomValue(0, GetScreenHeight() - fish.height),
			(float)fish.width, (float)fish.height };
		idx++;
	}
}

void Enemy::update()
{
	// add more fish
	if (GetRandomValue(0, 100) == 0) {
		add();
	}

	// update positions
	for (int i = 0; i < idx; i++) {
		fishies[i].x -= speed * GetFrameTime();
		// cut off at edges
		if (fishies[i].x + fishies[i].width <= 0) {
			// opject pool
			// get rid of them
			fishies[i] = fishies[--idx];
			// idx--;
		}
	}
	
}

void Enemy::draw()
{
	// draw all fish
	for (int i = 0; i < idx; i++) {
		/*DrawTexturePro(fish, fishies[i], 
			{ 0, 0, fishies[i].width * currentSize, fishies[i].height * currentSize }, 
			{ fishies[i].x * 1, fishies[i].y * 1 }, 0, RED);*/
		DrawTexture(fish, fishies[i].x, fishies[i].y, WHITE);
	}
}
