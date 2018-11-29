#include "Fish.h"

Fish::Fish()
{
	sprite = LoadTexture("assets/fishP.png");
	speed = 150.0f;
	size = 0.4f;

	// random position within screen bounds
	position = { (float)GetScreenWidth() - sprite.width * size,
		(float)GetRandomValue(0, GetScreenHeight() - sprite.height * size) };

}

Fish::Fish(std::string _sprite, float _speed, float _size) : Fish::Fish()
{
	UnloadTexture(sprite);

	sprite = LoadTexture(_sprite.c_str());
	speed = _speed;
	size = _size;
	// so it doesn't "peek" the edge of the screen
	position.x = (float)GetScreenWidth() - sprite.width * size;
}


Fish::~Fish()
{
	UnloadTexture(sprite);
}

void Fish::update()
{		
	position.x -= speed * GetFrameTime();
	
	// bounds checking done in fish manager
}

void Fish::draw()
{
	DrawTexturePro(sprite, { 0, 0, (float)sprite.width, (float)sprite.height }, { 0, 0, sprite.width * size, sprite.height * size }, { position.x * -1, position.y * -1 }, 0, WHITE);
}

void Fish::randomizeValues()
{
	position = { (float)GetScreenWidth() + sprite.width * size,
		(float)GetRandomValue(0, GetScreenHeight() - sprite.height * size) };

	speed = GetRandomValue(100, 150);
}

Rectangle Fish::boundingBox()
{
	// hitbox modifier
	float a = 0.75;
	return { position.x, position.y, sprite.width * size * a, sprite.height * size * a };
}

Fish& Fish::operator=(const Fish & rhs)
{
	// delete something here
	// UnloadTexture(sprite);

	// init vals
	sprite = rhs.sprite;
	speed = rhs.speed;
	size = rhs.size;
	randomizeValues();

	return *this;
}

