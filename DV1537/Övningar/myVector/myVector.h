template <class T>
class myVector {
private:
	T** vector;
	int reserved;
	int size;
	int expandsize;
public:
	myVector(int=10,int=10);
	~myVector();
	// Insertion
	bool append(T&);
	bool append(T*);
	// Fetching
	T& first();
	T& last();
	T& operator[](int);
	// Expansion
	void expand();
	// Info
	int getSize();
};


template <class T>
myVector<T>::myVector (int size, int expandsize){
	// Initialize values
	this->size = size;
	reserved = 0;
	this->expandsize = expandsize;
	// Initialize array
	vector = new T*[size];
}

template <class T>
myVector<T>::~myVector(){
	delete[] vector;
}

/*
	Insertion
*/

template <class T>
bool myVector<T>::append(T& entry){
	if (reserved >= size)
		this->expand();
	vector[reserved] = &entry;
	reserved++;
	return true;
}

template <class T>
bool myVector<T>::append(T* entry){
	if (reserved >= size)
		this->expand();
	vector[reserved] = entry;
	reserved++;
	return true;
}


/*
	Fetching
*/

template <class T>
T& myVector<T>::first(){
	return *vector[0];
}

template <class T>
T& myVector<T>::last(){
	return *vector[reserved-1];
}

template <class T>
T& myVector<T>::operator[](int index){
	if (index < reserved)
		return *vector[index];
	else
		throw "Index does not exist";
}

/*
	Expansion
*/

template <class T>
void myVector<T>::expand(){
	size += expandsize;
	T** newvector = new T*[size];
	for(int i=0; i<reserved; i++){
		newvector[i] = vector[i];
	}
	delete[] vector;
	vector = newvector;
}

/*
	Info
*/

template <class T>
int myVector<T>::getSize(){
	return reserved;
}