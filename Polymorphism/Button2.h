#pragma once
#include <string>
#include "raylib.h"
class Button2
{
public:

	float delayTime;
	float elapsedTime;
	bool isClicked;
	bool resetting;
	Texture2D upTexture;
	Texture2D downTexture;

	Rectangle bounds;

	Button2();
	Button2(const std::string up, const std::string down);
	~Button2();

	void update(Vector2 click);
	void draw();
};
