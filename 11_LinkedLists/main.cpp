#include "tForwardList.h"
#include <iostream>

int main() {

	tForwardList<int> myTest;

	myTest.push_front(1);
	myTest.push_front(2);
	myTest.push_front(3);
	myTest.push_front(1);
	myTest.push_front(2);
	myTest.push_front(3);

	// std::cout << myTest.front() << std::endl;
	// myTest.pop_front();
	std::cout << myTest.front() << std::endl;
	myTest.remove(3);
	// myTest.pop_front();
	std::cout << myTest.front() << std::endl;
	myTest.remove(2);
	std::cout << myTest.front() << std::endl;
	myTest.remove(1);
	// myTest.pop_front();
	// std::cout << myTest.front() << std::endl;
	std::cout << "1 = " << myTest.empty() << std::endl;

	std::cout << std::endl;
	tForwardList<int> test2;
	test2.push_front(1);
	test2.push_front(2);
	test2.push_front(3);
	test2.push_front(4);
	std::cout << test2.front() << std::endl;
	test2.resize(2);
	std::cout << test2.front() << std::endl;

	std::cout << std::endl;
	tForwardList<int> remTest;
	remTest.push_front(2);
	remTest.push_front(0);
	remTest.push_front(0);
	remTest.push_front(0);
	remTest.push_front(3);
	remTest.push_front(2);
	remTest.push_front(0);
	remTest.push_front(0);
	remTest.push_front(0);
	remTest.push_front(1);
	std::cout << remTest.front() << std::endl; // 1
	remTest.remove(0);
	std::cout << remTest.front() << std::endl; // 1
	remTest.pop_front();
	std::cout << remTest.front() << std::endl; // 2
	remTest.pop_front();
	std::cout << remTest.front() << std::endl; // 3

	std::cout << std::endl;
	tForwardList<int> jonTest;
	jonTest.push_front(4);
	jonTest.push_front(4);
	jonTest.push_front(7);
	jonTest.push_front(4);
	jonTest.push_front(4);
	jonTest.push_front(3);
	jonTest.push_front(4);
	jonTest.push_front(4);

	std::cout << std::endl;
	jonTest.show(); // WHY DOES THIS BREAK EVERYTHING

	jonTest.remove(4);
	std::cout << jonTest.front() << std::endl; // 3
	jonTest.remove(3);
	std::cout << jonTest.front() << std::endl; // 7

	system("pause");

	return 0;
}