#include "Clock.h"



void Clock::drawFace()
{
	Vector2 endPos = { position.x + 180 / PI * cos(currentAngle * time - (0.5 * PI)) * (radius / 65), 
		position.y + 180 / PI * sin(currentAngle * time - (0.5 * PI)) * (radius / 65) };

	// face
	DrawCircleV(position, radius, WHITE);
	// hand
	DrawLineEx(position, endPos, 2.0f, BLUE);

	// numbers
	float numSize = radius / 8;
	for (int i = 1; i <= 12; i++) {
		float rad = 2 * PI * i * 30 / 360; // takes in radians!!
		std::string s = std::to_string(i);
		DrawText(s.c_str(), position.x + 180 / PI * cos(rad - (0.5 * PI)) * (radius / 70) - numSize / 2,
			position.y + 180 / PI * sin(rad - (0.5 * PI)) * (radius / 70) - numSize / 2, numSize, BLUE);
	}
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
	position = { 400.0f, 250.0f };
	radius = 100.0f;
	time = 1.0f;

	// degreeOfRotation = 1.0f;
}


Clock::~Clock()
{
}
