#pragma once
#include "gamestate.h"
#include "Octopus.h"
// #include "Enemy.h"
#include "FishManager.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif


class level1 : public gamestate
{
	Octopus player;

	FishManager enemyInstance;

	size_t level;

	Texture healthSprite;
	// scale down health texture
	float hSize;

	// x val of seaweed
	int * seaweedPos;
	// is green texture
	bool * isGreen;
	// number of clumps of seaweed
	int seaweedCount;
	Texture2D seaweedP;
	Texture2D seaweedG;

public:

	level1();
	~level1();

	void update();
	virtual void draw();
	virtual GameStates next() override;
};

