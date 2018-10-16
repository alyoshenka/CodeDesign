#include "raylib.h"
#include "Wizard.h"
#include "Barbarian.h"
#include "Corpse.h"
#include "Player.h"

int main() {
	// screen dimensions
	// multiples of 16 for tiles
	int screenWidth = 1600;
	int screenHeight = 832;

	// initialize window
	InitWindow(screenWidth, screenHeight, "Dungeon Shooty");

	// load floor textures
	int tileSize = 64; // until resizing

					   // main floor tile
	Image floor_i = LoadImage("assets/floor_1.png");
	ImageResize(&floor_i, tileSize, tileSize);
	Texture2D floor = LoadTextureFromImage(floor_i);
	UnloadImage(floor_i);

	// characters
	Wizard wiz1;
	wiz1.position = { 100, 100 };
	wiz1.resize({ (float)tileSize/2, (float)tileSize });

	Barbarian barb1;
	barb1.position = { 400, 200 };
	barb1.resize({ (float)tileSize / 2, (float)tileSize });

	Corpse zomb1; // tester
	zomb1.position = { 50, 300 };
	zomb1.resize({ (float)tileSize / 2, (float)tileSize / 2 });

	Player me;
	me.position = { 1000, 500 };
	me.resize({ (float)tileSize, (float)tileSize*2 });

	SetTargetFPS(60);
	// main game loop
	while (!WindowShouldClose()) {

		// update
		me.update(GetFrameTime());

		// draw
		BeginDrawing();

		ClearBackground(RAYWHITE);

		// floor
		// borders come later
		for (int y = 0; y < screenHeight; y += tileSize) {
			for (int x = 0; x < screenWidth; x += tileSize) {
				// random crack
				// changes every time
				/*if (GetRandomValue(0, 5) == 0) {
				DrawTexture(floor_crack, x, y, WHITE);
				}
				else {
				DrawTexture(floor, x, y, WHITE);
				}*/
				DrawTexture(floor, x, y, WHITE);
			}
		}

		// characters
		wiz1.draw();
		barb1.draw();
		zomb1.draw();
		me.draw();

		EndDrawing();

	}

	// de initialize
	UnloadTexture(floor);

	CloseWindow();

	return 0;

}