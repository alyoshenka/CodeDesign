#include <iostream>

#include "tVector.h"
#include "raylib.h"

// #include "WizBarNecromancer.h"

int main() {

	tVector<int>original;
	original.push_back(4);
	original.push_back(5);
	original.push_back(6);
	std::cout << original.at(0) << std::endl;
	std::cout << original.at(1) << std::endl;
	std::cout << original.at(2) << std::endl;

	tVector<int> copy = original;

	original.pop_back();
	original.pop_back();
	original.pop_back();
	original.push_back(100);

	std::cout << copy.size() << std::endl;
	std::cout << "orig" << std::endl;
	std::cout << original.at(0) << std::endl;
	std::cout << original.at(1) << std::endl;
	std::cout << original.at(2) << std::endl;
	std::cout << "copy" << std::endl;
	std::cout << copy.at(0) << std::endl;
	std::cout << copy.at(1) << std::endl;
	std::cout << copy.at(2) << std::endl;

	/*std::cout << "[]" << std::endl;
	std::cout << copy[0] << std::endl;
	std::cout << copy[1] << std::endl;
	std::cout << copy[2] << std::endl;*/

	int w = 800;
	int h = 450;
	InitWindow(w, h, "dynamArr");

	// tVector<WizBarNecromancer> sprites;
	tVector<Texture2D> sprites;
	tVector<Vector2> positions;
	Texture2D sprite = LoadTexture("barb.png");

	SetTargetFPS(60);
	while(!WindowShouldClose()) {

		// update arr
		if (IsMouseButtonDown(0)) {
			/*WizBarNecromancer e;
			e.position = GetMousePosition();
			sprites.push_back(e);*/
			sprites.push_back(sprite);
			positions.push_back(GetMousePosition());
		}

		// update contents
		/*for (int i = 0; i < sprites.size(); i++) {
			sprites[i].moveTo(GetMousePosition());
		}*/

		BeginDrawing();

		ClearBackground(WHITE);

		// draw
		for (int i = 0; i < sprites.size(); i++) {
			// sprites[i].draw();
			DrawTextureV(sprites[i], positions[i], WHITE);
		}

		EndDrawing();

	}

	UnloadTexture(sprite);

	CloseWindow();

	return 0;
}