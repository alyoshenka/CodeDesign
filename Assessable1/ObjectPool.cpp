#include "ObjectPool.h"
 
template<typename T>
ObjectPool<T>::ObjectPool() : ObjectPool(50)
{
}

template<typename T>
ObjectPool<T>::ObjectPool(size_t initialCapacity)
{
	pool = new T[initialCapacity];
	free = new bool[initialCapacity];
	// init all vals to unused
	for (int i = 0; i < initialCapacity; i++) {
		free[i] = true;
	}
}

template<typename T>
ObjectPool<T>::~ObjectPool()
{
	delete[] pool;
	delete[] free;
}

template<typename T>
T * ObjectPool<T>::retrieve()
{
	// iterate through free and return first true
	for (int i = 0; i < capacity(); i++) {
		if (free[i]) {
			return pool[i];
		}
	}
	// nothing free
	return nullptr;
}

template<typename T>
void ObjectPool<T>::recycle(T * obj)
{
	for (int i = 0; i < capacity(); i++) {
		if (pool[i] == obj) {
			free[i] = true;
			return;
		}
	}
}

template<typename T>
size_t ObjectPool<T>::capacity()
{
	size_t count = 0;
	T current = pool[0];
	while (current != nullptr) {
		current = pool[++count];
	}
	return count;
}
