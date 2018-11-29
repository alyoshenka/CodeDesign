#pragma once

// check for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif


template <typename T>
class ObjectPool
{
public:

	size_t currentCapacity;

	ObjectPool();                       // default initializes the object pool
	ObjectPool(size_t initialCapacity); // initializes the pool to have a set number of objects
	~ObjectPool();                      // destroys all objects

	T* pool;                            // all objects stored in the pool
	bool* free;                         // indicates whether an object is available

	T* retrieve();                      // returns a pointer to an object that will be used (returns null if none available)
	void recycle(T* obj);               // accepts a pointer that can be used in the future

	size_t capacity();
};

template<typename T>
ObjectPool<T>::ObjectPool() : ObjectPool(50)
{
}

template<typename T>
ObjectPool<T>::ObjectPool(size_t initialCapacity)
{
	currentCapacity = initialCapacity;
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
		if (&pool[i] == obj) {
			free[i] = false;
			return;
		}
	}
}

template<typename T>
size_t ObjectPool<T>::capacity()
{
	return currentCapacity;
}

