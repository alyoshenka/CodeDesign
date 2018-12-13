#pragma once
#include "raylib.h"
#include <string>
#include <math.h>

//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//#ifdef _DEBUG
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW
//#endif

class Fish
{
	// used for sin y movement
	float waveMath;
	// "wave" size modifier (period?)
	float waveMod;

public:
	// made public for easy access elsewhere
	
	Texture2D sprite;
	// Texture2D * spritePtr;
	float speed;
	// how big it is, relative to texture
	float size;
	Vector2 position;

	Fish();
	Fish(std::string filePath, float _speed, float _size);
	~Fish();

	void update();
	void draw();

	void randomizeValues();
	// void randomizeValues(size_t level);

	// return bounding box (to test for collision)
	Rectangle boundingBox();

	// copy assignment operator
	Fish& operator = (const Fish & rhs);
	
	// move semantics
	// move constructor
	Fish(Fish && rhs);
	// move assignment operator
	Fish& operator = (Fish && rhs);
};

