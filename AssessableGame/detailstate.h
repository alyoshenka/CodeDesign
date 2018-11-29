#pragma once
#include "gamestate.h"
#include <string>
#include <fstream>
#include <iostream>

class detailstate :
	public gamestate
{
	std::string fileText;
public:
	detailstate();
	~detailstate();

	virtual void draw();
	virtual GameStates next() override;
};

