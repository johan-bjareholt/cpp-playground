#include <sstream>
#include <iostream>

template<typename T>
class Heap {
private:
	T** array;
	int nrOfElements;
	static const int size=50;
public:
	Heap();
	~Heap();
	void insert(T);
	void deleteMax();
	T root();
	std::string present();
};

template<typename T>
Heap<T>::Heap(){
	this->array = new T*[size];
	this->nrOfElements = 0;
}

template<typename T>
Heap<T>::~Heap(){
	for(int i=0; i<nrOfElements; i++)
		delete array[i];
	delete[] array;
}

template<typename T>
void Heap<T>::insert(T element){
	if (nrOfElements == size)
		throw "Array is full";
	T* newElement = new T(element);
	int i=nrOfElements++;
	// (i-1)/2 is same as the parents position
	bool lower = false;
	while (!lower)
	{
		int parenti = (i-1)/2;
		if (i>0 && *newElement > *array[parenti]){
			array[i] = array[parenti];
			i = parenti;
		}
		else
			lower = true;
	}
	array[i] = newElement;
	std::cout << present();
}

template<typename T>
void Heap<T>::deleteMax(){
	delete array[0];
	nrOfElements--;
	int* val = array[nrOfElements];
	int i=0;
	bool lower=true;
	while(lower){
		int leftChildPos = 2*i+1;
		int rightChildPos = 2*i+2;
		if (leftChildPos < nrOfElements && *val < *array[leftChildPos]){
			array[i] = array[leftChildPos];
			i = leftChildPos;
		}
		else if (rightChildPos < nrOfElements && *val < *array[rightChildPos]){
			array[i] = array[rightChildPos];
			i = rightChildPos;
		}
		else
			lower = false;

	}
	array[i] = val;
}

template<typename T>
T Heap<T>::root(){
	if (nrOfElements==0)
		throw "Cannot get root from empty heap!";
	return array[0];
}

template<typename T>
std::string Heap<T>::present(){
	std::stringstream ss;
	for(int i=0; i<nrOfElements; i++)
		ss << *array[i] << ",";
	ss << std::endl;
	return ss.str();
}