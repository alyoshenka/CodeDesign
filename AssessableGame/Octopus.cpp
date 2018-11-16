#include "Octopus.h"

Octopus::Octopus()
{
	/*sprite = LoadTexture("octopusGuy.png");
	frameCount = 14;
	sourceRec = { 0, 0, (float)sprite.width, (float)sprite.height / frameCount};	
	currentFrame = 0;
	animationSpeed = 500;
	currentFrameItr = 0;*/
	sprite = LoadTexture("fishTile_101.png");
	sourceRec = {0.0f, 0.0f, (float)sprite.width, (float)sprite.height};
	destRec = sourceRec;
	pos = { 0, 0 };
	speed = 150.0f;
	waterGravity = speed / 10;

	health = 10;

	currentSize = 1.0f;
	// trying to get 3x bigger
	goalSize = 3.0f;
	modifier = 0.02;
}


Octopus::~Octopus()
{
	UnloadTexture(sprite);
}

void Octopus::draw()
{
	// DrawTexture(sprite, 0, 0, WHITE);
	// DrawTextureRec(sprite, sourceRec, pos, WHITE);
	DrawTexturePro(sprite, sourceRec, destRec, { pos.x * -1, pos.y * -1 }, 0, WHITE);
}

void Octopus::update()
{
	// test
	if (IsKeyPressed(KEY_SPACE)) {
		health = 0;
	}

	// animation
	/*currentFrameItr++;
	if (currentFrameItr > animationSpeed) {
		currentFrame++;
		if (currentFrame >= frameCount) {
			currentFrame = 0;
		}
		sourceRec.y = sprite.height / frameCount * currentFrame;
		currentFrameItr = 0;
	}*/

	// movement
	if (IsKeyDown(KEY_A)) {
		pos.x -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_D)) {
		pos.x += speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_W)) {
		pos.y -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_S)) {
		pos.y += speed * GetFrameTime();
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
	/*if (pos.y + sprite.height / frameCount > GetScreenHeight()) {
		pos.y = GetScreenHeight() - sprite.height / frameCount;
	}*/
	if (pos.y + sprite.height > GetScreenHeight()) {
		pos.y = GetScreenHeight() - sprite.height;
	}

	// slight gravity
	pos.y += waterGravity * GetFrameTime();
}

void Octopus::grow()
{
	// correct porportion?
	currentSize *= modifier;
	destRec.width *= modifier;
	destRec.height *= modifier;
}
