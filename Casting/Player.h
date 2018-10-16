#pragma once
#include "Entity.h"
class Player: public Entity
{
public:
	Player();
	~Player();

	void draw();
	void update(float deltaTime);
	void resize(Vector2 scale);
};

