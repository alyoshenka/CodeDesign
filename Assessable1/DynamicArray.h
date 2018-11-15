#pragma once
#include <iostream>

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
	void push_back(const T& val);
	// pop value off back
	void pop_back();
	// add value to front
	void push_front(const T& val);
	// pop value from front
	void pop_front();
	// add item at index
	void add(T item, size_t idx); 
	// was it removed successfully?
	bool remove(size_t idx);
	// preserves order
	bool removeOrdered(size_t idx);
	void resize(size_t newSize);
	// resize by growth factor if needed
	void resize();
	// clears but maintains size
	void clear();
	// returns arrSize
	size_t sizeInUse() const;

	// operator overload
	T& operator [] (size_t index);
	// const qualified
	const T& operator [] (size_t index) const;

	// sorting functions
	void bubbleSortAscending();
	void insertionSortAscending();
	void mergeSortDescending(int p, int r);
	void mergeDescending(int p, int q, int r);

	// for testing
	void show();
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
	// init vals
	arrSize = _arr.arrSize;
	arrCapacity = _arr.arrCapacity;
	arr = new T[arrCapacity];

	for (int i = 0; i < arrSize; i++) {
		arr[i] = _arr[i];
	}

	return *this;
}

template<typename T>
void DynamicArray<T>::add(T item, size_t idx)
{

	// increment size
	arrSize++;
		
	// if too small
	if (arrSize >= arrCapacity) {
		// make more space
		resize(arrSize);
	}

	// if in middle
	if (idx < arrSize) {
		// iterate through array
		for (int i = arrSize - 2; i >= idx; i--) {
			// move elements over
			arr[i+1] = arr[i];
		}
	}

	// put element in
	arr[idx] = item;

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
bool DynamicArray<T>::removeOrdered(size_t idx)
{
	// if invalid idx
	if (idx < 0 || idx >= arrSize) {
		return false;
	}

	// iterate through array
	for (int i = idx; i < arrSize; i++) {
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
	// newArr = arr;
	// copy data over
	for (int i = 0; i <= arrSize; i++) {
		newArr[i] = arr[i];
	}

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
size_t DynamicArray<T>::sizeInUse() const
{
	return arrSize;
}

template<typename T>
T & DynamicArray<T>::operator[](size_t index)
{
	return arr[index];
}

template<typename T>
const T & DynamicArray<T>::operator[](size_t index) const
{
	return arr[index];
}

template<typename T>
void DynamicArray<T>::bubbleSortAscending()
{
	for (int i = 0; i < arrSize; i++) {
		// int n = i;
		for (int n = 0; n < arrSize - i - 1; n++) {
			if (arr[n] > arr[n + 1]) {
				// swap
				T temp = arr[n + 1];
				arr[n + 1] = arr[n];
				arr[n] = temp;
			}
		}
	}
}

template<typename T>
void DynamicArray<T>::insertionSortAscending()
{
	for (int i = 0; i < arrSize; i++) {
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			T temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
		}
	}
}

template<typename T>
void DynamicArray<T>::mergeSortDescending(int p, int r)
{
	/*int p = 0;
	int r = arrSize - 1;*/
	int q = (p + r) / 2;

	// terminate loop
	if (q >= r || p > q) {
		return;
	}

	// int p = 0;
	// int r = arrSize - 1;
	mergeSortDescending(p, q);
	mergeSortDescending(q + 1, r);
	mergeDescending(p, q, r);
}

template<typename T>
void DynamicArray<T>::mergeDescending(int p, int q, int r)
{
	int leftEnd = q - p + 1;
	int rightEnd = r - q;

	T * L = new T[leftEnd];
	T * R = new T[rightEnd];

	for (int i = 0; i < leftEnd; i++) {
		L[i] = arr[p + i];
	}
	for (int j = 0; j < rightEnd; j++) {
		R[j] = arr[q + j + 1];
	}

	int i = 0;
	int j = 0;

	for (int k = p; k <= r; k++) {
		if (j >= rightEnd || (i < leftEnd and L[i] >= R[j])) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
	}

	delete[] L;
	delete[] R;
}

template<typename T>
void DynamicArray<T>::show()
{
	std::cout << "Array values" << std::endl;
	for (int i = 0; i < arrSize; i++) {
		std::cout << arr[i] << std::endl;
	}
	std::cout << "S: " << arrSize << std::endl;
	std::cout << "C: " << arrCapacity << std::endl;
	std::cout << std::endl;
}

template<typename T>
void DynamicArray<T>::push_back(const T & val)
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
void DynamicArray<T>::push_front(const T & val)
{
	// increment
	arrSize++;

	// if needed
	resize();

	// move everything forward
	for (int i = arrSize - 2; i >= 0; i--) {
		arr[i+1] = arr[i];
	}

	// put into array
	arr[0] = val;
}

template<typename T>
void DynamicArray<T>::pop_front()
{
	// keeps order
	removeOrdered(0);
}
