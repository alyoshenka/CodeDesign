#include "Singleton.h"



Singleton::Singleton()
{
}


Singleton::~Singleton()
{
}

void Singleton::operator = (Singleton const&) {
	// don't do anything
}

Singleton & Singleton::GetInstance() {
	static Singleton instance;
	return instance;
}

int Singleton::addInts(const int a, const int b) {
	return a + b;
}
