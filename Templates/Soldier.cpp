#include "Soldier.h"



Soldier::Soldier()
{
	sprite = LoadTexture("dude.png");
	position = { 100.0f, 100.0f };
	speed = 50.0f;
}


Soldier::~Soldier()
{
	UnloadTexture(sprite);
}

void Soldier::draw()
{
	DrawTextureV(sprite, position, WHITE);
}

void Soldier::update(float dt)
{
	if (IsKeyDown(KEY_W)) {
		position.y -= speed * dt;
	}
	if (IsKeyDown(KEY_S)) {
		position.y += speed * dt;
	}
	if (IsKeyDown(KEY_A)) {
		position.x -= speed * dt;
	}
	if (IsKeyDown(KEY_D)) {
		position.x += speed * dt;
	}
}
