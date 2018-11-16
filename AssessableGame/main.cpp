#include "raylib.h"
#include "menustate.h"

int main() {

	int w = 1000;
	int h = 500;

	InitWindow(w, h, "OctoAdventure");
	SetTargetFPS(60);

	gamestate * stateInstance = new menustate();
	GameStates currentState = MENU;

	while (!WindowShouldClose()) {

		// go to next state
		GameStates nextState = stateInstance->next();
		// if different state
		if (nextState != currentState) {
			// get new one
			delete stateInstance;
			// set up new one
			setupGameState(stateInstance, nextState);
			// make new = current
			currentState = nextState;
			continue;
		}

		stateInstance->update();

		BeginDrawing();

		ClearBackground(BLACK); // just in case

		stateInstance->draw();

		EndDrawing();
	}

	delete stateInstance;

	CloseWindow();

	return 0;
}