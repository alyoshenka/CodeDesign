#pragma once
#include "Sprite.h"
class Button :
	public Sprite
{
public:

	bool isPressed;

	Button();

	Button(const std::string *filename, 
		const Vector2 & position, const  int cellCount = 1);
	~Button();

	void draw();
	void update();
};

