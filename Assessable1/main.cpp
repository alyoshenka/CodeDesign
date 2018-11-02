#include "LinkedList.h"
#include <iostream>

// figure out why iteration isn't working

int main() {

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


	for (auto it = list1.begin(); it != list1.end(); it++) {
		// iteration at enddddd
		std::cout << (*it) << std::endl;
	}
	for (auto it = list1.begin(); it != list1.end(); ++it) {
		std::cout << (*it) << std::endl;
	}
	


	system("pause");
	return 0;
}