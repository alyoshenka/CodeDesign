#include "Falling.h"



Falling::Falling()
{
	// Falling::spriteMasters = nullptr;
	// Falling::spriteCount = 0;
}


Falling::~Falling()
{
	delete[] spriteMasters;
}

//FallingFactory.cpp
void Falling::init()
{
	//Load in the various sprites
	spriteCount = 3;
	spriteMasters = new Spritey[spriteCount];
	spriteMasters[0] = *(new Spritey("bzombie.png", "big zombie", 1.0f));
	spriteMasters[1] = *(new Spritey("bogre.png", "big ogre", 1.0f));
	spriteMasters[2] = *(new Spritey("bdemon.png", "big demon", 1.0f));
}

Spritey * Falling::getRandom()
{
	// choose random sprite
	int r = GetRandomValue(0, spriteCount - 1);
	// make copy
	Spritey * s = new Spritey(spriteMasters[r]);
	s->pos = GetMousePosition();
	// DrawTexturePro is dumb
	s->r1.x = GetMouseX();
	s->r1.y = GetMouseY();
	s->r2.x = GetMouseX();
	s->r2.y = GetMouseY();
	// s->texture = spriteMasters[r].texture;
	return s;
}

Spritey * Falling::getFromType(const std::string & _sprType)
{
	for(int i = 0; i < spriteCount; i++) {
		if (spriteMasters[i].sprType == _sprType) {
			return & spriteMasters[i];
		}
	}

	return nullptr;
}

