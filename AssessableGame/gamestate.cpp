#include "gamestate.h"
#include "menustate.h"
#include "levelstate.h"
#include "gameoverstate.h"
#include "detailstate.h"
#include "winstate.h"

gamestate::gamestate()
{
}


gamestate::~gamestate()
{
}

void gamestate::update()
{
}

void gamestate::draw()
{
}

void setupGameState(gamestate *& ptr, GameStates newState)
{
	switch (newState) {
	case GameStates::NONE: ptr = new gamestate(); break;
	case GameStates::MENU: ptr = new menustate(); break;
	case GameStates::DETAIL: ptr = new detailstate(); break;
	case GameStates::LEVEL: ptr = new levelstate(); break;
	case GameStates::WIN: ptr = new winstate(); break;
	case GameStates::LOSE: ptr = new gameoverstate(); break;

	default: assert(false && "Invalid state specified");
	}
}
