#include "Entity.h"



Entity::Entity()
{
	name = "defaultName";
	type = "Entity";
	maxHealth = 100;
	currentHealth = 100;
	gold = 0;
	position = { 0, 0 };
	size = { 0, 0 };
	speed = 0.0f;
}


Entity::~Entity()
{
}
