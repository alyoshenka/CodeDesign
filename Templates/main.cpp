#include <iostream>
#include "Templates.h"
#include "raylib.h"
#include "Ninja.h"
#include "gameObject.h"
#include "Soldier.h"
#include "myButton.h"

int main() {

	std::cout << "Min Max" << std::endl;
	std::cout << min<int>(4, 7) << std::endl;
	std::cout << max<float>(5.02f, 10) << std::endl;

	InitWindow(800, 450, "Templates");

	gameObject <Ninja> myNinja;
	gameObject <Soldier> mySoldier;
	myNinja.enabled = true;
	mySoldier.enabled = true;

	myButton ninjaButton;
	ninjaButton.bounds.x = 10;
	ninjaButton.bounds.y = 350;

	myButton soldierButton;
	soldierButton.bounds.x = 600;
	soldierButton.bounds.y = ninjaButton.bounds.y;

	while (!WindowShouldClose()) {

		myNinja.update(GetFrameTime());
		mySoldier.update(GetFrameTime());

		ninjaButton.update(GetMousePosition());
		soldierButton.update(GetMousePosition());

		if (ninjaButton.resetting) {
			if (myNinja.enabled) {
				myNinja.enabled = false;
			}
			else {
				myNinja.enabled = true;
			}
		}
		if (soldierButton.resetting) {
			if (mySoldier.enabled) {
				mySoldier.enabled = false;
			}
			else {
				mySoldier.enabled = true;
			}			
		}

		BeginDrawing();

		ClearBackground(WHITE);

		myNinja.render();
		mySoldier.render();
		
		ninjaButton.draw();
		soldierButton.draw();

		EndDrawing();
	}


	CloseWindow();

	return 0;
}