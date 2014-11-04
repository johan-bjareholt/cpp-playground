#include <iostream>
#include <cstring>
#include <time.h>

void print_array(int array[], int arrsize, int pos=0){
	for (int n=pos; n<arrsize; n++){
		std::cout << array[n] << ", ";
	}
	std::cout << std::endl;
}


void merge(int array[], int pos, int arr1[], int arr1width, int arr2[], int arr2width){
	// Print them
	//print_array(arr1, arr1width);
	//print_array(arr2, arr1width);
	// Compare
	int arr1i=0,
		arr2i=0;
	for (int i=0; i<arr1width+arr2width; i++){
		//std::cout << "arr1i:" << arr1i << " arr2i:" << arr2i << std::endl;
		// If all numbers in array are taken, push numbers from the other array
		if (arr1i >= arr1width){
			array[pos+i] = arr2[arr2i];
			arr2i++;
		}
		else if (arr2i >= arr2width){
			array[pos+i] = arr1[arr1i];
			arr1i++;
		}
		// Compare values
		else if (arr1[arr1i] > arr2[arr2i]){
			array[pos+i] = arr1[arr1i];
			arr1i++;
		}
		else {
			array[pos+i] = arr2[arr2i];
			arr2i++;
		}
	}
	//print_array(array, arr1width+arr2width, pos);
}

void mergesort2(int array[], int pos, int width){	
	if (width > 1){
		// Print numbers
		//printf("Pos %i\n", pos);
		//print_array(array, width, pos);
		// Each width size
		int colwidth1 = width/2,
			colwidth2 =  width/2;
		if (width%2==1)
			colwidth2++;

		// Branch
		//while (std::cin.get() != '\n'){};
		mergesort2(array, pos, colwidth1);
		mergesort2(array, pos+colwidth1, colwidth2);
		// Split for compare
		int h1[colwidth1],
			h2[colwidth2];
		for (int i=0; i<colwidth1; i++){
			h1[i] = array[pos+i];
		}
		for (int i=0; i<colwidth2; i++){
			h2[i] = array[pos+colwidth1+i];
		}

		// Compare
		merge(array, pos, h1, colwidth1, h2, colwidth2);
	}
}

int main(){
	srand(time(NULL));
	int arraysize;

	std::cout << "Array size: ";
	std::cin >> arraysize;

	int array[arraysize];
	for (int n=0; n<arraysize; n++){
		array[n] = rand() % 10;
	}
	printf("Starting mergesort on array\n");
	std::cout << "Unsorted: ";
	print_array(array, arraysize);

	//mergesort2(array, arraysize);
	mergesort2(array, 0, arraysize);

	std::cout << "Sorted: ";
	print_array(array, arraysize);
}