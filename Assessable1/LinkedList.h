#pragma once
#include <cassert>
#include <stddef.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif

template <typename T>
class LinkedList {

	struct Node {
		// value
		T data;
		// previous node
		Node * previous;
		// next node
		Node * next;
	};

	// starting node
	Node * head;

public:

	// iterator
	class iterator {
		// current node being operated upon
		Node * cur;
	public:
		// constructor
		iterator(Node * n);
		// destructor
		~iterator(); 

		// does iterator point to same node?
		bool operator==(const iterator& rhs) const;
		// does iterator point to different node?
		bool operator!=(const iterator& rhs) const;
		// returns element pointed to my current node
		T& operator*() const;
		// pre-increment, reference to iterator after incremented
		iterator& operator++();
		// post-increment, iterator to current node while incrementing existing iterator (WHAT)
		iterator operator++(int);
		// pointer dereference overload
		T* operator->();
	};

	// constructor
	LinkedList();
	// destructor
	~LinkedList();

	// add value to front of list
	void pushFront(const T& val); // &?
	// pop value from front of list
	void popFront();
	// add value to back of list
	void pushBack(const T& val);
	// pop value from back of list
	void popBack();

	// first value in list
	T& first();
	// last value in list
	T& last();
	// number of values in list
	size_t count();
	// is list empty?
	bool empty();
	// clear list
	// void clear();

	// iterator to first element
	iterator begin();
	// iterator to last element
	iterator end();

};

template <typename T>
LinkedList<T>::LinkedList() {
	// no data in list
	head = nullptr; 
}

template <typename T>
LinkedList<T>::~LinkedList() { 
	// iterate through and delete all pointers
	while (head->next != nullptr) {
		head = head->next;
		delete head->previous;
	}
}

template <typename T>
void LinkedList<T>::pushFront(const T& val) {

	// if first node
	if (head == nullptr) {
		head = new Node;
		head->data = val;
		head->next = nullptr;
		head->previous = nullptr;
	}
	else {
		// make new node
		Node * temp = new Node{val, nullptr, head};	
		head->previous = temp;
		head = temp;
	}	
} 

template <typename T>
void LinkedList<T>::popFront() { 
	// set second node's previous pointer to null
	head->next->previous = nullptr;	
	// create temporary pointer to second node
	Node temp;
	temp.next = head->next;
	// delete first
	delete head;
	// set class head to new value
	head = temp.next;
	// temp is deleted when functions ends
}

template <typename T>
void LinkedList<T>::pushBack(const T& val) {


	// create new node
	Node newNode;
	newNode.data = val;
	newNode.next = nullptr;

	// get to last value in list
	Node temp = head; 
	// while next value
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	// set last->next to new
	temp->next = newNode;
	// set new->previous to last
	newNode.previous = * temp; // this could be wrong
	
}

template <typename T>
void LinkedList<T>::popBack() {
	// iterate to one back from back of list
	Node * temp = head;
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	// delete next (last) node
	delete temp->next;
	// set next to null
	temp->next = nullptr;
}

template <typename T>
T& LinkedList<T>::first() {
	// return first node data
	return head->data;
} 

template <typename T>
T& LinkedList<T>::last() {

	// if nothing	
	if (head == nullptr) {
		assert("Nothing to return");
	}

	// iterate to back of list
	Node * temp = head;
	
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	// return data
	return temp->data;
}

template <typename T>
size_t LinkedList<T>::count() {

	size_t cnt = 0;

	// if nothing in list
	if (head == nullptr) {
		return cnt;
	}

	// head = 1
	cnt++;

	// iterate through list, count items
	Node * temp = head;
	while (temp->next != nullptr) {
		temp = temp->next; 
		cnt++;
	}

	return cnt;
}

template <typename T>
bool LinkedList<T>::empty() {
	// if nothing
	if (head == nullptr) {
		return true;
	}
	// else
	return false;
}

template <typename T> 
typename LinkedList<T>::iterator LinkedList<T>::begin() {

	iterator temp(head);
	return temp;
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::end() {
	return iterator(nullptr);
}

template<typename T>
LinkedList<T>::iterator::iterator(Node * n)
{
	cur = n;
}

template<typename T>
LinkedList<T>::iterator::~iterator()
{
	// delete cur;
}

template <typename T>
bool LinkedList<T>::iterator::operator==(const iterator& rhs) const {	

	return cur == rhs.cur;
}

template <typename T>
bool LinkedList<T>::iterator::operator!=(const iterator& rhs) const {

	return cur != rhs.cur;
}

template <typename T>
T& LinkedList<T>::iterator::operator*() const {
	return cur->data;
}

template <typename T>
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator++() {
	cur = cur->next;
	return *this;
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::iterator::operator++(int) {
	iterator temp(*this);
	cur = cur->next;
	return temp;
}

template<typename T>
T * LinkedList<T>::iterator::operator->()
{
	return &this;
}




