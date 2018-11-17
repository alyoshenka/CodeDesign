#include "Enemy.h"



Enemy::Enemy()
{
	fish = LoadTexture("fishE.png");
	fishPool = 50;
	fishies = new Rectangle[fishPool];
	// populate with starting size
	startSize = { 0.0f, 0.0f, (float)fish.width, (float)fish.height };
	for (int i = 0; i < fishPool; i++) {
		fishies[i] = startSize;
	}
	idx = 0;
	currentSize = 1.0f;
	speed = 150.0f;
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
			startSize.width, startSize.height };
		idx++;
	}
}

void Enemy::update()
{
	// add more fish
	if (GetRandomValue(0, 30) == 0) {
		add();
	}

	// update positions
	for (int i = 0; i < idx; i++) {
		fishies[i].x -= speed * GetFrameTime();
		// fishies[i].y += (sin(10 * PI * GetFrameTime()));
		// cut off at edges
		if (fishies[i].x + fishies[i].width <= 0) {
			// opject pool
			// get rid of them
			fishies[i] = fishies[--idx];
			// idx--;
		}

		// check for collision with player

	}
	
}

void Enemy::draw()
{
	// draw all fish
	for (int i = 0; i < idx; i++) {
		DrawTexturePro(fish, startSize, startSize,
			{ fishies[i].x * -1, fishies[i].y * -1 }, 0, RED);
		// DrawTexture(fish, fishies[i].x, fishies[i].y, WHITE);
	}
}

void Enemy::pop(int i)
{
	fishies[i] = fishies[--idx];
}
