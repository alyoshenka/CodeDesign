#include "Clock.h"



void Clock::drawFace()
{
	Vector2 endPos = { position.x + 180 / PI * cos(currentAngle) * (radius / 65), 
		position.y + 180 / PI * sin(currentAngle) * (radius / 65) };
	// face
	DrawCircleV(position, radius, WHITE);
	// hand
	DrawLineEx(position, endPos, 2.0f, BLUE);
}

void Clock::tick()
{
	// update angle	
	// currentAngle += degreeOfRotation;
		// 1 sec = 1 rotation
	currentAngle += GetFrameTime() * 2 * PI;

	// not really needed
	// constrain 0  - < 360
	// wrong offset
	/*if (currentAngle >= 360 / (2*PI)) {
		currentAngle = currentAngle - 360;
	}*/
}

Clock::Clock()
{
	// position = { 400.0f, 250.0f };
	// radius = 40.0f;

	// degreeOfRotation = 1.0f;
}


Clock::~Clock()
{
}
