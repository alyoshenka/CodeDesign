#include "Sprite.h"



void Sprite::draw()
{
	DrawTexture(spriteCells[currentFrame], x, y, WHITE);
}

void Sprite::update()
{

	// movement state
	if (IsKeyDown(KEY_D)) {
		walking = true;
		standing = false;
		climbing = false;
		minFrame = 2; // change how this is done
		// currentFrame = minFrame;
		maxFrame = 3;
		x++;
	}
	else if (IsKeyDown(KEY_W)) {
		walking = false;
		standing = false;
		climbing = true;
		minFrame = 4;
		// currentFrame = minFrame;
		maxFrame = 5;
		y--;
	}
	else {
		walking = false;
		climbing = false;
		standing = true;
		minFrame = 0;
		// currentFrame = minFrame; // this was the problem
		maxFrame = 1;
	}

	// update, given state
	framesCounter++;
	if (framesCounter >= (60 / frameRate)){

		framesCounter = 0;

		currentFrame++;

		// better way but this works to constrain
		if (currentFrame < minFrame) {
			currentFrame = minFrame;
		}

		if (currentFrame > maxFrame) {
			currentFrame = minFrame;
		}
	}	
}

Sprite::Sprite(const std::string * filename, const int cellCount, const float _frameRate)
{
	// populate cells with filename textures
	for (int i = 0; i < cellCount; i++) {
		spriteCells[i] = LoadTexture(filename[i].c_str());
	}

	frameRate = _frameRate;
	frameCount = cellCount;
}

Sprite::Sprite()
{
	spriteCells = new Texture2D[frameCount];
	spriteCells[0] = LoadTexture("assets/player_stand.png");
	spriteCells[1] = LoadTexture("assets/player_stand.png");
	spriteCells[2] = LoadTexture("assets/player_walk1.png");
	spriteCells[3] = LoadTexture("assets/player_walk2.png");
	spriteCells[4] = LoadTexture("assets/player_climb1.png");
	spriteCells[5] = LoadTexture("assets/player_climb2.png");

	frameCount = 6;

	standing = true;
	walking = false;
	climbing = false;
}


Sprite::~Sprite()
{
	// unload textures
	for (int i = 0; i < frameCount; i++) {
		UnloadTexture(spriteCells[i]);
	}

	// delete arr
	delete[] spriteCells;
}
