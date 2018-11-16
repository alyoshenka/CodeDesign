#pragma once
#include "gamestate.h"
class detailstate :
	public gamestate
{
public:
	detailstate();
	~detailstate();

	virtual void draw();
	virtual GameStates next() override;
};

