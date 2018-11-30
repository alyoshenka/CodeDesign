#include "Fish.h"

Fish::Fish()
{
	sprite = LoadTexture("assets/fishP.png");
	// spritePtr = &sprite;
	size = 0.4f;
	waveMath = 0.0f;

	randomizeValues();
}

Fish::Fish(std::string _sprite, float _speed, float _size) : Fish::Fish()
{
	UnloadTexture(sprite);

	sprite = LoadTexture(_sprite.c_str());
	// spritePtr = &sprite;
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
	waveMath += GetFrameTime() * waveMod;
	position.y += sin(waveMath) / 2;	
	// bounds checking done in fish manager
}

void Fish::draw()
{
	DrawTexturePro(sprite, { 0, 0, (float)sprite.width, (float)sprite.height }, { 0, 0, sprite.width * size, sprite.height * size }, { position.x * -1, position.y * -1 }, 0, WHITE);
}

void Fish::randomizeValues()
{
	position = { (float)GetRandomValue(GetScreenWidth() + sprite.width * size, GetScreenWidth() * 2),
		(float)GetRandomValue(0, GetScreenHeight() - sprite.height * size) };

	speed = GetRandomValue(100, 150);
	waveMod = GetRandomValue(1, 10) / 3;
}

Rectangle Fish::boundingBox()
{
	// scaled down so you really have to hit the enemies for a collision to occur
	// hitbox modifier
	float a = 0.75;
	return { position.x, position.y, sprite.width * size * a, sprite.height * size * a };
}

Fish& Fish::operator=(const Fish & rhs)
{
	// delete something here
	// UnloadTexture(sprite);

	// init vals
	sprite = rhs.sprite; // this is the problem
	// spritePtr = rhs.spritePtr;
	// sprite = *spritePtr;

	speed = rhs.speed;
	size = rhs.size;
	randomizeValues();

	return *this;
}

