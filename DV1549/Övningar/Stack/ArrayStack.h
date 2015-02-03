#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "IStack.h"

template <typename T>
class ArrayStack : public IStack<T>
{
	int arrSize;
	T* array;
	int front;
	int back;
	public:
		ArrayStack();
		~ArrayStack();
		void push(const T& element) throw();
		T pop();
		T peek() const;
		bool isEmpty() const;
		void present();
};

template<typename T>
ArrayStack<T>::ArrayStack(){
	arrSize = 5;
	array = new T[arrSize];
	front = 0;
	back = 0;
}

template<typename T>
ArrayStack<T>::~ArrayStack(){

}

template<typename T>
void ArrayStack<T>::push(const T& element) throw(){
	if ((front+1)%arrSize == back%arrSize)
		throw "Too many elements in the arraystack to handle, please expand!";
	array[front%arrSize] = element;
	front = (front+1) % arrSize;
}

template<typename T>
T ArrayStack<T>::pop() {
	front--;
	return array[front+1];
}

template<typename T>
T ArrayStack<T>::peek() const {
	return array[back%arrSize];
}

template<typename T>
bool ArrayStack<T>::isEmpty() const {
	bool returnval;
	if (front == back)
		returnval = true;
	else
		returnval = false;
	return returnval;
}

template<typename T>
void ArrayStack<T>::present(){
	for (int i=back; i!= front; i=(i+1)%arrSize){
		std::cout << array[i] << ",";
	}
	std::cout << std::endl;
}

#endif
