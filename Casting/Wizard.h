#pragma once
#include "Entity.h"
class Wizard: public Entity
{
public:
	Wizard();
	~Wizard();

	void draw();
	// void update(float deltaTime);
	void resize(Vector2 scale);
};

