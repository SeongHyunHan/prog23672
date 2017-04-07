#include <iostream>
#include <vector>
#include "vectorQueue.h"

using namespace std;
void use_VectorQueue() {
	VectorQueue q;
	cout << "The size after creating a queue:" << q.size() << "\n";
	q.enqueue("Dave");
	q.enqueue("John");
	cout << "The size after enqueuing Dave, John:" << q.size() << "\n";
	cout << q.head() << " is at the front of the Queue \n";
	q.dequeue();
	q.head();
	cout << "The size after dequeueing dave: " << q.size() << "\n";
	cout << q.head() << " is at the front of the Queue \n";
	q.print();
}

int main() {
	use_VectorQueue();
	system("pause");
}