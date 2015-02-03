#include <iostream>

#include "List.h"

int main(){
	try {
		List<std::string> list;
		list.insertAt(0,"Hello!");
		list.insertAt(1,"How");
		list.insertAt(2,"are");
		list.insertAt(3,"you");
		list.insertAt(4,"today?");
	
		list.showContent();
	
		list.removeAt(1);
		list.removeAt(1);
		list.insertAt(2,"is");
		list.insertAt(3,"she");//
		
		list.showContent();
	
		std::cout << "Who " << list.elementAt(2) << " "<< list.elementAt(3) << "?" << std::endl;

		List<std::string> list2(list);//
		list2.showContent();

		List<int> intlist;
		intlist.insertAt(0,50);
		intlist.insertAt(0,25);
		intlist.insertAt(2,75);//

		intlist.showContent();
	}
	catch (const char* e) {
		std::cout << e << std::endl;
	}
	return 0;
}
