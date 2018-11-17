#pragma once
#include "gamestate.h"
#include "aButton.h"
#include <fstream>
#include <iostream>

class menustate : public gamestate
{
	aButton startButton;
	aButton detailButton;
	int pauseTime;
	int timer;
	std::string fileText;

public:
	menustate();
	~menustate();

	void update();
	virtual void draw() override;
	virtual GameStates next() override;
};

