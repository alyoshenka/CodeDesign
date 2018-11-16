#include "Octopus.h"

Octopus::Octopus()
{
	sprite = LoadTexture("octopusGuy.png");
	frameCount = 14;
	sourceRec = { 0, 0, (float)sprite.width, (float)sprite.height / frameCount};	
	currentFrame = 0;
	animationSpeed = 500;
	currentFrameItr = 0;
	pos = { 0, 0 };
	speed = 0.03;
	waterGravity = speed / 10;
}


Octopus::~Octopus()
{
	UnloadTexture(sprite);
}

void Octopus::draw()
{
	// DrawTexture(sprite, 0, 0, WHITE);
	DrawTextureRec(sprite, sourceRec, pos, WHITE);
}

void Octopus::update()
{
	// animation
	currentFrameItr++;
	if (currentFrameItr > animationSpeed) {
		currentFrame++;
		if (currentFrame >= frameCount) {
			currentFrame = 0;
		}
		sourceRec.y = sprite.height / frameCount * currentFrame;
		currentFrameItr = 0;
	}

	// movement
	if (IsKeyDown(KEY_A)) {
		pos.x -= speed;
	}
	if (IsKeyDown(KEY_D)) {
		pos.x += speed;
	}
	if (IsKeyDown(KEY_W)) {
		pos.y -= speed;
	}
	if (IsKeyDown(KEY_S)) {
		pos.y += speed;
	}

	// bounds checking
	if (pos.x < 0) {
		pos.x = 0;
	}
	if (pos.x + sprite.width > GetScreenWidth()) {
		pos.x = GetScreenWidth() - sprite.width;
	}
	if (pos.y < 0) {
		pos.y = 0;
	}
	if (pos.y + sprite.height / frameCount > GetScreenHeight()) {
		pos.y = GetScreenHeight() - sprite.height / frameCount;
	}

	// slight gravity
	pos.y += waterGravity;

}
