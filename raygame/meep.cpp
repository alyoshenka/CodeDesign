#include "meep.h"

meep::meep()
{
	texture = LoadTexture("assets/cloud.png");
	
	enabled = false;
	position = { 0, 0 };
	// mainWeapon = nullptr;
	holdingWeapon = false;

	dTexture = new Texture2D(texture);
	if (dTexture == nullptr) {
		std::cout << "Error: out of memory" << std::endl;
		exit(1);
	}
}

// because CONSTRUCTOR CHAINING
meep::meep(bool _enabled) : meep() {

	enabled = _enabled;
}

meep::~meep()
{
	UnloadTexture(texture);

	UnloadTexture(*dTexture);
	delete dTexture;
	delete playerControlled;
}

void meep::refresh() {
	if (enabled) {
		// keyboard input
		if (IsKeyDown(KEY_D)) {
			position.x++;
		}
		if (IsKeyDown(KEY_A)) {
			position.x--;
		}
		if (IsKeyDown(KEY_W)) {
			position.y--;
		}
		if (IsKeyDown(KEY_S)) {
			position.y++;
		}

		DrawTexture(texture, position.x, position.y, WHITE);

		// weapon
		if (holdingWeapon) {
			mainWeapon.draw(position.x - 10, position.y);
		}
	}
}

void meep::giveWeapon(item weapon) {
	mainWeapon = weapon;
	holdingWeapon = true;
}


