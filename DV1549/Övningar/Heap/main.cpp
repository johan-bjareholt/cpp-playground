#include <iostream>
#include "Heap.h"

int main(){
	try {
		Heap<int> heap;
		heap.insert(1);
		heap.insert(2);
		heap.insert(3);
		heap.insert(4);
		heap.insert(5);
		heap.insert(6);
		heap.insert(7);
		heap.insert(8);
		heap.insert(9);
		heap.insert(10);
		std::cout << heap.present();

		heap.deleteMax();

		std::cout << heap.present();

		heap.deleteMax();

		std::cout << heap.present();

		Heap<int> heap2;
		heap2.insert(5);
		heap2.insert(8);
		heap2.insert(12);
		heap2.insert(4);
		heap2.insert(55);
		heap2.insert(9);
		heap2.insert(1);
		heap2.insert(17);
		heap2.insert(11);
		std::cout << heap2.present();
	}
	catch (const char* e){
		std::cout << e << std::endl;
	}
	return 0;
}