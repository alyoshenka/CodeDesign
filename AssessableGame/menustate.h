#pragma once
#include "gamestate.h"

class menustate : public gamestate
{
	Rectangle start;
	Rectangle controls;
public:
	menustate();
	~menustate();

	void update();
	virtual void draw() override;
	virtual GameStates next() override;
};

