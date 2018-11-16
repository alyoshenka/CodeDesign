#pragma once
#include "gamestate.h"

class menustate : gamestate
{
public:
	menustate();
	~menustate();

	virtual GameStates next() override;
};

