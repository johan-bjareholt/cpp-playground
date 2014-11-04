#include <iostream>

int exp(int base, int exponent){
	if (exponent==0)
		return 1;
	return base*exp(base,exponent-1);
}

int fibo(int n, int prev, int max){
	std::cout << n << ",";
	if (n>=max){
		return n;
		std::cout << std::endl;
	}
	return fibo(n+prev, n, max);
}

void arrayBackwards(int n, int array[]){
	std::cout << array[n-1] << ", ";
	if (n==1){
		std::cout << std::endl;
		return;
	}
	arrayBackwards(n-1, array);
}

void sort(int array[], int arrsize, int i=0){
	if (i>=arrsize || i==-1)
		return;
	if (array[i+1]<array[i]){
		int temp = array[i];
		array[i] = array[i+1];
		array[i+1] = temp;
		sort(array,arrsize,i-1);
	}
	sort(array,arrsize,i+1);
}

int binarySearch(int array[], int number, int min, int max){
	int delta = max-min;
	int i = min+(delta/2);
	std::cout << i << ",";
	if (array[i] == number)
		return i;
	if (delta==1)
		return 0;
	if (array[i]<number)
		return binarySearch(array, number, i, max);
	else
		return binarySearch(array, number, min, i);
}

int main(){
	std::cout << "pow(2,8): " << exp(2,8);
	std::cout << std::endl << "fibo(1,1,200): ";
	fibo(1,1,200);

	int myarray[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	sort(myarray,20);
	int myarray2[20] = {50,15,34,76,23,45,3,8,4,6,87,3,786,4,7,4,5,6,18,5};
	sort(myarray2,20);

	std::cout << std::endl << "sorted array1: ";
	for (int n=0; n<20; n++)
		std::cout << myarray[n] << ",";

	std::cout << std::endl << "binarySearch for 18: " << binarySearch(myarray2, 18, 0,19);

	std::cout << std::endl << "arrayBackwards: ";
	arrayBackwards(20,myarray);
	return 1;
}