#include <iostream>

void insertionsort (int array[], int arrsize){
	int cursor;
	for (int sorted=1; sorted<arrsize; sorted++){
		cursor = sorted;
		while (cursor>0 && array[cursor]<array[cursor-1]){
			int temp = array[cursor-1];
			array[cursor-1] = array[cursor];
			array[cursor] = temp;
			cursor--;
		}
	}
}

void print_array(int array[], int arrsize){
	for (int n=0; n<arrsize; n++){
		std::cout << array[n] << ", ";
	}
	std::cout << std::endl;
}

int main(){
	int arrsize = 10;
	int array[] = {6,7,5,4,3,8,9,1,2,0};

	print_array(array, arrsize);
	insertionsort(array, arrsize);
	print_array(array, arrsize);
}