// tLinkedList.md
#pragma once
#include <iostream>

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list

public:
	tForwardList();                 // default constructor
	~tForwardList();                // destructor

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front

	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)

	void remove(const T& val);      // removes all elements equal to the given value

	// copy constructor
	tForwardList(const tForwardList& other);
	// copy assignment
	tForwardList& operator=(const tForwardList &rhs);

	bool empty() const;             // Returns true if there are no elements
	void clear();                   // Destroys every single node in the linked list
	void resize(size_t newSize);    // Resizes the linked list to contain the given number of elements
									// New elements are default-initialized

	// print the damn thing
	void show();
};

template<typename T>
tForwardList<T>::tForwardList() {
	// not sure yet
	// need to initialize something
	head = nullptr; // there's nothing here
}

template<typename T>
tForwardList<T>::~tForwardList() {
	
	// if no memory allocated
	if (head == nullptr) {
		// we're good
		return;
	}

	// otherwise...
	Node * temp = head;
	while (temp->next != nullptr) {
		head = temp;
		temp = temp->next;
		delete head;
	}
	// get rid of it
	delete temp;
}

template<typename T>
void tForwardList<T>::push_front(const T& val){
	
	// if first
	if (head == nullptr) {
		head = new Node;
		head->data = val;
		head->next = nullptr;
	}
	// if 1+ nodes
	else {		
		Node * temp = new Node{ val, head };
		head = temp;
		// delete temp; you cant delete because it's using it
		// DELETE TEMP
	}
}

template<typename T>
void tForwardList<T>::pop_front() {
	// set head to next node
	head = head->next;
	// delete head
	// DELETE HEAD
	// original data for head needs to be cleaned up here
}

template<typename T>
inline T & tForwardList<T>::front() {
	return head->data;
}

template<typename T>
inline const T& tForwardList<T>::front() const {
	return head->data; // what should I change?
}

template<typename T>
inline void tForwardList<T>::remove(const T& val) {

	// head == nullptr = user error

	// if at beginning
	while (head->data == val) {
		pop_front();
		if (head == nullptr) {
			return;
		}
	}

	// there must be a better way to do this, I don't know what it is
	for (Node * it = head; it->next != nullptr; it = it->next) {
		// Node * temp = it->next;
		while (it->next->data == val) { // WHATTTTTTT WHY FUCK SHOW()
			Node * temp = it->next;
			// Node * temp = it->next;
			it->next = it->next->next;
			// delete temp;
			delete temp;

			// if we've reached the end before the while loop catches it
			if (it->next == nullptr) {
				return;
			}
		}
	}
}

template<typename T>
inline tForwardList<T>::tForwardList(const tForwardList & other)
{
	// while still another value
	while (head.next != nullptr) {
		// head = data for next
		other.head = head.next;
		// should there be more??
	}

	return *this;
}

// tForwardList& operator=(const tForwardList &rhs);
template<typename T>
inline tForwardList<T> & tForwardList<T>::operator=(const tForwardList & rhs)
{
	// should be the sape as copy constructor 

	// while still another value
	while (head.next != nullptr) {
		// head = data for next
		rhs.head = head.next;

		// should there be more??
	}

	return *this;
}

template<typename T>
inline bool tForwardList<T>::empty() const
{
	// if nothing
	if (head == nullptr) {
		return true;
	}
	// else
	return false;
}

template<typename T>
inline void tForwardList<T>::clear()
{
	// iterate through
	while (head->next != nullptr) { // will this delete the last one?
		// set to next
		head = head->next;
		// delete
		delete head;
	}
}

template<typename T>
inline void tForwardList<T>::resize(size_t newSize)
{
	// constrain to size
	for (size_t i = 0; i < newSize; i++) {
		// set val
		head = head->next;
	}

	// this should be ok because head isn't set at the start right now
	// clear();
}

template<typename T>
void tForwardList<T>::show() {

	if (head == nullptr) {
		return;
	}
	
	Node * temp = head;

	while (temp->next != nullptr) {

		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
	std::cout << temp->data << std::endl;

	delete temp;
}

