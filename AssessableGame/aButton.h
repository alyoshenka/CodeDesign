#pragma once
#include <string>
#include "raylib.h"

class aButton
{
public:

	float delayTime;
	float elapsedTime;
	bool isClicked;
	bool resetting;
	Texture2D upTexture;
	Texture2D downTexture;

	Rectangle bounds;

	aButton();
	aButton(const std::string up, const std::string down);
	~aButton();

	void update(Vector2 click);
	void draw();
};

