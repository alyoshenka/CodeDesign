#pragma once
#include "Entity.h"
#include "Barbarian.h"
#include "Wizard.h"


class Corpse: public Entity
{
public:
	Corpse(Wizard a);
	Corpse(Barbarian a);
	Corpse();
	~Corpse();

	void draw();
	void resize(Vector2 scale);
};

