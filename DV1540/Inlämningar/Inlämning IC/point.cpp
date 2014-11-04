#include "point.h"

#include <sstream>

int Point::nextindex = 0;

Point::Point(){
	this->setCoordinates(x, y);
}

Point::Point(int x, int y){
	this->setCoordinates(x, y);
	this->setIndex();
}

void Point::setIndex(){
	this->index = nextindex;
	this->nextindex++;
}

int Point::getIndex(){
	return this->index;
}

std::string Point::info () {
	std::stringstream info;
	info << "Punkt " << this->index+1;
	info << "(" << this->x << "," << this->y << ")";
	return info.str();
}

/*

	Coordinate handling

*/

int Point::getX () {
	return this->x;
}

int Point::getY () {
	return this->y;
}

void Point::setCoordinates(int x, int y){
	this->x = x;
	this->y = y;
}

float Point::distance(Point* targetPoint){
	return sqrt(
		pow(getX()-targetPoint->getX(), 2)
		+
		pow(getY()-targetPoint->getY(), 2)
		);
}

float Point::distance(float x, float y){
	return sqrt(
		pow(getX()-x, 2)
		+
		pow(getY()-y, 2)
		);
}