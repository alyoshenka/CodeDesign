#include "raylib.h"
#include "menustate.h"

// check for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

// To Do
// check for memory leaks
// check on unloading fish prototypes (mem leak)

int main() {

	{

	// window vars
	int w = 1000;
	int h = 500;

	// init
	InitWindow(w, h, "FishyGame");
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

	}

	// _CrtDumpMemoryLeaks();

	return 0;
}