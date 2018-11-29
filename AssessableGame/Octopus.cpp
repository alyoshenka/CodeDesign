#include "Octopus.h"

Octopus::Octopus()
{
	/*sprite = LoadTexture("octopusGuy.png");
	frameCount = 14;
	sourceRec = { 0, 0, (float)sprite.width, (float)sprite.height / frameCount};	
	currentFrame = 0;
	animationSpeed = 500;
	currentFrameItr = 0;*/
	spriteL = LoadTexture("assets/fishL.png");
	spriteR = LoadTexture("assets/fishR.png");
	spriteC = spriteR;
	sourceRec = {0.0f, 0.0f, (float)spriteR.width, (float)spriteR.height};
	position = { 0, 0 };
	speed = 250.0f;
	waterGravity = speed / 10;

	size = 0.5f;
	// trying to get 3x bigger
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
	// DrawTexturePro(spriteC, sourceRec, boundingBox(), { position.x * -1, position.y * -1 }, 0, WHITE);
	DrawTexturePro(spriteC, sourceRec, {0, 0, spriteC.width * size, spriteC.height * size}, { position.x * -1, position.y * -1 }, 0, WHITE);
}

void Octopus::update()
{

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
	if (position.x + boundingBox().width > GetScreenWidth()) {
		position.x = GetScreenWidth() - boundingBox().width;
	}
	if (position.y < 0) {
		position.y = 0;
	}
	if (position.y + boundingBox().height > GetScreenHeight()) {
		position.y = GetScreenHeight() - boundingBox().height;
	}

	// slight gravity
	position.y += waterGravity * GetFrameTime();
}

void Octopus::shrink()
{
	size *= 1 - modifier;
	// health -= modifier;
}

Rectangle Octopus::boundingBox()
{
	// hitbox modifier
	float a = 0.8;
	return { position.x, position.y, spriteC.width * size * a, spriteC.height * size * a};
}

void Octopus::grow()
{
	// correct porportion?
	size *= 1 + modifier;
}
