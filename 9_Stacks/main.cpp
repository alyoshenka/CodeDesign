#include "tStack.h"
#include "Spell.h"
#include <iostream>
#include "raylib.h"
#include <string>

// could be implemented with enum spellType

int main() {
	
	int h = 450;
	int w = 800;
	InitWindow(w, h, "SPELLS");

	// spell modifiers
	Spell water;
	water.color = BLUE;
	water.speed = 10.0f;

	water.damage = 0;
	water.size = 0;

	Spell fire;
	fire.color = RED;
	fire.damage = 10;

	fire.size = 0;
	fire.speed = 0;

	Spell earth;
	earth.color = GREEN;
	earth.size = 10;
	earth.speed = -10;

	earth.damage = 0;

	Spell lightning; // not sure yet
	lightning.color = YELLOW;
	lightning.size = 10;

	lightning.speed = 0;
	lightning.damage = 0;
	

	Spell defSpell{ GRAY, 10, 10, 10 };
	Vector2 position = { 600.0f, 100.0f };
	Color c = BLACK;

	tStack<Spell> mySpell;

	// UI
	std::string combos[5];
	Spell colors[5];

	size_t idx = 0;

	bool showSpell = true; // not really needed
	// bool startSpell = false;

	int direction = 1;

	SetTargetFPS(60);
	while (!WindowShouldClose()) {

		// add
		if(IsKeyPressed(KEY_ONE) && idx < 5){
			mySpell.push(water);
			combos[idx] = "water";
			colors[idx] = water;

			// cancel
			if (idx > 0 && colors[idx - 1] == fire) {
				colors[idx - 1].cancel();
				colors[idx].cancel();
			}

			idx++;
		}
		if (IsKeyPressed(KEY_TWO) && idx < 5) {
			mySpell.push(fire);
			combos[idx] = "fire";
			colors[idx] = fire;

			// cancel
			if (idx > 0 && colors[idx - 1] == water) {
				colors[idx - 1].cancel();
				colors[idx].cancel();
			}
			idx++;
		}
		if (IsKeyPressed(KEY_THREE) && idx < 5) {
			mySpell.push(earth);
			combos[idx] = "earth";
			colors[idx] = earth;

			// cancel
			if (idx > 0 && colors[idx - 1] == lightning) {
				colors[idx - 1].cancel();
				colors[idx].cancel();
			}

			idx++;
		}
		if (IsKeyPressed(KEY_FOUR) && idx < 5) {
			mySpell.push(earth);
			combos[idx] = "lightning";
			colors[idx] = lightning;

			// cancel
			if (idx > 0 && colors[idx - 1] == earth) {
				colors[idx - 1].cancel();
				colors[idx].cancel();
			}

			idx++;
		}

		// spell
		if (showSpell) {

			position.y += direction * defSpell.speed;

			if (position.y > 400) {
				direction = -1;
				position.y = 400;
			}
			if (position.y < 50) {
				direction = 1;
				position.y = 50;
			}			

		}

		// show spell
		if (IsMouseButtonPressed(1)) {
			// swap true / false
			showSpell = showSpell ? false : true;
		}

		// make spell
		if (IsMouseButtonPressed(0)) {
			for (size_t i = 0; i < mySpell.size(); i++) {
				if (colors[i].active) { // should be using stack here
					defSpell.add(mySpell.top());
				}
				mySpell.pop();
			}
			if (idx > 0) {
				c = colors[idx - 1].color;
			}			
			idx = 0;
		}

		BeginDrawing();

		// show UI
		for (size_t i = 0; i < idx; i++) {
			DrawRectangle(20, i * 30 + 20, 60, 30, colors[i].color);
			DrawText(combos[i].c_str(), 25, i * 30 + 25, 15, BLACK);
		}

		// show spell
		if (showSpell) {
			DrawCircleV(position, defSpell.size, c);
		}

		// directions
		DrawText("1, 2, 3, and 4 to add water, fire, earth, or lightning", 150, 30, 15, BLACK);
		DrawText("left mouse button to combine spells", 150, 60, 15, BLACK);
		DrawText("right mouse button to toggle showing spell", 150, 90, 15, BLACK);

		ClearBackground(WHITE);

		EndDrawing();
	}

	CloseWindow();

	// system("pause");
	return 0;
}