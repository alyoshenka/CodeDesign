#pragma once
#include "DynamicArray.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

template <typename T>
class Stack {
	// contains data for stack
	DynamicArray<T> arr;
public:
	// initializes default values
	Stack();
	~Stack();

	// adds element to top
	void push(const T& val);
	// drops top element
	void pop();
	// returns top element
	T& top();
	// const qualified version
	const T& top() const;
	// returns nuymber of elements
	size_t size() const;
	// true if stack is empty
	bool empty() const;
};

template<typename T>
Stack<T>::Stack()
{
	arr = DynamicArray<T>();
}

template<typename T>
Stack<T>::~Stack()
{
	// delete ar
	// should I call the deconstructor??
}

template<typename T>
void Stack<T>::push(const T & val)
{
	arr.push_front(val);
}

template<typename T>
void Stack<T>::pop()
{
	// 0 = first element
	arr.removeOrdered(0);
}

template<typename T>
T & Stack<T>::top()
{
	return arr[0];
}

template<typename T>
const T & Stack<T>::top() const
{
	// TODO: insert return statement here
}

template<typename T>
size_t Stack<T>::size() const
{
	return arr.sizeInUse();
}

template<typename T>
bool Stack<T>::empty() const
{
	return arr.sizeInUse() == 0;
}
