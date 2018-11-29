#include "LinkedList.h"
#include "DynamicArray.h"
#include "Stack.h"
#include "Queue.h"
#include "ObjectPool.h"
#include <iostream>
#include <list>

// check for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif


int main() {

	// true == 1

	// put into it's own scope to get rid of memory leaks
	{
		// expected values are commented and printed for easy
		// checks with actual output values

		std::cout << "Alexi Most, Prog 2020" << std::endl;
		std::cout << "Classes are separated by labels \nand "
			"expected values are printed \nfor easy checking. " << std::endl;

		std::cout << std::endl;
		std::cout << "Linked List" << std::endl;

		LinkedList<int> list1;
		std::cout << "0=" << list1.count() << std::endl; // 0
		std::cout << "1=" << list1.empty() << std::endl; // 1
		list1.pushFront(1);
		list1.pushFront(2);
		list1.pushFront(3);
		list1.pushFront(4);
		list1.pushFront(5);

		std::cout << "5=" << list1.first() << std::endl; // 5
		std::cout << "1=" << list1.last() << std::endl; // 1
		std::cout << "5=" << list1.count() << std::endl; // 5
		std::cout << "0=" << list1.empty() << std::endl; // 0
		list1.popFront();
		list1.popBack();
		std::cout << "4=" << list1.first() << std::endl; // 4
		std::cout << "2=" << list1.last() << std::endl; // 2

		std::cout << std::endl;

		LinkedList<int>::iterator itr = list1.begin();
		LinkedList<int>::iterator itr2 = list1.end();
		// they should both be null
		std::cout << "0=" << (itr == itr2) << std::endl; // 0

		std::cout << std::endl;

		// check for correct iteration through list
		for (auto it = list1.begin(); it != list1.end(); it++) { // 432
			std::cout << (*it) << std::endl;
		}

		std::cout << std::endl;

		LinkedList<int> list2;
		std::cout << "1=" << list2.empty() << std::endl; // 1 empty = true
		list2.resize(5);
		std::cout << "0=" << list2.empty() << std::endl; // 0 empty = false

		// this doesn't work, but there should be a way to iterate backwards
		//for (auto it = list1.end(); it != list1.begin(); it--) { // 234
		//	std::cout << (*it) << std::endl;
		//}

		std::cout << std::endl;
		std::cout << "Dynamic Array" << std::endl;

		DynamicArray<int> arr1;
		arr1.push_front(7);
		arr1.push_front(6);
		arr1.push_back(8);
		arr1.push_back(9);
		arr1.push_front(5);
		arr1.add(10, 3);
		arr1.show(); // 5 6 7 10 8 9 
		arr1.remove(2);
		arr1.show(); // 5 6 9 10 8
		arr1.removeOrdered(2);
		arr1.show(); // 5 6 10 8
		arr1.clear();
		arr1.show(); // nothing

		std::cout << std::endl;

		DynamicArray<int> arr2;
		arr2.push_back(4);
		arr2.push_back(5);
		arr2.push_back(3);
		arr2.push_back(1);
		arr2.push_back(2);
		arr2.push_back(6);
		arr2.bubbleSortAscending();
		std::cout << "Bubble sort ascending" << std::endl;
		arr2.show();
		std::cout << "Merge sort descending" << std::endl;
		arr2.mergeSortDescending(0, arr2.sizeInUse() - 1);
		arr2.show();
		std::cout << "Insertion sort ascending" << std::endl;
		arr2.insertionSortAscending();
		arr2.show();

		std::cout << "Stack" << std::endl;

		Stack<int> stack1;
		std::cout << "1=" << stack1.empty() << std::endl; // 1
		stack1.push(3);
		stack1.push(2);
		stack1.push(1);
		std::cout << "1=" << stack1.top() << std::endl; // 1
		std::cout << "3=" << stack1.size() << std::endl; // 3
		stack1.pop();
		std::cout << "2=" << stack1.top() << std::endl; // 2
		std::cout << "2=" << stack1.size() << std::endl; // 2

		std::cout << std::endl;
		std::cout << "Queue" << std::endl;

		Queue<int> queue1(5, 40);
		std::cout << "0=" << queue1.empty() << std::endl; // 0
		std::cout << "5=" << queue1.size() << std::endl; // 5
		std::cout << "40=" << queue1.front() << std::endl; // 40
		queue1.pop();
		std::cout << "4=" << queue1.size() << std::endl; // 4

		std::cout << "\nObject Pool" << std::endl;

		ObjectPool<int> pool1(5);
		// put values into pool
		for (int i = 0; i < pool1.capacity(); i++) {
			if (pool1.free[i]) {
				pool1.pool[i] = i + 1;
			}
		}
		// print values
		std::cout << "5=" << pool1.capacity() << std::endl; // 5
		for (int i = 0; i < pool1.capacity(); i++) {
			if (pool1.free[i]) {
				std::cout << pool1.pool[i] << " "; // 1-5
			}			
		}
		std::cout << std::endl;
		// recycle 2
		pool1.recycle(&(pool1.pool[1]));
		// print values
		for (int i = 0; i < pool1.capacity(); i++) {
			if (pool1.free[i]) {
				std::cout << pool1.pool[i] << " "; // 1-5, no 2
			}
		}
		std::cout << std::endl;
		std::cout << std::endl;

		system("pause");
		
	}

	// _CrtDumpMemoryLeaks();

	return 0;
}