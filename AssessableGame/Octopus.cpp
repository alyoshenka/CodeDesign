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
	position = { 0, 0 };
	speed = 200.0f;
	waterGravity = speed / 10;

	health = 10;

	currentSize = 0.5f;
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
	DrawTexturePro(spriteC, sourceRec, boundingBox(), { position.x * -1, position.y * -1 }, 0, WHITE);
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
		position.x -= speed * GetFrameTime();
		spriteC = spriteL;
	}
	if (IsKeyDown(KEY_D)) {
		position.x += speed * GetFrameTime();
		spriteC = spriteR;
	}
	if (IsKeyDown(KEY_W)) {
		position.y -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_S)) {
		position.y += speed * GetFrameTime();
	}

	// bounds checking
	if (position.x < 0) {
		position.x = 0;
	}
	if (position.x + spriteR.width > GetScreenWidth()) {
		position.x = GetScreenWidth() - spriteR.width;
	}
	if (position.y < 0) {
		position.y = 0;
	}
	/*if (pos.y + sprite.height / frameCount > GetScreenHeight()) {
		pos.y = GetScreenHeight() - sprite.height / frameCount;
	}*/
	if (position.y + spriteR.height > GetScreenHeight()) {
		position.y = GetScreenHeight() - spriteR.height;
	}

	// slight gravity
	position.y += waterGravity * GetFrameTime();
}

void Octopus::shrink()
{
	currentSize *= 1 - modifier;
	destRec.width *= 1 - modifier;
	destRec.height *= 1 - modifier;
	health -= modifier;
}

Rectangle Octopus::boundingBox()
{
	return { position.x, position.y, spriteC.width * currentSize, spriteC.height * currentSize };
}

void Octopus::grow()
{
	// correct porportion?
	currentSize *= 1 + modifier;
	destRec.width *= 1 + modifier;
	destRec.height *= 1 + modifier;	
}
