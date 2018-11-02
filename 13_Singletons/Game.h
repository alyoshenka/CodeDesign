#pragma once
#include "GameState.h"
#include "raylib.h"
#include <string>

// should this be the singleton?
// making it a singleton

class Game
{
private:

	Game();

	void mainMenu();
	void playerSelect();
	void inGame();
	void gameOver();
	void dropBlocks();

	int health;

	int blockSpeed, blockDamage; // idx not needed here
	int blockW, blockH;
	const int blockCount =50; // can't do in constructor
	Rectangle blocks[50]; // why cant i do blockCount

public:
	~Game();

	static Game & GetInstance();

	void go();

	int windowW, windowH;
	int floorH;
	int x, y;
	float speed;

	Texture2D sprite;
	int spriteW, spriteH;
};

