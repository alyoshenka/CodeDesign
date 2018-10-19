#include <iostream>
#include "raylib.h"

template <typename T>
class gameObject
{
public:
	bool enabled;   // is this gameObject enabled?
	T * object;     // pointer to underlying instance of type T

	void update(float delta)
	{
		if (enabled) {
			std::cout << "Updating" << std::endl;
			object->update(delta);
		}		
	}

	void render()
	{
		if (enabled) {
			std::cout << "Rendering" << std::endl;
			object->draw();
		}		
	}

	gameObject() {

		enabled = false;
		object = new T();
		// not sure what goes here
	}

	~gameObject() {
		delete object;
	}

	void setPosition(const Vector2 & _pos) {
		object.position = _pos;
	}
};
