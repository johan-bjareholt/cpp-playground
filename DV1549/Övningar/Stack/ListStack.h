#ifndef LIST_STACK_H
#define LIST_STACK_H

template<typename T>
class ListStack : public IStack<T> {
private:
	class Node {
		T value;
		Node* prev;
	};
	Node* first;
	Node* last;
public:
	void push(const T& element);
	T pop();
	T peek() const;
	bool isEmpty() const;
	void present();
};

template<typename T>
void ListStack<T>::push(const T& element){

}

template<typename T>
T ListStack<T>::pop(){

}

template<typename T>
T ListStack<T>::peek() const{

}

template<typename T>
bool ListStack<T>::isEmpty() const{

}

template<typename T>
void ListStack<T>::present(){

}

#endif