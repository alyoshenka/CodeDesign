#include "LinkedList.h"
#include "DynamicArray.h"
#include <iostream>
#include <list>

// figure out why iteration isn't working

int main() {

	/*
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
	std::cout << "0=" << (itr == itr2) << std::endl;

	std::cout << *itr << std::endl;
	std::cout << *itr2 << std::endl;

	std::list<int> test;
	test.push_back(1);
	std::list<int>::iterator testItr = test.end();
	// std::cout << *(test.end()) << std::endl;

	for (auto it = list1.begin(); it != list1.end(); it++) {
		std::cout << (*it) << std::endl;
	}
	for (auto it = list1.begin(); it != list1.end(); ++it) {
		std::cout << (*it) << std::endl;
	}
	*/

	DynamicArray<int> test2;
	test2.push_front(1);
	

	system("pause");
	return 0;
}