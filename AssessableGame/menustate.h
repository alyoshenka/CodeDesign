#pragma once
#include "gamestate.h"
#include "aButton.h"

class menustate : public gamestate
{
	aButton startButton;
	aButton detailButton;
	int pauseTime;
	int timer;

public:
	menustate();
	~menustate();

	void update();
	virtual void draw() override;
	virtual GameStates next() override;
};

