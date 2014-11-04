#include "turtle.h"

Turtle::Turtle(){
	this->pos = 0;
}

void Turtle::setName(string name){
	this->name = name;
}

string Turtle::getName(){
	return this->name;
}

void Turtle::move(){
	this->pos += rand()%4+1;
}

int Turtle::getPos(){
	return this->pos;
}

bool Turtle::arrivedAtPos(int targetPos){
	if (this->pos >= targetPos)
		return true;
	else
		return false;
}