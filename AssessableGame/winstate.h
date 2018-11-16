#pragma once
#include "gamestate.h"
class winstate :
	public gamestate
{
public:
	winstate();
	~winstate();

	virtual void draw() override;
	virtual GameStates next() override;
};

