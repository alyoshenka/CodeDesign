#pragma once

// reorganize functions
// check resize for index being 1 off
// better way than calling resize() each time?
// check deconstructor

template <typename T>
class DynamicArray {

	// how much it grows each time it is needed
	const static size_t GROWTH_FACTOR = 2;
	
	// array
	T * arr;
	// amount of array used
	size_t arrSize;
	// amount of array available
	size_t arrCapacity;

public:

	int size;

	DynamicArray();
	~DynamicArray();

	DynamicArray(const DynamicArray& _arr);
	DynamicArray& operator = (const DynamicArray& _arr);

	// add value to back
	void push_back(T& val);
	// pop value off back
	void pop_back();
	// add value to front
	void push_front(T& val);
	// pop value from front
	void pop_front();

	void add(T item, size_t idx); // make work for more than one item
								  // was it removed successfully?
	bool remove(size_t idx);
	bool removedOrdered(size_t idx);
	void resize(size_t newSize);
	// resize by growth factor if needed
	void resize();
	// clears but maintains size
	void clear();
};

template<typename T>
DynamicArray<T>::DynamicArray()
{
	arrSize = 0;
	arrCapacity = 1;
	arr = new T[arrCapacity];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {

	delete[] arr;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray & _arr)
{
	arr = new T[arrCapacity];
	arrSize = _arr.arrSize;
	arrCapacity = _arr.arrCapacity;
	
	for (int i = 0; i < arrSize; i++) {
		arr[i] = _arr[i];
	}
}

template<typename T>
DynamicArray<T> & DynamicArray<T>::operator=(const DynamicArray & _arr)
{
	// same as copy constructor
	// is this right?
	// change so I'm not reusing code

	arr = new T[arrCapacity];
	arrSize = _arr.arrSize;
	arrCapacity = _arr.arrCapacity;

	for (int i = 0; i < arrSize; i++) {
		arr[i] = _arr[i];
	}
}

template<typename T>
void DynamicArray<T>::add(T item, size_t idx)
{
	// TEST 
		
	// if too small
	if (arrSize >= arrCapacity) {
		// make more space
		resize(arrCapacity * GROWTH_FACTOR);
	}

	// if in middle
	if (idx < arrSize) {
		// iterate through array
		for (int i = idx; i < arrSize; i++) {
			// move elements over
			arr[i] = arr[i + 1];
		}
	}

	// put element in
	arr[idx] = item;

	// increment size
	arrSize++;

}

template<typename T>
bool DynamicArray<T>::remove(size_t idx)
{
	// if invalid index
	if (idx < 0 || idx >= arrSize) {
		return false;
	}

	// index value = last value in array
	arr[idx] = arr[arrSize - 1];
	// last value cut off
	arrSize--;

	// it worked
	return true;
}

template<typename T>
bool DynamicArray<T>::removedOrdered(size_t idx)
{
	// if invalid idx
	if (idx < 0 || idx >= arrSize) {
		return false;
	}

	// iterate through array
	for (int i = idx; idx < arrSize; idx++) {
		// move each element back
		arr[i] = arr[i + 1];
	}

	// change size
	arrSize--;
}

template<typename T>
void DynamicArray<T>::resize(size_t newCapacity)
{
	// it is probably best not to make a new array, but I'm going to
	// ultimately, find a better way to do this

	// new array
	T * newArr = new T[newCapacity];

	// change vals
	arrCapacity = newCapacity;
	// arrSize shouldn't need to be changed

	// copy data over
	newArr = arr;

	// delete old arr
	delete[] arr;

	// set to new array
	arr = newArr;

}

template<typename T>
void DynamicArray<T>::resize()
{
	if (arrSize >= arrCapacity) {
		resize(arrCapacity * GROWTH_FACTOR);
	}	
}

template<typename T>
void DynamicArray<T>::clear()
{
	// one or the other until I figure out the right way

	/*for (int i = 0; i < arrSize; i++) {
		arr[i] = nullptr;
	}*/

	// doesn't free up memory, but does have functionality

	arrSize = 0;
}

template<typename T>
void DynamicArray<T>::push_back(T & val)
{
	// if needed
	resize();
	// add to array
	arr[arrSize] = val;
	// increment size
	arrSize++;
}

template<typename T>
void DynamicArray<T>::pop_back()
{
	// take away one
	arrSize--;
}

template<typename T>
void DynamicArray<T>::push_front(T & val)
{
	// if needed
	resize();

	// move everything forward
	for (int i = 0; i < arrSize; i++) {
		arr[i] = arr[i + 1];
	}

	// put into array
	arr[0] = val;

	// increment
	arrSize++;
}

template<typename T>
void DynamicArray<T>::pop_front()
{
	// keeps order
	this.removeOrdered(0);
}
