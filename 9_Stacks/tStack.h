// tStack.h
#pragma once
#include "tVector.h"

template <typename T>
class tStack
{
	tVector<T> vec;                     // contains the data for a stack
	// capacity
	size_t cap;

public:
	tStack();                           // initializes the stack's default values
	// overload
	tStack(size_t _cap);
	// deconstructor
	// ~tStack();

	void push(const T& value);          // adds an element to the top of the Stack
	void pop();                         // drops the top-most element of the Stack

	T& top();                           // returns the top-most element at the given element

	size_t size() const;                // returns current number of elements

	// const qualified top
	const T & top() const;

	// const isEmpty
	bool empty() const;
	
};


// definitions

template <typename T>
tStack<T>::tStack() {
	// vec = new tVector<T>; // is this ok??
	cap = 5;
	vec = tVector<T>(cap);
}

template <typename T>
tStack<T>::tStack(size_t _cap) {
	// vec = new tVector<T>; // is this ok??
	cap = _cap;
	vec = tVector<T>(cap);
}

//template <typename T>
//tStack<T>::~tStack() {
//	// delete vec;
//}

template <typename T>
void tStack<T>::push(const T & value) {
	if (vec.size() < cap) {
		vec.push_back(value);
	}
	// else error
}

template <typename T>
void tStack<T>::pop() {
	vec.pop_back();
}

template <typename T>
T & tStack<T>::top() {
	return vec[vec.size()-1];
}

template <typename T>
size_t tStack<T>::size() const
{
	return vec.size();
}

template <typename T>
const T & tStack<T>::top() const {
	return vec[arrSize]; // works??
}

template <typename T>
bool tStack<T>::empty() const {
	return vec.empty(); // is this const?
}
