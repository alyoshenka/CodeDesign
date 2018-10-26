// tVector.h
#pragma once

#include <cassert>

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used (-1)
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:

	// initializes the vector's default values
	tVector()
	{
		arrSize = 0; // nothing used yet
		arrCapacity = 0; // seems good
		arr = new T[arrCapacity];
	}

	// overload
	tVector(size_t _cap)
	{
		arrSize = 0; // nothing used yet
		arrCapacity = _cap; // seems good
		arr = new T[arrCapacity];
	}

	// destroys the underlying array
	~tVector()
	{
		delete[] arr;
	}

	// returns a pointer to the underlying array
	T *data()
	{
		return arr; // right?
	}

	// resizes the vector to at least this many elements
	void reserve(size_t newCapacity)
	{
		// if smaller
		if (newCapacity < arrCapacity) {
			return;
		}

		// new array
		T * newArr = new T[newCapacity];
		// copy data over
		for (size_t i = 0; i <= arrSize; i++) {
			newArr[i] = arr[i];
		}
		// change class vals
		arrCapacity = newCapacity;
		// delete old arr
		delete[] arr;
		// set to new array
		arr = newArr;
	}

	// adds an element to the end of the vector
	void push_back(const T &value)
	{
		// if over, resize
		if (arrSize >= arrCapacity) {
			// reserve to new size
			reserve(arrCapacity * GROWTH_FACTOR + 1); // if 0
		}
		// add new element
		arr[arrSize] = value;
		// increment index
		arrSize++;

		// arrCapacity == 0 ? 1 : arrCapacity * GROWTH_FACTOR
	}

	// drops the last element of the vector
	void pop_back()
	{
		arrSize--; // all that is really needed
	}

	// returns the element at the given element
	T &at(size_t index)
	{
		// return val at idx
		if (index <= arrSize) {
			return arr[index];
		}
		// else return last value
		return arr[arrSize];
	}

	// returns the element at the given element (const)
	const T& at(size_t index) const
	{
		// assert index within vals
		if (index >= 0) {
			assert(index >= 0 && "Index must be >= 0");
		}
		if (index < arrSize) {
			assert(index < arrSize && "Index must be within array");
		}

		if (index <= arrSize) {
			return arr[index];
		}

	}

	// returns current number of elements
	size_t size() const
	{
		return arrSize;
	}

	// returns maximum number of elements we can store
	size_t capacity() const
	{
		return arrCapacity;
	}

	// overloaded constructor
	tVector(const tVector &vec)
	{
		// init vals
		arrSize = vec.arrSize;
		arrCapacity = vec.arrCapacity;
		arr = new T[arrCapacity];

		// copy over individually
		for (int i = 0; i <= vec.arrSize; i++) {
			// arr.push_back(vec[i]);
			arr[i] = vec.at(i);
			// arr.push_back(vec.at(i));
			// const T temp = vec.at(i);
			// arr[i] = vec.at(i);
			// arr[i] = vec.arr[i];
		}
		// arr = &vec;
	}

	// = overload
	tVector & operator = (const tVector & vec)
	{
		// init vals
		arrSize = vec.arrSize;
		arrCapacity = vec.arrCapacity;
		arr = new T[arrCapacity];

		// copy over individually
		for (int i = 0; i <= vec.arrSize; i++) {
			// arr[i] = vec.at(i); // no idea why at() doesn't work
			arr[i] = vec.at(i);
		}

		// or could use constructor overload
		return *this;
	}

	// [] overload
	T & operator [] (size_t index) {
		return arr[index];
	}

	// returns if empty
	bool empty() {
		return arrSize == 0;
	}

	// basically reserve without limits
	// resize arr, can shrink
	void resize(size_t newCapacity) {

		// new array
		T * newArr = new T[newCapacity];

		// change class vals
		arrCapacity = newCapacity;
		if (arrSize >= arrCapacity) {
			arrSize = arrCapacity - 1;
		}

		// copy data over
		for (size_t i = 0; i <= arrSize; i++) {
			newArr[i] = arr[i];
		}

		// delete old arr
		delete[] arr;
		// set to new array
		arr = newArr;
	}

	// capacity = size(+1)
	void shrink_to_fit() {
		arrCapacity = arrSize + 1; // anything else needed?
								   // +1 lets us continue to ise arrSize for indexed values
	}

	// clears arr
	void clear() {
		/*delete[] arr;
		arr = new T[arrCapacity];*/
		arrSize = 0;
	}

	// removes element
	void remove(size_t index) {

		// arr[index] = arr.at(arrSize);
		// not working???
		//arr[index] = arr[arrSize]; // removes
		//arrSize--;

		// removes and keeps order
		for (size_t i = index; i < arrSize; i++) {
			arr[i] = arr[i + 1];
		}
		arrSize--;
	}

};
