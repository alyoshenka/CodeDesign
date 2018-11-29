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
// make adequate comments
// make fish move up and down (sin + cos)
// correct location of public vs privat variables
// change Fish position initialization
// there's gotta be a better way than making all your fish variables public
// randomizePos() vs just doing it in copy constructor
// would randomizing the position in the copy constructor really be that bad?
	// probably
// putting it in both initialization and copy constructor, make sure to take one out
// reasonably scale down enemy array size
// make sure to add fish size instead of multiplying by modifier
// pop messes up order
// why is initial fish spawn weird
// fish we can eat

int main() {

	{

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

	}

	// _CrtDumpMemoryLeaks();

	return 0;
}