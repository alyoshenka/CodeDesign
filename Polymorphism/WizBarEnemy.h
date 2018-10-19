#pragma once
#include "raylib.h"
#include <iostream>
class WizBarEnemy
{
public:
	Texture2D mySprite;
	float speed = 0.0f;
	Vector2 position = { 0, 0 };
	Vector2 destination = { 0, 0 };
	bool isActive = true;

	WizBarEnemy(const std::string & fileName);
	WizBarEnemy();
	~WizBarEnemy();

	virtual bool moveTo(const Vector2 &dest) = 0;
	void draw();
};

