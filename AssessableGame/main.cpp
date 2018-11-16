#include "raylib.h"
#include "Octopus.h"

int main() {

	int w = 1000;
	int h = 500;

	InitWindow(w, h, "OctoAdventure");

	Octopus o;

	while (!WindowShouldClose()) {
		o.update();
		BeginDrawing();
		ClearBackground(BLUE);
		o.draw();
		EndDrawing();
	}

	CloseWindow();

	return 0;
}