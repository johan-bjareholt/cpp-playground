#include <iostream>
#include <time.h>

static int array_size;
static int comparisons	= 0;
static int swaps		= 0;

template <typename T>
void print_array(T array[]){
	for (int n=0; n<array_size; n++)
		std::cout << array[n] << ",";
	std::cout << std::endl;
}

template <typename T>
void selection_sort(T array[]){
	int sorted=0;
	while (sorted < array_size){
		for (int low=0; low<array_size; low++){
			for (int lower=low+1; lower<array_size; lower++){
				std::cout << "Comparing index " << low << " to " << lower << std::endl;
				if (array[lower]<array[low]){
					T temp = array[low];
					array[low] = array[lower];
					array[lower] = temp;
					print_array(array);
					swaps++;
				}
				comparisons++;
			}
			sorted++;
		}
	}
}

int main(){
	srand(time(NULL));

	std::cin >> array_size;


	// Create random array
	short array[array_size];
	for (int n; n<array_size; n++){
		array[n] = rand() % 100;
	}

	// Print unsorted array
	print_array(array);
	// Sort array
	selection_sort<short>(array);
	// Print sorted array
	print_array(array);
	// Print comparison count
	std::cout << comparisons << " comparisons and " << swaps << " swaps were made" << std::endl;

	return 0;
}