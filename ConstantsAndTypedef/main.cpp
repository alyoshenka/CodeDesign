#include "raylib.h"
#include "Clock.h"

// currentAngle = 0.0f;
Vector2 Clock::position = { 400.0f, 250.0f };
float Clock::radius = 100.0f;
float Clock::degreeOfRotation = 0.03f;

int main() {

	/*Vector2 Clock::position = { 400.0f, 250.0f };
	float Clock::radius = 100.0f;
	float Clock::degreeOfRotation = 0.03f;*/

	int w = 800;
	int h = 450;
	InitWindow(w, h, "Constatntss");

	Clock c;

	while (!WindowShouldClose()) {

		// update all clocks
		Clock::tick();

		BeginDrawing();

		ClearBackground(BLACK);

		Clock::drawFace();
		
		EndDrawing();
	}

	CloseWindow();

	return 0;
}