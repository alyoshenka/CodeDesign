#pragma once
#include "WizBarEnemy.h"
class WizBarNecromancer :
	public WizBarEnemy
{
public:
	WizBarNecromancer();
	~WizBarNecromancer();

	bool moveTo(const Vector2 &dest);
};

