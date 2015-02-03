template <typename T>
class BinarySearchTree
{
private:
	class Node
	{
	public:
		T info;
		Node *leftChild;
		Node *rightChild;
		Node(T info) {this->info = info; this->leftChild = nullptr; this->rightChild = nullptr;}
		~Node() {};
	};
	Node* root;
	int nrOfNodes;
	// helper functions
	int getSortR(T result[], int i, Node* walker) const;
public:
	BinarySearchTree();
	virtual ~BinarySearchTree(){};
	void insert(T info);
	bool contains(T info) const;
	int getNrOfNodes() const;
	void getContentSorted(T result[], int n) const; // throws exception when n is smaller than the the number of elements/nodes in the tree
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(){
	root = nullptr;
	nrOfNodes = 0;
}

template<typename T>
void BinarySearchTree<T>::insert(T info) {
	Node* newNode = new Node(info);
	if (this->nrOfNodes == 0){
		root = newNode;
		nrOfNodes++;
	}
	else {
		Node* walker = root;
		bool done = false;
		Node* prev;
		while (!done){
			if (newNode->info < walker->info){
				if (walker->leftChild == nullptr){
					walker->leftChild = newNode;
					done = true;
					nrOfNodes++;
				}
				else
					walker = walker->leftChild;
			}
			else if (newNode->info > walker->info){
				if (walker->rightChild == nullptr){
					walker->rightChild = newNode;
					done=true;
					nrOfNodes++;
				}
				else
					walker = walker->rightChild;
			}
			else {
				delete newNode;
				done = true;
			}
		}
	}
}

template<typename T>
bool BinarySearchTree<T>::contains(T info) const {
	if (root == nullptr)
		return false;
	Node* walker = root;
	bool done=false;
	bool found=true;
	while (done == false){
		if (walker == nullptr){	
			found = false;
			done = true;
		}
		else if (info > walker->info)
			walker = walker->rightChild;
		else if (info < walker->info)
			walker = walker->leftChild;
		else {
			found = true;
			done = true;
		}
	}
	return found;
}

template<typename T>
int  BinarySearchTree<T>::getNrOfNodes() const {
	return nrOfNodes;
}

template<typename T>
int BinarySearchTree<T>::getSortR(T result[], int i, Node* walker) const {
	// Left to right

	// Left
	if (walker->leftChild != nullptr){
		i =  getSortR(result, i, walker->leftChild);
	}
	result[i] = walker->info;
	i++;
	if (walker->rightChild != nullptr){
		i = getSortR(result, i, walker->rightChild);
	}
	return i;
}

template<typename T>
void BinarySearchTree<T>::getContentSorted(T result[], int n) const {
	getSortR(result, 0, this->root);
}