#ifndef POSINTLIST_H
#define POSINTLIST_H
#include <cstdlib>

using namespace std;

class PosIntList
{
private:
	class Node
	{
	public:
		int value;
		Node *next;
		Node(int value){ this->value = value; this->next = NULL;}
		~Node() {}
	};
	
	Node *first;
	int nrOfNodes;
	void append(const PosIntList&);
	void clear();
public:
	PosIntList();
	PosIntList(const PosIntList& list);
	virtual ~PosIntList();
	PosIntList& operator=(const PosIntList& list);
	void insertLast(int value);
	void insertAt(int pos, int value) throw() ;
	void insertFirst(int value) throw() ;
	int elementAt(int pos) const throw();
	int removeFirst() throw();
	int removeLast() throw();
	int removeAt(int pos) throw();
	int size() const;
};

#endif