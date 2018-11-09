#include "raylib.h"
#include "Spritey.h"
#include <vector>
#include "Falling.h"
#include "Shootie.h"


Spritey * Falling::spriteMasters;
size_t Falling::spriteCount;

int main() {

	int w = 800;
	int h = 450;
	InitWindow(w, h, "fac");

	// init
	Falling::init();

	// our sprites
	std::vector<Spritey> sprites;

	// sprites are falling
	bool isFalling = false;
	Vector2 speed = { 0, 1 };

	// bullets
	Shootie bullets;

	SetTargetFPS(60);
	while (!WindowShouldClose()) {

		// add
		if (IsMouseButtonPressed(0)) {
			sprites.push_back(*Falling::getRandom());
		}

		// update
		if (IsMouseButtonPressed(1)) {
			isFalling = !isFalling;
		}

		// clone with new pos
		if (IsMouseButtonPressed(2)) {
			// clone all the sprites
			int max = sprites.size();
			for (int i = 0; i < max; i++) {
				Spritey * s = sprites[i].Clone();
				s->pos.x = sprites[i].pos.x + 20;
				sprites.push_back(*s);
			}
		}

		bullets.update();

		BeginDrawing();

		ClearBackground(WHITE);

		// draw
		for (int i = 0; i < sprites.size(); i++) {
			sprites[i].draw();
			if (isFalling) {
				sprites[i].translate(speed);
				// check
				if (sprites[i].pos.y > h) {
					sprites[i].pos.y = 0 - sprites[i].r1.height;
				}
			}

			// check collision with bullet
			for (int j = 0; j < bullets.maxIdx; j++) {
				if (CheckCollisionRecs(sprites[i].r1, bullets.projectiles[j])) {
					// make small
					if (sprites[i].r2.width > 10) {
						sprites[i].r2.width = sprites[i].r2.width / 2;
						sprites[i].r2.height = sprites[i].r2.height / 2;
					}
					else {
						// delete them both
						sprites[i] = sprites[sprites.size() - 1];
						sprites.pop_back();
					}
					// delete bullet
					bullets.pop(j);
				}
			}
		}

		bullets.draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}