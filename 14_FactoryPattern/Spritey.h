//SimpleSprite.h
#pragma once
#include <iostream>
#include "raylib.h"
class Spritey
{
public:
	std::string sprType;
	Vector2 pos;
	float rot;
	Rectangle sourceRec, r2; // r1 = size of texture , r2 = calculated destination size
	Texture2D texture;

	void translate(Vector2 delta); // move the sprites position by delta.
	void draw(); //draw the sprite on screen
	Spritey();
	Spritey(const Spritey & s);
	Spritey(const std::string & filename, const std::string _sprType = "", float scale = 1);
	// Spritey(const Spritey s);
	void operator = (const Spritey &);
	~Spritey();

	Spritey * Clone();
};

