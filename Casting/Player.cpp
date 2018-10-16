#include "Player.h"



Player::Player()
{
	type = "Player";
	speed = 10.0f; // should be fastest
	sprite = LoadTexture("assets/elfy.png");
}


Player::~Player()
{
	UnloadTexture(sprite);
}

void Player::draw() {
	DrawTextureV(sprite, position, WHITE);
}

void Player::resize(Vector2 scale) // should this be in the constructor?
{
	Image sprite_i = LoadImage("assets/elfy.png");
	ImageResize(&sprite_i, scale.x, scale.y);
	UnloadTexture(sprite);
	sprite = LoadTextureFromImage(sprite_i);
	UnloadImage(sprite_i);
}

void Player::update(float deltaTime) {
	// keyboard input
	if (IsKeyDown(KEY_W)) {
		position.y -= speed;
	}
	if (IsKeyDown(KEY_S)) {
		position.y += speed;
	}
	if (IsKeyDown(KEY_A)) {
		position.x -= speed;
	}
	if (IsKeyDown(KEY_D)) {
		position.x += speed;
	}
}

