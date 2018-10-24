#include "raylib.h"
#include "Clock.h"

// currentAngle = 0.0f;
// Vector2 Clock::position = { 400.0f, 250.0f };
// float Clock::radius = 100.0f;
// float Clock::degreeOfRotation = 0.03f;

int main() {

	/*Vector2 Clock::position = { 400.0f, 250.0f };
	float Clock::radius = 100.0f;
	float Clock::degreeOfRotation = 0.03f;*/

	int w = 800;
	int h = 450;
	InitWindow(w, h, "Constatntss");

	Clock s;
	s.radius = 120.0f;
	Clock m;
	m.time = 1.0f / 60;
	m.radius = 80.0f;
	m.position = { 100.0f, 100.0f };
	Clock hr;
	hr.radius = 50.0f;
	hr.time = 1 / 3600.0f; // 60 * 60
	hr.position = { 600, 150 };



	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		// update all clocks
		Clock::tick();

		BeginDrawing();

		ClearBackground(BLACK);

		s.drawFace();
		DrawText("Once a second", s.position.x, s.position.y + s.radius + 20, 15, RED);
		m.drawFace();
		DrawText("Once a minute", m.position.x, m.position.y + m.radius + 20, 15, RED);
		hr.drawFace();
		DrawText("Once an hour", hr.position.x, hr.position.y + hr.radius + 20, 15, RED);
		
		EndDrawing();
	}

	CloseWindow();

	return 0;
}