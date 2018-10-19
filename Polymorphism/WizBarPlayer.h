#pragma once
#include "raylib.h"
#include <iostream>
class WizBarPlayer
{
public:
	Vector2 position = { 0,0 };
	Vector2 destination = { 0,0 };
	float speed = 0.01f;
	Texture2D mySprite;

	// true if close, false if far
	virtual bool moveTo(const Vector2 &dest);

	WizBarPlayer();
	WizBarPlayer(const std::string & fileName); // assign the sprite image.
	~WizBarPlayer();

	void draw();
	virtual void update();
	virtual bool attack(Rectangle enemy);
};

