#pragma once
#include "WizBarPlayer.h"
class WizBarWizard :
	public WizBarPlayer
{
public:

	float blastRadius;
	float blastTime;
	float elapsedTime = 0.0f;

	WizBarWizard();
	~WizBarWizard();

	bool moveTo(const Vector2 &dest);
	bool attack(Rectangle enemy);
};

