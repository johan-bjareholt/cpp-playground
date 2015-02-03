#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "IList.h"

template <typename T>
class List : public IList<T> {
private:
	class Node {
	public:
		T element;
		Node* next;
		Node(T element){ this->element = element; this->next = nullptr; }
	};
	int nrOfElements;
	Node* first;
public:
	List(){
		nrOfElements = 0;
		first = nullptr;
	};
	virtual ~List();
	List(const List<T>& original);
	List<T>& operator=(const List<T>& original){};

	void insertAt(int, T) throw();
	T removeAt(int) throw();
	T elementAt(int) const throw();
	
	void showContent() throw();
	int size() const ;
};

template<typename T>
List<T>::~List(){
	Node* walker = first;
	for (int i=0;i<nrOfElements; i++){
		Node* toDelete = walker;
		walker = walker->next;
		delete toDelete;
	}
}

template<typename T>
List<T>::List(const List<T>& original){
	first = new Node(original.first->element);
	Node* walker1 = first;
	Node* walker2 = original.first;
	nrOfElements = 1;
	for (int i=1; i<original.size(); i++){
		walker1->next = new Node(walker2->next->element);
		walker1 = walker1->next;
		walker2 = walker2->next;
		nrOfElements++;
	}
}

template<typename T>
void List<T>::insertAt(int pos, T element) throw(){
	if ( pos < 0 || pos > nrOfElements)
		throw "Cannot add element since the position is out of range";
	if ( pos == 0 ){
		Node* newElement = new Node(element);
		newElement->next = first;
		first = newElement;
	}
	else {
		Node* walker = first;
		for (int i=0; i<pos-1; i++)
			walker = walker->next;
		Node* newElement = new Node(element);
		newElement->next = walker->next;
		walker->next = newElement;
	}
	nrOfElements++;
}

template<typename T>
T List<T>::removeAt(int pos) throw(){
	if ( pos < 0 || pos > nrOfElements-1 )
		throw "Cannot remove element since the position is out of range";
	T returnval;
	if ( pos == 0 ){
		Node* newFirst = first->next;
		returnval = first->element;
		delete first;
		first = newFirst;
	}
	else {
		Node* walker = first;
		for (int i=0; i<pos; i++)
			walker = walker->next;
		Node* newNext = walker->next->next;
		returnval = walker->next->element;
		delete walker->next;
		walker->next = newNext;
	}
	nrOfElements--;
	return returnval;
}

template<typename T>
T List<T>::elementAt(int pos) const throw(){
	if ( pos < 0 || pos > nrOfElements-1 )
		throw "Cannot fetch element since the position is out of range";
	Node* walker = first;
	for (int i=0; i<pos; i++)
		walker = walker->next;
	return walker->element;
}

template<>
void List<int>::showContent() throw(){
	if ( first == nullptr )
		throw "Cannot show an empty list";
	Node* walker = first;
	for (int i=0; i<nrOfElements; i++){
		std::cout << walker->element << ",";
		walker = walker->next;
	}
	std::cout << std::endl;
}

template<>
void List<std::string>::showContent() throw(){
	if ( first == nullptr )
		throw "Cannot show an empty list";
	Node* walker = first;
	for (int i=0; i<nrOfElements; i++){
		std::cout << walker->element << " ";
		walker = walker->next;
	}
	std::cout << std::endl;
}

template<typename T>
void List<T>::showContent() throw(){
	if ( first == nullptr )
		throw "Cannot show an empty list";
	Node* walker = first;
	for (int i=0; i<nrOfElements; i++){
		std::cout << walker->element << ", ";
		walker = walker->next;
	}
	std::cout << std::endl;
}

template<typename T>
int List<T>::size() const {
	return nrOfElements;
}

#endif
