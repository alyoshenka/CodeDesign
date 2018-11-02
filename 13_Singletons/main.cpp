#include "raylib.h"
#include "Singleton.h"
#include <iostream>
#include "GameState.h"
#include "Game.h"

int main() {

	std::cout << Singleton::GetInstance().addInts(5, 2) << std::endl;

	

	InitWindow(800, 450, "Singleton"); // figure out nums
		
	int w = Game::GetInstance().windowW;
	int h = Game::GetInstance().windowH;
	
	SetTargetFPS(60);
	while (!WindowShouldClose()) {

		// Game::GetInstance().update();

		BeginDrawing();

		ClearBackground(WHITE);

		Game::GetInstance().go();

		EndDrawing();

	}

	CloseWindow();

	return 0;
}