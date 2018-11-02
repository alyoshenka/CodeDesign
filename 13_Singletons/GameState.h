#pragma once

enum State {
	MainMenu=0,
	PlayerSelect,
	InGame,
	GameOver
};

class GameState
{
private:

	GameState();
	GameState(GameState const &); // prevent use
	void operator = (GameState const &); // prevent use

	State state;

public:
	State getState();
	State setState(State newState);
	static GameState & GetInstance();
	~GameState();
};

