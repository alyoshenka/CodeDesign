#include "tObjectPool.h"


template<typename T>
tObjectPool<T>::tObjectPool()
{
	// default
	freeCount = 100;
	// we haven't used any
	usedCount = 0;
	// set size
	free = new T[freeCount];
	// it's the same size
	used = new T[freeCount];
}

template<typename T>
tObjectPool<T>::tObjectPool(size_t initialCapacity)
{
	// default
	freeCount = initialCapacity;
	// we haven't used any
	usedCount = 0;
	// set size
	free = new T[freeCount];
	// it's the same size
	used = new T[freeCount];
}

template<typename T>
tObjectPool<T>::~tObjectPool()
{
	delete[] free;
	delete[] used;
}

template<typename T>
T * tObjectPool<T>::retrieve()
{
	// if nothing left
	if (freeCount <= 0) {
		return nullptr;
	}
	// otherwise
	else {
		// how does this work?
		// i return it yes, but I also need to move it between arrays

		// I don't know if this is the correct way to do this
		return free[freeCount - 1];

		// increment values
		freeCount--;
		usedCount++;
	}
	
}

template<typename T>
void tObjectPool<T>::recycle(T * obj)
{
	// iterate through free, find obj
	// take idx of obj, swap with last value in free
	// increment freecnt and usedcnt

	for (int i = 0; i < usedCount; i++) {
		if (used[i] == obj) {
			// swap out
			used[i] = used[usedCount - 1];
		}
	}

	freeCount++;
	usedCount--;
}

template<typename T>
size_t tObjectPool<T>::capacity()
{
	// this makes total capacity
	return freeCount + usedCount;
}
