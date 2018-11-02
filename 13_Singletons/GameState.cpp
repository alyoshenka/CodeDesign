#include "GameState.h"



GameState::GameState()
{
	state = MainMenu;
}

GameState::GameState(GameState const &)
{
	// nothing
}

void GameState::operator=(GameState const &)
{
	// nothing
}

State GameState::getState()
{
	return state;
}

State GameState::setState(State newState)
{
	state = newState;
	return state;
}

GameState & GameState::GetInstance()
{
	static GameState instance;
	return instance;
}


GameState::~GameState()
{
}
