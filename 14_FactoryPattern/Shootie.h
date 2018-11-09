#pragma once
#include "raylib.h"
class Shootie
{
public:

	// position to shoot from
	Vector2 position;
	// speed of projectiles
	float speed;
	// bullet size
	Rectangle bullet;
	// idx to make new projectile
	int idx;
	// used if bullet count < 25
	int maxIdx;

	// projectiles
	Rectangle projectiles[100];
	// destinations
	Vector2 dest[100];
	

	Shootie();
	~Shootie();

	void shoot(Vector2 mousePos);
	void update();
	void draw();
	// pop bullet from array if it hits something
	void pop(int idx);
};

