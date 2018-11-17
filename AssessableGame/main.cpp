#include "raylib.h"
#include "menustate.h"

int main() {

	// window vars
	int w = 1000;
	int h = 500;

	// init
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

		// update state
		stateInstance->update();

		BeginDrawing();

		ClearBackground(BLACK); // just in case

		stateInstance->draw();

		EndDrawing();
	}

	// clean up
	delete stateInstance;

	CloseWindow();

	return 0;
}