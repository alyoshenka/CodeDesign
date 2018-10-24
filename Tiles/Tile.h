#pragma once
#include "raylib.h"
#include <string>

class Tile
{
public:

	int size;
	Vector2 position;
	Texture2D sprite;
	Texture2D * spritePointer;
	bool show;

	Tile();
	Tile(std::string filePath);
	~Tile();

	void draw();
	Tile & operator = (const Tile &rhs);
};

