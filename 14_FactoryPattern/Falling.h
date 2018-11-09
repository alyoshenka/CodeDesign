//Falling.h
#pragma once
#include "raylib.h"
#include "Spritey.h"

class Falling
{
	static Spritey * spriteMasters;
	static size_t spriteCount;

public:
	static void init();

	static Spritey * getRandom();// returns a random sprite from all sprites loaded
	static Spritey * getFromType(const std::string & _sprType);// Returns a random sprite from this type of sprites.

	Falling();
	~Falling();
};

