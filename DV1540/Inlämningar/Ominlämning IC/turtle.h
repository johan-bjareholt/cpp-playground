#ifndef TURTLE_H
#define TURTLE_H

#include <string>

using namespace std;

class Turtle {
private:
	int pos;
	string name;
public:
	Turtle();
	void setName(string);
	string getName();
	void move();
	int getPos();
	bool arrivedAtPos(int);
};

#endif