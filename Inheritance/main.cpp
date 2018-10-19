#include "Sprite.h"
#include "raylib.h"
#include <string>
#include "Button.h"

int main() {

	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Sprites");

	Sprite myGuy;
	myGuy.x = 100;
	myGuy.y = 300;

	std::string names[] = { "assets/player_cheer1.png", "assets/player_stand.png" };
	Sprite duderino(names, 2, 3.0f );

	Button butt;

	SetTargetFPS(60);
	while (!WindowShouldClose()) {

		// myGuy.update(GetFrameTime());
		// duderino.update(GetFrameTime());
		butt.update();

		BeginDrawing();

		ClearBackground(RAYWHITE);
		
		// myGuy.draw();
		// duderino.draw();
		butt.draw();

		EndDrawing();
	}

	CloseWindow();
}