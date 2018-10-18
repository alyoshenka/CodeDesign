#include "Button.h"



Button::Button()
{
	activeCount = 2;
	activeCells = new Texture2D[activeCount];
}


Button::~Button()
{
	delete[] activeCells;
	// delete all?
}
