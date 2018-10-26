#include <iostream>

#include "tVector.h"
#include "raylib.h"

#include "Enem.h"


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
	std::cout << copy[0] << std::endl;
	std::cout << copy[1] << std::endl;
	std::cout << copy[2] << std::endl;

	// check assert
	// std::cout << copy.at(-1) << std::endl;

	/*std::cout << "[]" << std::endl;
	std::cout << copy[0] << std::endl;
	std::cout << copy[1] << std::endl;
	std::cout << copy[2] << std::endl;*/

	int w = 800;
	int h = 450;
	InitWindow(w, h, "dynamArr");

	tVector<Enem> sprites;

	/*tVector<Texture2D> sprites;
	tVector<Vector2> positions;
	Texture2D sprite = LoadTexture("barb.png");*/

	SetTargetFPS(60);
	while(!WindowShouldClose()) {

		// update arr
		if (IsMouseButtonDown(1)) {
			/*WizBarNecromancer e;
			e.position = GetMousePosition();
			sprites.push_back(e);*/
			Enem e;
			e.position = GetMousePosition();
			sprites.push_back(e);	
		}
		// update arr
		if (IsMouseButtonPressed(0)) {
			/*WizBarNecromancer e;
			e.position = GetMousePosition();
			sprites.push_back(e);*/
			Enem e;
			e.position = GetMousePosition();
			sprites.push_back(e);
		}

		// update contents
		for (size_t i = 0; i < sprites.size(); i++) {
			sprites[i].update();
		}

		// get rid of old enemies
		for (size_t i = 0; i < sprites.size(); i++) {
			if (sprites[i].position.x < -10 || sprites[i].position.x > w + 10 ||
				sprites[i].position.y < -20 || sprites[i].position.y > h + 10) {

				sprites.remove(i);
				std::cout << sprites.size() << std::endl;
			}
		}

		BeginDrawing();

		ClearBackground(WHITE);

		// draw
		for (size_t i = 0; i < sprites.size(); i++) {
			// sprites[i].draw();
			// std::cout << sprites.size() << std::endl;
			sprites[i].draw();
		}

		EndDrawing();

	}

	// UnloadTexture(sprite);

	CloseWindow();

	return 0;
}