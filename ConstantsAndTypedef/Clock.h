#pragma once
#include "raylib.h"
#include <math.h>
#include <string>

static float currentAngle = 0.0f;

class Clock
{
public:
	
	// static Vector2 position;
	// static float radius;

	Vector2 position;
	float radius;

	float time;

	// angle of rotatin each time;
	static float degreeOfRotation; // should be static?

	void drawFace();
	static void tick();

	Clock();
	~Clock();
};

