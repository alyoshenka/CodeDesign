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
	currentAngle += GetFrameTime(); // change for real time

	// constrain 0  - < 360
	if (currentAngle >= 360) {
		currentAngle = currentAngle - 360;
	}
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
