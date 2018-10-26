#pragma once
#include "raylib.h"

struct Spell {
	Color color = GRAY;
	float speed = 0.0f;
	int damage = 0;
	int size = 0;
	bool active = true;

	// add spell to existing spell
	void add(Spell s) {
		// change color
		// color = s.color;
		speed += s.speed;
		damage += s.damage;
		size += s.size;

		if (speed < 0) {
			speed = 0;
		}
		if (damage < 0) {
			damage = 0;
		}
		if (size < 0) {
			size = 0;
		}
	}

	// == overload
	bool operator == (Spell s){
		if (speed == s.speed && damage == s.damage &&
			size == s.size && color.r == s.color.r && 
			color.g == s.color.g && color.b == s.color.b &&
			color.a == s.color.a) {

			return true;
		}
		// else
		return false;
	}

	// cancels 
	void cancel() {
		color = GRAY;
		active = false;
	}
};