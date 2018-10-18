#include "Sprite.h"



void Sprite::draw()
{
	DrawTexture(activeCells[currentFrame], x, y, WHITE);
}

void Sprite::update(float deltaTime)
{
	// movement state
	if (IsKeyDown(KEY_D)) {
		walking = true;
		standing = false;
		climbing = false; // are these necessary?

		if (walkingCells != NULL) {
			activeCells = walkingCells;
			activeCount = walkingCount;
		}
	
		x += velocity.x;
	}
	else if (IsKeyDown(KEY_A)) {
		walking = false;
		standing = false;
		climbing = true;

		if (walkingCells != NULL) {
			activeCells = walkingCells;
			activeCount = walkingCount;
		}

		x -= velocity.x;
	}
	else if (IsKeyDown(KEY_W)) {
		walking = false;
		standing = false;
		climbing = true;

		if (climbingCells != NULL) {
			activeCells = climbingCells;
			activeCount = climbingCount;
		}
			
		y-= velocity.y;
	}
	else if (IsKeyDown(KEY_S)) {
		walking = false;
		standing = false;
		climbing = true;

		if (climbingCells != NULL) {
			activeCells = climbingCells;
			activeCount = climbingCount;
		}

		y += velocity.y;
	}
	else {
		walking = false;
		climbing = false;
		standing = true;

		if (standingCells != NULL) {
			activeCells = standingCells;
			activeCount = standingCount;
		}	
		// else
		// = active
	}

	// update, given state
	totalTime += deltaTime * 10;

	if (totalTime >= frameRate){

		totalTime = 0;

		currentFrame++;

		// better way but this works to constrain
		if (currentFrame >= activeCount) {
			currentFrame = 0;
		}
	}	
}

Sprite::Sprite(const std::string * filename, const int cellCount, const float _frameRate)
{
	activeCells = new Texture[cellCount];
	// populate cells with filename textures
	for (int i = 0; i < cellCount; i++) {
		activeCells[i] = LoadTexture(filename[i].c_str());
	}

	frameRate = _frameRate;
	frameCount = cellCount;
	activeCount = cellCount;

	velocity = { 2.0f, 2.0f };

	standing = true;
	walking = false;
	climbing = false;
}

Sprite::Sprite()
{
	standingCount = 2; // because otherwise it flashes
	standingCells = new Texture2D[standingCount];
	standingCells[0] = LoadTexture("assets/player_stand.png");
	standingCells[1] = LoadTexture("assets/player_stand.png");

	walkingCount = 2;
	walkingCells = new Texture2D[walkingCount];
	walkingCells[0] = LoadTexture("assets/player_walk1.png");
	walkingCells[1] = LoadTexture("assets/player_walk2.png");

	climbingCount = 2;
	climbingCells = new Texture2D[climbingCount];
	climbingCells[0] = LoadTexture("assets/player_climb1.png");
	climbingCells[1] = LoadTexture("assets/player_climb2.png");

	velocity = { 2.0f, 2.0f };

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

	// delete arrays
	delete[] spriteCells;
	delete[] standingCells;
	delete[] walkingCells;
	delete[] climbingCells;
}
