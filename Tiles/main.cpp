#include "raylib.h"
#include "Tile.h";
#include <iostream>

int main() {

	int screenWidth = 640;
	int screenHeight = 320;

	InitWindow(screenWidth, screenHeight, "Tiles");

	int tileSize = 64;

	// master Tile
	Tile master;
	int tileCount = 50;
	Tile * backgroundArr = new Tile[tileCount];
	// populate array
	// Color tint = WHITE;
	float y = 0.0f;
	float x = 0.0f;
	for (int i = 0; i < tileCount; i++) {
		backgroundArr[i] = master;
		backgroundArr[i].position = { x, y };

		// update x & y
		x += tileSize;
		if (x >= screenWidth) {
			x = 0;
			y += tileSize;
		}
	}

	// stamps

	// t = top
	// b = bottom
	// l = left
	// r = right
	Tile tl("assets/mapTile_136.png");
	tl.position = { 10.0f, 10.0f };
	Tile tr("assets/mapTile_115.png");
	tr.position = { screenWidth - tileSize - 10.0f, 10.0f };
	Tile bl("assets/mapTile_094.png");
	bl.position = { 10.0f, screenHeight - tileSize - 10.0f };
	Tile br("assets/mapTile_100.png");
	br.position = { screenWidth - tileSize - 10.0f, screenHeight - tileSize - 10.0f };
	Tile stamps[] = { tl, tr, bl, br };
	int selectedTile = -1;

	Tile test("assets/mapTile_114.png");
	test.position = { 100.0f, 100.0f };

	Tile stampedArr[10]; // max 10 stamps
	int startIdx = 0;
	// show = false
	for (int i = 0; i < 10; i++) {
		stampedArr[i].show = false;
	}

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		// update

		// check for new stamp selected
		if (IsMouseButtonPressed(0)) {
			// iterate through stamps
			for (int i = 0; i < 4; i++) {
				if (CheckCollisionPointRec(GetMousePosition(), 
					{ stamps[i].position.x,stamps[i].position.y, 
					(float)tileSize, (float)tileSize })) {

					// if already selected
					if (selectedTile == i) {
						// deselect
						selectedTile = -1;
					}
					else {
						// select
						selectedTile = i;
					}
				}
			}
		}

		// check for stamp being placed
		if (IsMouseButtonPressed(1) && selectedTile != -1) {

			Tile *a = new Tile;
			*a = stamps[selectedTile];
			// *a.position = GetMousePosition(); // ???
			a.position = { 100.0f, 100.0f };

			// new stamp 
			// stampedArr[startIdx] = stamps[selectedTile]; // = not working
			stampedArr[startIdx] = *a;

			// stampedArr[startIdx].position = GetMousePosition();
			
			startIdx++;

			// constrain
			if (startIdx > 9) {
				startIdx = 0;
			}

			delete a;
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);

		// background tiles
		for (int i = 0; i < tileCount; i++) {
			backgroundArr[i].draw();
		}
		
		// user placed stams
		for (int i = 0; i < 10; i++) {
			// null value??
			stampedArr[i].draw();
		}

		// stamp tiles
		for (int i = 0; i < 4; i++) {
			// border
			if (i == selectedTile) {
				DrawRectangle(stamps[i].position.x, stamps[i].position.y,
					tileSize, tileSize, PINK);
			}
			else {
				DrawRectangle(stamps[i].position.x, stamps[i].position.y,
					tileSize, tileSize, BLACK);
			}
	
			// tile
			stamps[i].draw();
		}

		// user placed stamps
		for (int i = 0; i < 10; i++) {
			if(stampedArr[i].show) {
				stampedArr[i].draw();
			}			
		}

		// test.draw();

		EndDrawing();
	}


	CloseWindow();
	return 0;
}