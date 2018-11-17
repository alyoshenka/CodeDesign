#include "Octopus.h"

Octopus::Octopus()
{
	/*sprite = LoadTexture("octopusGuy.png");
	frameCount = 14;
	sourceRec = { 0, 0, (float)sprite.width, (float)sprite.height / frameCount};	
	currentFrame = 0;
	animationSpeed = 500;
	currentFrameItr = 0;*/
	spriteL = LoadTexture("fishL.png");
	spriteR = LoadTexture("fishR.png");
	spriteC = spriteR;
	sourceRec = {0.0f, 0.0f, (float)spriteR.width, (float)spriteR.height};
	destRec = { 0.0f, 0.0f, sourceRec.width / 2.0f, sourceRec.height / 2.0f };
	pos = { 0, 0 };
	speed = 200.0f;
	waterGravity = speed / 10;

	health = 10;

	currentSize = 1.0f;
	// trying to get 3x bigger
	goalSize = 3.0f;
	modifier = 0.02;
}


Octopus::~Octopus()
{
	UnloadTexture(spriteR);
	UnloadTexture(spriteL);
}

void Octopus::draw()
{
	// DrawTexture(sprite, 0, 0, WHITE);
	// DrawTextureRec(sprite, sourceRec, pos, WHITE);
	DrawTexturePro(spriteC, sourceRec, destRec, { pos.x * -1, pos.y * -1 }, 0, WHITE);
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
		spriteC = spriteL;
	}
	if (IsKeyDown(KEY_D)) {
		pos.x += speed * GetFrameTime();
		spriteC = spriteR;
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
	if (pos.x + spriteR.width > GetScreenWidth()) {
		pos.x = GetScreenWidth() - spriteR.width;
	}
	if (pos.y < 0) {
		pos.y = 0;
	}
	/*if (pos.y + sprite.height / frameCount > GetScreenHeight()) {
		pos.y = GetScreenHeight() - sprite.height / frameCount;
	}*/
	if (pos.y + spriteR.height > GetScreenHeight()) {
		pos.y = GetScreenHeight() - spriteR.height;
	}

	// slight gravity
	pos.y += waterGravity * GetFrameTime();
}

void Octopus::shrink()
{
	currentSize *= 1 - modifier;
	destRec.width *= 1 - modifier;
	destRec.height *= 1 - modifier;
	health -= modifier;
}

void Octopus::grow()
{
	// correct porportion?
	currentSize *= modifier;
	destRec.width *= modifier;
	destRec.height *= modifier;
	
}
