#pragma once
#include "gamestate.h"
#include "Octopus.h"
// #include "Enemy.h"
#include "FishManager.h"


class level1 : public gamestate
{
	Octopus player;
	// Enemy enemies;
	Texture2D background;

	FishManager enemyInstance;

public:

	level1();
	~level1();

	void update();
	virtual void draw();
	virtual GameStates next() override;
};

