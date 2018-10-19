#include "Ninja.h"

Ninja::Ninja()
{
	sprite = LoadTexture("puppy.png");
	position = { 200.0f, 100.0f };
	speed = 50.0f;
}


Ninja::~Ninja()
{
	UnloadTexture(sprite);
}

void Ninja::draw()
{
	DrawTextureV(sprite, position, WHITE);
}

void Ninja::update(float dt)
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
