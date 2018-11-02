#pragma once
class Singleton
{
private:
	// constructor
	Singleton();
	// prevent use
	Singleton(Singleton const&);
	void operator = (Singleton const&);

public:
	// other parts of code use this, so public
	static Singleton& GetInstance();
	// destructor
	~Singleton();

	// test
	int addInts(const int a, const int b);
};

