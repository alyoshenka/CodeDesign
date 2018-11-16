#pragma once

enum GameStates {
	NONE,
	MENU,
	CONTROLS,
	GAME,
	WIN,
	LOSE
};

class gamestate
{
public:
	gamestate();
	~gamestate();

	virtual void draw();
	virtual GameStates next() { return NONE; };
};

// only ONE place where everything is tied together
void setupGameState(gamestate *&ptr, GameStates newState);

