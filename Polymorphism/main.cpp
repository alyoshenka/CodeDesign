#include "raylib.h"
#include "WizBarPlayer.h"
#include "WizBarWizard.h"
#include "WizBarBarbarian.h"

#include "WizBarEnemy.h"
#include "WizBarNecromancer.h"
#include "WizBarChort.h"

#include "Button2.h"

#include <vector>
#include <iterator>
#include <iostream>

// std::vector<WizBarEnemy> split();
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
	// WizBarEnemy * enemies[10];

	// number of enemies by default
	int defaultEnemies = 10;

	// enemies vector
	std::vector<WizBarEnemy*> enemies;

	// instantiate enemies
	// WizBarNecromancer necro;
	// WizBarChort chort;
	WizBarEnemy *enem;
	
	// populate enemies
	for (int i = 0; i < defaultEnemies; i++) {
		// randomly choose type
		if (GetRandomValue(0, 2) == 0) {
			enem = new WizBarNecromancer;
			enemies.push_back(enem);
		}
		else {
			enem = new WizBarChort;
			enemies.push_back(enem);
		}
	}

	// assign random position
	for (auto enemItr = enemies.begin(); enemItr != enemies.end(); enemItr++) {
		(*enemItr)->position.x = GetRandomValue(0, screenWidth); 
		(*enemItr)->position.y = GetRandomValue(0, screenHeight);
	}

	// + / - enemies
	Button2 addEnemy("assets/blue_button07.png", "assets/blue_button06.png");
	addEnemy.bounds = { 10.0f, 10.0f,(float)addEnemy.upTexture.width,
		(float)addEnemy.upTexture.height };
	Button2 subtractEnemy("assets/green_button07.png", "assets/green_button06.png");
	subtractEnemy.bounds = { 740.0f, 10.0f, (float)subtractEnemy.upTexture.width,
		(float)subtractEnemy.upTexture.height };

	// test
	// WizBarEnemy test;
	// WizBarNecromancer test1;
	// WizBarChort test2;

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

	Button2 randomize("assets/yellow_button00.png", "assets/yellow_button13.png");
	randomize.bounds = {305.0f, 10.0f, (float)randomize.upTexture.width,
		(float)randomize.upTexture.height };


	// ui sizing
	int offset = 10;
	int size = 30;

	Vector2 tempPosition = { 0, 0 };

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		// ideally:
		// check for click
		// if click -> check position
		// if match -> do thing

		// in if statement?
		// yes, later
		wizButton.update(GetMousePosition());
		barbButton.update(GetMousePosition());
		playerButton.update(GetMousePosition());
		addEnemy.update(GetMousePosition());
		subtractEnemy.update(GetMousePosition());
		randomize.update(GetMousePosition());

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
		 else if (CheckCollisionPointRec(GetMousePosition(), barbButton.bounds) && IsMouseButtonPressed(0)) {
			selection = 2;
			// a = c;
			// delete a;
			tempPosition = a.position;
			a = c;
			a.position = tempPosition;
			a.destination = tempPosition;
		}
		// player
		else if (CheckCollisionPointRec(GetMousePosition(), playerButton.bounds) && IsMouseButtonPressed(0)) {
			selection = 2;
			tempPosition = a.position;
			a = d;
			a.position = tempPosition;
			a.destination = tempPosition;
		}
		// +
		else if (CheckCollisionPointRec(GetMousePosition(), addEnemy.bounds) && IsMouseButtonPressed(0)) {
			// randomly choose type
			if (GetRandomValue(0, 4) == 0) {
				enem = new WizBarNecromancer;
				enem->position.x = GetRandomValue(0, screenWidth);
				enem->position.y = GetRandomValue(0, screenHeight);
				enemies.push_back(enem);
			}
			else {
				enem = new WizBarChort;
				enemies.push_back(enem);
				enem->position.x = GetRandomValue(0, screenWidth);
				enem->position.y = GetRandomValue(0, screenHeight);
			}
			// more enemies
			defaultEnemies++;
		}
		// -
		else if (CheckCollisionPointRec(GetMousePosition(), subtractEnemy.bounds) && IsMouseButtonPressed(0)) {
			// take enemy
			// delete last or random?
			// delete on collision/ hit
			// random for now
			int rand = GetRandomValue(0, defaultEnemies - 1);
			int idx = 0;
			// search for idx
			for (auto enemItr = enemies.begin(); enemItr != enemies.end(); enemItr++) {
				if (idx == rand) {
					enemies.pop_back();
					break;
				}
				idx++;
			}
			defaultEnemies--;
		}
		// randomize
		else if (CheckCollisionPointRec(GetMousePosition(), randomize.bounds) && IsMouseButtonPressed(0)) {
			for (auto enemy : enemies) {
				enemy->position.x = GetRandomValue(0, screenWidth);
				enemy->position.y = GetRandomValue(0, screenHeight);
			}
		}
		// if not on button
		else {
			// update a
			a.update();
		}

		// move enemies
		for (auto enemItr = enemies.begin(); enemItr != enemies.end(); enemItr++) {
			// move towards player
			(*enemItr)->moveTo(a.position);
			// std::cout << "moveTo" << std::endl;
		}

		// wizard enemy attack collider
		for (auto enemItr = enemies.begin(); enemItr != enemies.end(); enemItr++) {
			// not good way to do it I know
			if (a.attack({ (*enemItr)->position.x, (*enemItr)->position.x, 8, 16 })) {
				enemies.pop_back();
			}
		}


		BeginDrawing();

		ClearBackground(RAYWHITE);
		
		// draw buttons
		wizButton.draw(); // you can place player on buttons but whatever
		DrawText("Wizard", wizButton.bounds.x + offset, wizButton.bounds.y + offset, size, BLACK);
		barbButton.draw();
		DrawText("Barbarian", barbButton.bounds.x + offset, barbButton.bounds.y + offset, size, BLACK);
		playerButton.draw();
		DrawText("Elf", playerButton.bounds.x + offset, playerButton.bounds.y + offset, size, BLACK);

		// +- buttons
		addEnemy.draw();
		DrawText("+", addEnemy.bounds.x + offset, addEnemy.bounds.y + offset * 0.5, size * 1.5, BLACK);
		subtractEnemy.draw();
		DrawText("-", subtractEnemy.bounds.x + offset, subtractEnemy.bounds.y + offset * 0.5, size * 1.5, BLACK);

		// randomize
		randomize.draw();
		DrawText("Randomize", randomize.bounds.x + offset, randomize.bounds.y + offset, size, BLACK);

		// draw enemies
		for (auto enemItr = enemies.begin(); enemItr != enemies.end(); enemItr++) {
			// move towards player
			(*enemItr)->draw();
			// std::cout << "draw" << std::endl;
		}

		// draw players / friendly characters
		a.draw();

		// check collision with enemies & wizard
		/*for (int i = 0; i < 10; i++) {
			if (a.attack({ enemies[i]->position.x, enemies[i]->position.y, 8, 16 })) {
				enemies[i]->isActive = false;
			}			
		}*/

		// test
		// test.draw();

		EndDrawing();

	}

	
	// should be calling this but...
	// delete[] enemies;

	CloseWindow();

	return 0;
}

