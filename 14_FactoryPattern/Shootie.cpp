#include "Shootie.h"



Shootie::Shootie()
{
	position = { 0, 0 };
	speed = 3.0f;
	bullet = { 0, 0, 5, 5 };
	idx = 0;
	maxIdx = 0;
}


Shootie::~Shootie()
{
}

void Shootie::shoot(Vector2 m)
{
	// m for mouse

	// new bullet
	projectiles[maxIdx] = { 0, 0, 5, 5 };
	// funky maths
	float x = m.x / (m.x + m.y);
	float y = m.y / (m.x + m.y);
	Vector2 velocity = {x * speed, y * speed};
	dest[maxIdx] = velocity;

	// use bigger chunk of array
	maxIdx++;
}

void Shootie::update()
{
	// update bullet positions
	for (int i = 0; i < maxIdx; i++) {
		projectiles[i].x += dest[i].x;
		projectiles[i].y += dest[i].y;

		// check for out of bounds
		if (projectiles[i].x > 800 || projectiles[i].x < -20 ||
			projectiles[i].y > 450 || projectiles[i].y < -20) {
			// get rid of bullet
			projectiles[i] = projectiles[maxIdx - 1];
			// get rid of it
			maxIdx--;
		}
	}

	// check for new
	if (IsKeyPressed(KEY_SPACE) && maxIdx < 99) {
		shoot(GetMousePosition());
	}
}

void Shootie::draw()
{
	for (int i = 0; i < maxIdx; i++) {
		DrawRectangleRec(projectiles[i], GRAY);
	}
}

void Shootie::pop(int idx)
{
	projectiles[idx] = projectiles[maxIdx];
	maxIdx--;
}
