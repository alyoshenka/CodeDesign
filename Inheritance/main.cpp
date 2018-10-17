#include "Sprite.h"
#include "raylib.h"

int main() {

	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Sprites");

	Sprite myGuy;
	myGuy.x = 100;
	myGuy.y = 300;

	SetTargetFPS(60);
	while (!WindowShouldClose()) {

		myGuy.update();

		BeginDrawing();

		ClearBackground(RAYWHITE);

		myGuy.draw();

		EndDrawing();
	}

	CloseWindow();
}