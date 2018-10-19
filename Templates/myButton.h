#pragma once
#include <string>
#include "raylib.h"
class myButton
{
public:

	float delayTime;
	float elapsedTime;
	bool isClicked;
	bool resetting;
	Texture2D upTexture;
	Texture2D downTexture;

	Rectangle bounds;

	myButton();
	myButton(const std::string up, const std::string down);
	~myButton();

	void update(Vector2 click);
	void draw();
};