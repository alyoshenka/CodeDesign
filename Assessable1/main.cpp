#include "LinkedList.h"
#include "DynamicArray.h"
#include <iostream>
#include <list>

// figure out why iteration isn't working

int main() {

	// expected values are commented and printed for easy
	// checks with actual output values

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
	std::cout << "0=" << (itr == itr2) << std::endl;

	std::cout << std::endl;

	// check for correct iteration through list
	for (auto it = list1.begin(); it != list1.end(); it++) { // 432
		std::cout << (*it) << std::endl;
	}
	// this doesn't work, but there should be a way to iterate backwards
	//for (auto it = list1.end(); it != list1.begin(); it--) { // 234
	//	std::cout << (*it) << std::endl;
	//}
	
	std::cout << std::endl;
	std::cout << "Dynamic Array" << std::endl;

	DynamicArray<int> test2;
	test2.push_front(7);
	test2.push_front(6);
	test2.push_back(8);
	test2.push_back(9);
	test2.push_front(5);
	test2.add(10, 3);
	test2.show(); // 5 6 7 10 8 9 
	test2.remove(2); 
	test2.show(); // 5 6 9 10 8
	test2.removedOrdered(2); 
	test2.show(); // 5 6 10 8
	test2.clear();
	test2.show(); // nothing

	std::cout << std::endl;

	DynamicArray<int> test3;
	test3.push_front(1);
	test3.push_back(5);
	test3.show(); // 1 5
	int test3Arr[3] = { 2, 3, 4 };
	test3.addArr(test3Arr, 3, 1);
	test3.show(); // 1 2 3 4 5

	// possible problem is trying to delete test3Arr when this has already been handled
	
	system("pause");
	return 0;
}