#pragma once
#include "gamestate.h"
class gameoverstate :
	public gamestate
{
public:
	gameoverstate();
	~gameoverstate();

	void update();
	virtual void draw();
	virtual GameStates next() override;
};

