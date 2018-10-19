#pragma once
#include "WizBarEnemy.h"
class WizBarChort :
	public WizBarEnemy
{
public:
	WizBarChort();
	~WizBarChort();
	
	bool moveTo(const Vector2 &dest);
};

