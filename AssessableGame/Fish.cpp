#include "Fish.h"

Fish::Fish()
{
	sprite = LoadTexture("fishE.png");
	speed = 150.0f;
	size = 1.0f;
	position = { (float)GetScreenWidth() - sprite.width * size,
		(float)GetRandomValue(0, GetScreenHeight() - sprite.height * size) };
}

Fish::Fish(std::string _sprite, float _speed, float _size)
{
	sprite = LoadTexture(_sprite.c_str());
	speed = _speed;
	size = _size;
	position = { (float)GetScreenWidth() - sprite.width * size,
		(float)GetRandomValue(0, GetScreenHeight() - sprite.height * size) };
}


Fish::~Fish()
{
	UnloadTexture(sprite);
}

void Fish::update()
{
		
	position.x -= speed * GetFrameTime();
	
	if (position.x + sprite.width <= 0) {
		// call facroty function to *remove*
	}
	
}

void Fish::draw()
{
	/*DrawTexturePro(sprite, startSize, currentSize,
		{ fishies[i].x * -1, fishies[i].y * -1 }, 0, RED);*/
	DrawTextureV(sprite, position, WHITE);
}

void Fish::randomizePosition()
{
	position = { (float)GetScreenWidth() + sprite.width * size,
		(float)GetRandomValue(0, GetScreenHeight() - sprite.height * size) };
}

Fish& Fish::operator=(const Fish & rhs)
{
	// delete something here
	UnloadTexture(sprite);

	// init vals
	sprite = rhs.sprite;
	speed = rhs.speed;
	size = rhs.size;
	randomizePosition();

	return *this;
}

