#include <iostream>
#include "BinarySearchTree.h"

int main(){
	BinarySearchTree<int> bst = BinarySearchTree<int>();
	// Simple
	bst.insert(10);
	bst.insert(20);
	bst.insert(30);
	bst.insert(40);

	// Advanced
	bst.insert(50);
	bst.insert(30);
	bst.insert(70);
	bst.insert(80);
	bst.insert(75);
	bst.insert(35);
	bst.insert(73);
	bst.insert(33);

	std::cout << bst.contains(10) << bst.contains(20) << bst.contains(75) << bst.contains(33) << std::endl;

	const int size=12;
	int asd[size];
	bst.getContentSorted(asd, size);
	for (int i=0; i<size; i++){
		std::cout << asd[i] << ",";
	}
	std::cout << std::endl;
}