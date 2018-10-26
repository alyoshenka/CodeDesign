#include "Enem.h"



Enem::Enem()
{
	mySprite = LoadTexture("barb.png");
	position = { 0, 0 };
	// destination = { 0, 0 };
	isActive = true;

	speed.x = GetRandomValue(15, 70);
	speed.y = GetRandomValue(15, 70);
	
	int xNeg = GetRandomValue(0, 1);
	int yNeg = GetRandomValue(0, 1);

	if(xNeg == 0) {
		speed.x *= -1;
	}
	if (yNeg == 0) {
		speed.y *= -1;
	}

	// more random
	int oneWay = GetRandomValue(0, 30);
	if (oneWay == 0) {
		speed.x = 0;
		}
	if (oneWay == 1) {
		speed.y = 0;
	}
	
}


Enem::~Enem()
{
	// UnloadTexture(mySprite);
}

void Enem::update()
{	

	// move
	position.x += speed.x * GetFrameTime();
	position.y -= speed.y * GetFrameTime();

}

void Enem::draw()
{
	// if alive
	//if (isActive) {
	//	// offset for size
	//	DrawTexture(mySprite, position.x - 4, position.y - 8, WHITE);
	//}
	DrawTexture(mySprite, position.x - 5, position.y - 10, WHITE);
}

