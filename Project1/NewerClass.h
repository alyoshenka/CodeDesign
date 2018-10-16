#pragma once
#include "OriginalClass.h"
class NewerClass
{
public:
	int bsMyVal = 0;
	NewerClass(OriginalClass a);
	NewerClass();
	~NewerClass();
};

