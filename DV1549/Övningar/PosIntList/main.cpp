#include <iostream>

#include "PosIntList.h"

void printList(PosIntList& pil){
	for (int i=0; i<pil.size(); i++){
		std::cout << pil.elementAt(i) << ",";
	}
	std::cout << std::endl;
}

int main(){
	PosIntList pil;
	try {
		pil.insertFirst(30);
		pil.insertFirst(20);
		pil.insertFirst(10);
		pil.insertAt(0,5);
		pil.insertAt(2,15);
		pil.insertAt(4,25);
		//pil.insertAt(-4,22);
		pil.insertLast(35);

		printList(pil);

		pil.removeFirst();
		pil.removeLast();

		pil.removeAt(1);
		pil.removeAt(2);

		printList(pil);

		PosIntList pil2(pil);
		pil2.insertFirst(1);
		pil2.insertLast(39);
		printList(pil2);

		pil = pil2;

		printList(pil);
	}
	catch (const char* e){
		std::cout << e << std::endl;
	}

	//PosIntList pil2(pil);

	return 0;
}