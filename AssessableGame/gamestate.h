#pragma once
#include <cassert>
#include "raylib.h"
#include <string>


enum GameStates {
	NONE,
	MENU,
	DETAIL,
	GAME,
	LEVEL,
	WIN,
	LOSE
};

class gamestate
{
	
public:
	static int score;

	gamestate();
	~gamestate();

	virtual void update();
	virtual void draw();
	virtual GameStates next() { return NONE; };
};

// only ONE place where everything is tied together
void setupGameState(gamestate *&ptr, GameStates newState);

