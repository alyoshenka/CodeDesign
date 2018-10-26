#pragma once
#include "raylib.h"
#include <iostream>
class Guy
{
public:
	Vector2 position = { 0,0 };
	Vector2 destination = { 0,0 };
	float speed = 0.01f;
	Texture2D mySprite;

	// true if close, false if far
	virtual bool moveTo(const Vector2 &dest);

	Guy();
	// Guy(const std::string & fileName); // assign the sprite image.
	~Guy();

	void draw();
	void update();
	// virtual bool attack(Rectangle enemy);
};


