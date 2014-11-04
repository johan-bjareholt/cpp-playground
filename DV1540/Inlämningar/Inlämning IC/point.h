#ifndef POINTH
#define POINTH

#include <cmath>
#include <string>

class Point {
private:
	int x, y;
	int index;
	void setIndex();
public:
	Point();
	Point(int,int);
	int getIndex();
	static int nextindex;
	std::string info();
	// Coordinates management
	int getX();
	int getY();
	void setCoordinates(int,int);
	float distance(Point*);
	float distance(float,float);
};

#endif