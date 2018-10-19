#include "raylib.h"
#include "WizBarPlayer.h"
#include "WizBarWizard.h"
#include "WizBarBarbarian.h"

#include "WizBarEnemy.h"
#include "WizBarNecromancer.h"
#include "WizBarChort.h"

#include "Button2.h"

int main() {

	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Poly");

	bool pause = true;

	WizBarPlayer a;
	WizBarWizard b;
	WizBarBarbarian c;
	WizBarPlayer d;

	// declare array
	WizBarEnemy * enemies[10];
	// populate array
	for (int i = 0; i < 10; i++) {

		// 1 : 3
		if (GetRandomValue(0, 2) == 0) {
			enemies[i] = new WizBarNecromancer;
		}
		else {
			enemies[i] = new WizBarChort;
		}

		// set position
		enemies[i]->position.x = GetRandomValue(0, screenWidth);
		enemies[i]->position.y = GetRandomValue(0, screenHeight);
	}

	// Rectangle wizRect = {10, screenHeight - 60, wizButton.width, wizButton.height};
	// Rectangle barbRect = {screenWidth - 200, screenHeight - 60, barbButton.width, barbButton.height};
	// 0 = not chosen
	// 1 = wiz
	// 2 = barb
	int selection = 0;

	Button2 wizButton;
	wizButton.bounds = { 10.0f, screenHeight - 60.0f, (float)wizButton.upTexture.width,
		(float)wizButton.upTexture.height };
	Button2 barbButton("assets/red_button01.png", "assets/red_button10.png");
	barbButton.bounds = { screenWidth - 200.0f, wizButton.bounds.y,
		(float)barbButton.upTexture.width, (float)barbButton.upTexture.height };
	Button2 playerButton("assets/green_button00.png", "assets/green_button13.png");
	playerButton.bounds = {305.0f, wizButton.bounds.y, (float)wizButton.upTexture.width,
		(float)wizButton.upTexture.height };

	Vector2 tempPosition = { 0, 0 };

	while (!WindowShouldClose()) {

		// update a
		a.update();

		wizButton.update(GetMousePosition());
		barbButton.update(GetMousePosition());

		// wizard
		if (CheckCollisionPointRec(GetMousePosition(), wizButton.bounds) && IsMouseButtonPressed(0)) {
			selection = 1;
			// a = b; // copy constructor
			// delete a;
			tempPosition = a.position;
			a = b;
			// so he doesn't go back to upper left corner
			a.position = tempPosition;
			a.destination = tempPosition;
		}
		// barbarian
		if (CheckCollisionPointRec(GetMousePosition(), barbButton.bounds) && IsMouseButtonPressed(0)) {
			selection = 2;
			// a = c;
			// delete a;
			tempPosition = a.position;
			a = c;
			a.position = tempPosition;
			a.destination = tempPosition;
		}
		// player
		if (CheckCollisionPointRec(GetMousePosition(), playerButton.bounds) && IsMouseButtonPressed(0)) {
			selection = 2;
			tempPosition = a.position;
			a = d;
			a.position = tempPosition;
			a.destination = tempPosition;
		}

		// update enemies
		for (int i = 0; i < 10; i++) {
			enemies[i]->moveTo(a.position);
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);

		wizButton.draw(); // you can place player on buttons but whatever
		barbButton.draw();
		playerButton.draw();

		// draw enemies
		for (int i = 0; i < 10; i++) {
			enemies[i]->draw();
		}

		// draw players / friendly characters
		a.draw();

		// check collision with enemies & wizard
		for (int i = 0; i < 10; i++) {
			if (a.attack({ enemies[i]->position.x, enemies[i]->position.y, 8, 16 })) {
				enemies[i]->isActive = false;
			}			
		}

		EndDrawing();

	}

	
	// should be calling this but...
	// delete[] enemies;

	CloseWindow();

	return 0;
}

