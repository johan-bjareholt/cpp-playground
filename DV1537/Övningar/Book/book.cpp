#include "book.h"
#include <iostream>

using namespace std;

Book::Book()
{
	this->title = "nothing";
	this->publYear = -1;
}

Book::Book(std::string title, int publYear)
{
	this->title = title;
	this->publYear = publYear;
}

void Book::setTitle(std::string title)
{
	this->title = title;
}

void Book::setPublYear(int publYear)
{
	this->publYear = publYear;
}

string Book::getTitle() const
{
	return this->title;
}

int Book::getPublYear() const
{
	return this->publYear;
}

void Book::print() const
{
	cout<<this->title<<" publicerad "<<this->publYear<<endl;
}