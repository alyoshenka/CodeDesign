// tVector.h
#pragma once

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	tVector()                          // initializes the vector's default values
	{
		arrSize = 0; // nothing used yet
		arrCapacity = 10; // seems good
		arr = new T[arrCapacity];
	}

	~tVector()                         // destroys the underlying array
	{
		delete[] arr;
	}

	T *data()                          // returns a pointer to the underlying array
	{
		return arr; // right?
	}

	void reserve(size_t newCapacity)   // resizes the vector to at least this many elements
	{
		// if smaller
		if (newCapacity < arrCapacity) {
			return;
		}

		// new array
		T * newArr = new T[newCapacity];
		// copy data over
		for (int i = 0; i < arrSize; i++) {
			newArr[i] = arr[i];
		}
		// change class vals
		arrCapacity = newCapacity;
		// delete old arr
		delete[] arr;
		// set to new array
		arr = newArr;
	}

	void push_back(const T &value)     // adds an element to the end of the vector
	{
		// if over, resize
		if (arrSize >= arrCapacity) {
			// reserve to new size
			reserve(arrCapacity * 1.5 + 1); // if 0
		}
		// add new element
		arr[arrSize] = value;
		// increment index
		arrSize++;
	}

	void pop_back()                    // drops the last element of the vector
	{
		arrSize--; // all that is really needed
	}

	T &at(size_t index)               // returns the element at the given element
	{
		// return val at idx
		if (index <= arrSize) {
			return arr[index];
		}
		// else return last value
		return arr[arrSize];
	}

	const T& at(size_t index) const
	{
		if (index <= arrSize) {
			return arr[index];
		}
		// else return last value
		return arr[arrSize];
	}

	size_t size() const               // returns current number of elements
	{
		return arrSize;
	}

	size_t capacity() const            // returns maximum number of elements we can store
	{
		return arrCapacity;
	}

	tVector(const tVector &vec) // overloaded constructor
	{
		// init vals
		arrSize = vec.arrSize;
		arrCapacity = vec.arrCapacity;
		arr = new T[arrCapacity];

		// copy over individually
		for (int i = 0; i < vec.arrSize; i++) {
			// arr.push_back(vec[i]);
			arr[i] = vec.at(i);
			// arr.push_back(vec.at(i));
			// const T temp = vec.at(i);
			// arr[i] = vec.at(i);
			// arr[i] = vec.arr[i];
		}
		// arr = &vec;
	}

	tVector & operator = (const tVector & vec) // = overload
	{
		// init vals
		arrSize = vec.arrSize;
		arrCapacity = vec.arrCapacity;
		arr = new T[arrCapacity];

		// copy over individually
		for (int i = 0; i < vec.arrSize; i++) {
			// arr[i] = vec.at(i); // no idea why at() doesn't work
			arr[i] = vec.at(i);
		}

		// or could use constructor overload
	}

	// [] overload
	T & operator [] (size_t index){
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
		for (int i = 0; i < arrSize; i++) {
			newArr[i] = arr[i];
		}

		// delete old arr
		delete[] arr;
		// set to new array
		arr = newArr;
	}

	// capacity = size(+1)
	void shrink_to_fit() {
		arrCapacity = arrSize+1; // anything else needed?
		// +1 lets us continue to ise arrSize for indexed values
	}

	// clears arr
	void clear() {
		delete[] arr;
		arr = new T[arrCapacity];
	}

};

