#include "tQueue.h"
#include "raylib.h"
#include "Guy.h"

int main() {

	int w = 800;
	int h = 450;
	InitWindow(w, h, "queueueues");

	Guy me;

	tQueue<Vector2> stops;

	SetTargetFPS(60);
	while(!WindowShouldClose()) {

		// update click queue
		if (IsMouseButtonPressed(0)) {
			stops.push(GetMousePosition());
		}
		// pop queue if dest reached
		if (me.moveTo(stops.front())) {
			stops.pop();
		}

		me.moveTo(stops.front());

		BeginDrawing();

		ClearBackground(WHITE);

		me.draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}