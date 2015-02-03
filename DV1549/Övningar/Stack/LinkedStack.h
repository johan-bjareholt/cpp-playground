#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>

template <typename T>
class LinkedStack : public IStack<T>
{
	class Node {
	public:
		T element;
		Node* previous;
		Node(T e){
			this->element = e;
			this->previous = nullptr;
		}
	};
	Node* last;
	public:
		LinkedStack();
		~LinkedStack();
		void push(const T& element);
		T pop();
		T peek() const;
		bool isEmpty() const;
		void present();
};

template<typename T>
LinkedStack<T>::LinkedStack(){
	last = nullptr;
}

template<typename T>
LinkedStack<T>::~LinkedStack(){
	Node* walker = last;
	while (walker != nullptr){
		Node* toDelete = walker;
		walker = walker->previous;
		delete toDelete;
	}
}

template<typename T>
void LinkedStack<T>::push(const T& element){
	Node* newNode = new Node(element);
	newNode->previous = last;
	last = newNode;
}

template<typename T>
T LinkedStack<T>::pop(){
	Node* toDelete;
	last = last->previous;
	delete toDelete;
	return T();
}

template<typename T>
T LinkedStack<T>::peek() const {
	return last->element;
}

template<typename T>
bool LinkedStack<T>::isEmpty() const {
	bool returnval;
	if (last == nullptr)
		returnval = true;
	else
		returnval = false;
	return returnval;
}

template<typename T>
void LinkedStack<T>::present(){
	Node* walker = last;
	while (walker != nullptr){
		std::cout << walker->element << ",";
		walker = walker->previous;
	}
	std::cout << std::endl;
}

#endif
