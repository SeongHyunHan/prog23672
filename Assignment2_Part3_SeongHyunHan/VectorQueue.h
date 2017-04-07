#ifndef VECTORQUEUE_H
#define VECTORQUEUE_H
#include <vector>
#include <iostream>
#include "MyExceptions.h"

typedef string Elem;
class VectorQueue {
public:
	VectorQueue();
	int size() const;
	bool empty() const;
	const Elem& head() const throw(QueueException);
	const Elem& tail() throw(QueueException);
	void enqueue(const Elem& e);
	void dequeue() throw(QueueException);
	void print();
private:
	vector<Elem> V;
};

//implementation
VectorQueue::VectorQueue(){}

int VectorQueue::size() const {
	return V.size();
}

bool VectorQueue::empty() const{
	return V.size() == 0;
}

const Elem& VectorQueue::head() const throw(QueueException){
	if (empty())
		throw QueueException("empty queue");
	return V.front();
}

const Elem& VectorQueue::tail() throw(QueueException) {
	if (empty())
		throw QueueException("empty queue");
	return V.back();
}

void VectorQueue::enqueue(const Elem& e) {
	V.push_back(e);
}

void VectorQueue::dequeue() throw(QueueException) {
	if (empty())
		throw QueueException("Dequeue of empty queue");
	V.erase(V.begin());
}

void VectorQueue::print() {
	for (int i = 0; i < V.size(); i++) {
		cout << i << " : " << V[i] << "\n";
	}
}

#endif // !VECTORQUEUE_H
