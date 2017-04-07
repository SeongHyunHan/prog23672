#include<string>
#include<iostream>
#ifndef MYSLINKEDLIST_H
#define MYSLINKEDLIST_H
#include "MyExceptions.h"

using namespace std;
// define the node
template <typename E>
class SNode {					// singly linked list node
private:
	E elem;					// linked list element value
	SNode<E>* next;			// next item in the list
	template<class E> friend class MySLinkedList;

	//friend class SLinkedList<E>;
};

template <typename E>
class MySLinkedList {
public:
	MySLinkedList();
	~MySLinkedList();
	bool empty() const;
	const E& front() const;
	const E& last() const;
	void addFront(const E& e);
	void addLast(const E& e);
	void removeFront() throw (LinkedListException);
	void removeLast() throw (LinkedListException);
	void print();
private:
	SNode<E>* head;
	SNode<E>* tail;
};

#endif