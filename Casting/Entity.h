#pragma once
#include <string>
#include "raylib.h"

// abstract class
class Entity
{
public:

	std::string name;
	std::string type;
	int maxHealth;
	int currentHealth;
	int gold;
	float speed; // not needed (yet)
	Vector2 position;
	Vector2 size;
	Texture2D sprite; // no moving sprites for now

	Entity();
	~Entity();

	// virtual void update(float deltaTime) = 0;
	virtual void draw() = 0;
	virtual void resize(Vector2 scale) = 0;
};

