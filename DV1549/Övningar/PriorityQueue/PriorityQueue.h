#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <iostream>

#include "IPriorityQueue.h"

template<typename T>
class PriorityQueue : IPriorityQueue<T> {
private:
	class Node {
	public:
		T element;
		Node* next;
		Node(const T& element){this->element = element; this->next = nullptr; }
	};

	Node* first;
	Node* last;
public:
	PriorityQueue();
	~PriorityQueue();
	void enqueue(const T& element);
	T dequeue();
	T peek() const;
	int size() const;
	void present();
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{
	first = nullptr;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	Node* n = first;
	while (n != nullptr){
		Node* next = n->next;
		delete n;
		n = next;
	}
}

template<typename T>
void PriorityQueue<T>::enqueue(const T& element)
{
	Node* n = first;
	Node* newN = new Node(element);
	if (first != nullptr && first->element > element){
		while (n->next != nullptr && n->next->element > element)
			n = n->next;
		Node* after = nullptr;
		newN->next = n->next;
		n->next = newN;
	}
	else {
		newN->next = first;
		first = newN;
	}
}

template<typename T>
T PriorityQueue<T>::dequeue()
{
	if (first == NULL)
		throw "Cannot dequeue from an empty queue";
	T result = this->first->element;
	Node* toDelete = first;
	this->first = this->first->next;
	delete toDelete;
	return result;
}

template<typename T>
T PriorityQueue<T>::peek() const
{
	if (first == nullptr)
		throw "Cannot peek an empty queue";
	return first->element;
}

template<typename T>
int PriorityQueue<T>::size() const
{
	Node* n = first;
	int size = 0;
	if (n != nullptr){
		size++;
		while (n->next != nullptr){
			n = n->next;
			size++;
		}
	}
	return size;
}

template<typename T>
void PriorityQueue<T>::present(){
	Node* n = first;
	while (n != nullptr){
		std::cout << n->element << ",";
		n = n->next;
	}
	std::cout << std::endl;
}

#endif