#pragma once
#include "raylib.h"
#include <string>
// #include <math.h>

class Fish
{
public:
	
	Texture2D sprite;
	float speed;
	//how big it is, relative to texture
	float size;
	Vector2 position;



	Fish();
	Fish(std::string filePath, float _speed, float _size);
	~Fish();

	void update();
	void draw();

	void randomizePosition();

	// copy constructor
	Fish& operator = (const Fish & rhs);
};

