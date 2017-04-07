#include <stdlib.h>
#include <time.h>
#include "MyLinkedList.h"
#include "MyExceptions.h"

template <typename E>
MySLinkedList<E>::MySLinkedList()				// constructor
	: head(NULL) { }                        // initialize a member pointer


template <typename E>
bool MySLinkedList<E>::empty() const			// is list empty?
{
	return head == NULL;
}

template <typename E>
const E& MySLinkedList<E>::front() const		// return front element
{
	return head->elem;
}

template <typename E>
const E& MySLinkedList<E>::last() const {
	return tail->elem;
}

template <typename E>
MySLinkedList<E>::~MySLinkedList()			// destructor
{
	while (!empty()) removeFront();
}

template <typename E>
void MySLinkedList<E>::addFront(const E& e) {		// add to front of list
	SNode<E>* v = new SNode<E>;				// create new node
	v->elem = e;					// store data
	if (empty()) {
		SNode<E>* v = new SNode<E>;				// create new node
		v->elem = e;					// store data
		v->next = NULL;
		head = v;
		tail = head;
	}
	else {
		v->next = head;
		head = v;
	}
}

template <typename E>
void MySLinkedList<E>::addLast(const E& e) {
	SNode<E>* v = new SNode<E>;
	v->elem = e;
	if (empty()) {
		v->next = head;
		head = v;
		tail = head;
	}
	else {
		v->next = NULL;
		tail->next = v;
		tail = v;
	}


}

template <typename E>
void MySLinkedList<E>::removeFront() throw (LinkedListException) {			// remove front item
	if (empty())
		throw LinkedListException("Empty Linked List");
	SNode<E>* old = head;				// save current head
	head = old->next;					// skip over old head
	delete old;						// delete the old head

}

template <typename E>
void MySLinkedList<E>::removeLast() throw (LinkedListException) {
	if (empty())
		throw LinkedListException("Empty Linked List");
	SNode<E>* temp = new SNode<E>;
	SNode<E>* prev = new SNode<E>;
	temp = head;
	while (temp->next != NULL) {
		prev = temp;
	}
	prev->next = NULL;
	delete tail;
}

template <typename E>
void MySLinkedList<E>::print() {
	SNode<E>* temp = new SNode<E>;
	temp->elem = head->elem;
	temp->next = head->next;
	while (temp->next) {
		cout << temp->elem << endl;
		temp = temp->next;
	}
	cout << temp->elem << endl;

}

void use_MySLinkedList() {
	srand(time(NULL));
	int number;
	MySLinkedList<int> intList;
	for (int i = 1; i <= 50; i++) {
		number = rand() % 100 + 1;
		intList.addFront(number);
	}
	intList.print();

	MySLinkedList<string> customerList;
	string customer;
	for (int i = 1; i <= 100; i++) {
		customer = "Customer " + to_string(i);
		customerList.addLast(customer);
	}

	customerList.print();
}

int main() {

	use_MySLinkedList();

	system("pause");
}