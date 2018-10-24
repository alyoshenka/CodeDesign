#include "Tile.h"



Tile::Tile()
{
	spritePointer = &LoadTexture("assets/mapTile_017.png");
	sprite = *spritePointer;
	position = { 0, 0 };
	size = 64;
	show = true;
}

Tile::Tile(std::string filePath) // implement constructor chaining
{	
	spritePointer = &LoadTexture(filePath.c_str());
	sprite = *spritePointer;
	position = { 0.0f, 0.0f };
	size = 64;
	show = true;
}


Tile::~Tile()
{
	// which one?
	UnloadTexture(*spritePointer);
	UnloadTexture(sprite);
}

void Tile::draw()
{
	DrawTextureV(sprite, position, WHITE);
}

Tile& Tile::operator=(const Tile & rhs)
{
	// Tile a;
	size = rhs.size;
	position = rhs.position;
	
	// are textures different?
	// sprite = rhs.sprite;
	spritePointer = new Texture2D(*rhs.spritePointer);
	// sprite = new Texture2D(&spritePointer);

	return *this;
}
