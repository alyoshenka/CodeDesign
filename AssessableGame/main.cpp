#include "raylib.h"
#include "menustate.h"

// To Do
// check for memory leaks
// make adequate comments
// make fish move up and down (sin + cos)
// also varying speeds?
// write data to high score file option in win state
// correct location of public vs privat variables
// should I use a factory or prototype class? yes I should
// update fish draw function to do different sizes
// should FishManager be a singleton? yes, make it so later
// fish copy constructor
// add more fish prototypes
// change Fish position initialization
// movement boundaries scaled to size
// arrSize init to 0
// there's gotta be a better way than making all your fish variables public
// randomizePos() vs just doing it in copy constructor
// would randomizing the position in the copy constructor really be that bad?
	// probably
// putting it in both initialization and copy constructor, make sure to take one out
// reasonably scale down enemy array size
// enemy.pop, player.shrink, player.grow
// grow in't working because of something with how i'm increasing it

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