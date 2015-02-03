#include <iostream>

#include "ArrayStack.h"
#include "LinkedStack.h"
#include "ListStack.h"

void shortIntTest(IStack<int>& stack){
	try {
		stack.push(3);
		stack.push(2);
		stack.push(1);
	
		stack.present();
	}
	catch (const char* e){
		std::cout << e << std::endl;
	}
}

void longIntTest(IStack<int>& stack){
	try {
		stack.push(3);
		stack.push(2);
		stack.push(1);
		stack.present();
		stack.pop();
		stack.pop();
		stack.push(6);
		stack.push(9);
		stack.present();
	}
	catch (const char* e){
		std::cout << e << std::endl;
	}
}


int main(){
	
	std::cout << "Linked stack" << std::endl;
	LinkedStack<int> linked1;
	longIntTest(linked1);

	std::cout << "Array stack" << std::endl;
	ArrayStack<int> array1;
	longIntTest(array1);

	std::cout << "List stack" << std::endl;
	return 0;
}
