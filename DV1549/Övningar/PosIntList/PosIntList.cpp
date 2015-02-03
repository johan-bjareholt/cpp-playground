#include "PosIntList.h"

PosIntList::PosIntList(){
	first = nullptr;
	nrOfNodes = 0;
}

PosIntList::PosIntList(const PosIntList& list){
	first = nullptr;
	nrOfNodes = 0;
	append(list);
}

PosIntList::~PosIntList() {
	clear();
}

PosIntList& PosIntList::operator=(const PosIntList& list){
	clear();
	append(list);
}

void PosIntList::append(const PosIntList& list){
	first = nullptr;

	for (int i=0; i<list.size(); i++)
		insertLast(list.elementAt(i));
}

void PosIntList::clear(){
	Node* n = first;
	for (int i=0; i<nrOfNodes; i++){
		Node* toDelete = n;
		n = n->next;
		delete toDelete;
	}
	nrOfNodes = 0;
	first = nullptr;
}

void PosIntList::insertLast(int value){
	// Create new node
	Node* newNode = new Node(value);
	// In case there is no first yet
	if (first == nullptr)
		first = newNode;
	else
	{
		// Iterate to last
		Node* n = first;
		for (int i=0; i<nrOfNodes-1; i++){
			n = n->next;
		}
		// Assign new node to the last elements pointer
		n->next = newNode;
	}
	// Add node to count
	nrOfNodes++;
}

void PosIntList::insertAt(int pos, int value) throw() {
	if ( pos < 0 || pos >= nrOfNodes){
		throw "Position not allowed!";
	}
	// Create new node
	Node* n = new Node(value);
	// Get the node before the pos
	if (pos == 0){
		n->next = first;
		first = n;
	}
	else {
		Node* nbefore = first;
		for (int i=0; i<pos-1; i++){
			nbefore = nbefore->next;
		}
		// Save node after and add it to the new nodes next pointer
		n->next = nbefore->next;
		// Replace old ptr at pos with new one
		nbefore->next = n;
	}
	// Add node to count
	nrOfNodes++;
}

void PosIntList::insertFirst(int value) throw() {
	// Create new node by value
	Node* n = new Node(value);
	// Set old first as next ptr on new first node
	n->next = first;
	// Set new first node as first
	first = n;
	// Add node to count
	nrOfNodes++;
}

int PosIntList::elementAt(int pos) const throw() {
	if ( first==NULL )
		throw "Cannot get element from an empty list!";
	if ( pos < 0 || pos >= nrOfNodes)
		throw "Position not allowed!";
	// Make sure so the pos isn't higher than the amount of nodes
	if (pos >= nrOfNodes)
		pos = nrOfNodes-1;
	// Iterate to the element
	Node* n = first;
	for (int i=0; i<pos; i++){
		n = n->next;
	}
	// Return the elements value
	return n->value;
}

int PosIntList::removeFirst() throw() {
	if ( first == NULL ){
		throw "Cannot remove from empty list!";
	}
	// Save pointer and replace first with second
	Node* old = first;
	first = first->next;
	// Remember value to return
	int oldval = old->value;
	// Delete it
	delete old;
	// Remove node from count
	nrOfNodes--;
	return oldval;
}

int PosIntList::removeLast() throw() {
	if ( first == NULL ){
		throw "Cannot remove from empty list!";
	}
	Node* n = first;
	// Go to last node
	for (int i=0; i<nrOfNodes-2; i++)
		n = n->next;
	// Remember its value to return before deletion
	int val = n->next->value;
	// Finally remove n
	delete n->next;
	// Remove node from count
	nrOfNodes--;
	return val;
}

int PosIntList::removeAt(int pos) throw() {
	if ( first == NULL )
		throw "Cannot remove from empty list!";
	if ( pos >= nrOfNodes || pos < 0 )
		throw "Cannot remove index out of array!";

	Node* n = first;
	int value;
	if ( pos == 0){
		first = first->next;
		value = n->value;
		delete n;
	}
	else {
		for (int i=0; i<pos-1; i++)
			n = n->next;
		Node* toDelete = n->next;
		n->next = n->next->next;
		value = toDelete->value;
		delete toDelete;
	}
	nrOfNodes--;
	return 0;
}

int PosIntList::size() const {
	return nrOfNodes;
}