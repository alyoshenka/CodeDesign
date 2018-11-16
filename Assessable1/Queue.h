#pragma once
#include "DynamicArray.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

template<typename T>
class Queue {
	// data for queue
	DynamicArray<T> arr;
public:
	// constructor
	Queue();
	// overloaded constructor, initialized to count number of val
	Queue(size_t count, const T& val);
	// deconstructor
	~Queue();

	// add element to top
	void push(T& val);
	// drops top element
	void pop();
	// returns front element
	T& front();
	// const qualified
	const T& front() const;
	// returns back element
	T& back();
	// const qualified
	const T& back() const;
	// returns current number of elements
	size_t size() const;
	// true if queue is empty
	bool empty() const;
};

template<typename T>
Queue<T>::Queue()
{
	arr = DynamicArray<T>();
}

template<typename T>
Queue<T>::Queue(size_t count, const T & val)
{
	arr = DynamicArray<T>();
	// init values
	for (int i = 0; i < count; i++) {
		// add to arr
		arr.push_front(val);
	}
}

template<typename T>
Queue<T>::~Queue()
{
	// ??
}

template<typename T>
void Queue<T>::push(T & val)
{
	arr.push_back(val);
}

template<typename T>
void Queue<T>::pop()
{
	arr.pop_front();
}

template<typename T>
T & Queue<T>::front()
{
	return arr[0];
}

template<typename T>
const T & Queue<T>::front() const
{
	return arr[0];
}

template<typename T>
T & Queue<T>::back()
{
	return arr[ar.sizeInUse() - 1];
}

template<typename T>
const T & Queue<T>::back() const
{
	return arr[ar.sizeInUse() - 1];
}

template<typename T>
size_t Queue<T>::size() const
{
	return arr.sizeInUse();
}

template<typename T>
bool Queue<T>::empty() const
{
	return arr.sizeInUse() == 0;
}
