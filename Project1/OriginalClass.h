#pragma once
#include "NewerClass.h"

class OriginalClass
{
public:
	int myVal = 10;
	OriginalClass(NewerClass a);

	OriginalClass();
	~OriginalClass();
};

