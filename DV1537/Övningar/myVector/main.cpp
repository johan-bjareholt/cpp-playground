#include <iostream>

#include "myVector.h"

int main(){
	myVector<std::string> testVector;

	std::string mystring = "asdasd";
	std::string mystring2 = "asdasd2";
	std::string mystring3 = "asdasd3";
	testVector.append(mystring);
	testVector.append(mystring2);
	testVector.append(mystring3);

	std::cout << "First: " << testVector.first() << std::endl;
	std::cout << "Last: " << testVector.last() << std::endl;

	std::cout << "All entries" << std::endl;
	for (int i=0; i<testVector.getSize(); i++){
		std::cout << testVector[i] << std::endl;
	}
	return 0;
}