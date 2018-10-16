#pragma once
#include "Entity.h"
class Barbarian: public Entity
{
public:
	Barbarian();
	~Barbarian();

	void draw();
	// void update(float deltaTime); // should this be constrained to player?? yes
	void resize(Vector2 scale);
};

