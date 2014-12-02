#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book
{
private:
	string title;
	int publYear;
public:
	Book();
	Book(string title, int publYear);
	void setTitle(string title);
	void setPublYear(int publYear);
	string getTitle() const;
	int getPublYear() const;
	void print() const;
};

#endif