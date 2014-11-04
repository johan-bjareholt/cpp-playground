#include <time.h>
#include <iostream>


int arraysize;

void print_array(int array[], int size, int startpos=0){
	for (int n=startpos; n<arraysize; n++){
		std::cout << array[n] << ",";
	}
}

void partition(int array[], int i, int pivot){
	int temp = array[pivot-1];
	array[pivot-1] = array[pivot];
	array[pivot] = array[i];
	array[i] = temp;
}


void quicksort(int array[], int start, int end){
	int i = start;
	int pivot = end;
	std::cout << start << " and " << end << std::endl;
	while (i<pivot){
		std::cout << "comparing index " << i << " to " << pivot << ": ";
		print_array(array, end, start);
		std::cout << std::endl;
		if (array[i]>array[pivot]){
			partition(array, i, pivot);
			pivot--;
		}
		else
			i++;
	}
	
	if (start-end == 2){
		std::cout << "Sorting all " << start << " " << end << std::endl;
		quicksort(array, i, pivot);
	}
	if ((pivot-1)-start > 1){
		std::cout << "Sorting left side " << start << " " << i << std::endl;
		quicksort(array, start, pivot-1);
	}
	if (end-(pivot+1) > 1){
		std::cout << "Sorting right side " << pivot << " " << end << std::endl;
		quicksort(array, pivot+1, end);
	}
}


int main(){
	srand(time(NULL));

	std::cout << "Array size: ";
	std::cin >> arraysize;
	int array[arraysize];
	std::cout << "random array: ";
	for (int n=0; n<arraysize; n++){
		array[n] = rand() % 255;
		std::cout << array[n] << ",";
	}

	quicksort(array, 0, arraysize-1);
	//partition(array,0,arraysize-1);

	std::cout << std::endl << "sorted array: ";

	for (int n=0; n<arraysize; n++){
		std::cout << array[n] << ",";
	}
	std::cout << std::endl;

	return 1;
}