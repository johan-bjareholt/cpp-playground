#include <sstream>

#include "teammember.h"

TeamMember::TeamMember(std::string name, int number){
	this->name = name;
	this->number = number;
}

TeamMember::TeamMember(TeamMember& other){
	this->name = other.name;
	this->number = other.number;
}

TeamMember::~TeamMember(){
	
}

const std::string TeamMember::getName(){
	return this->name;
}

void TeamMember::setName(std::string name){
	this->name = name;
}

const int TeamMember::getNumber(){
	return this->number;
}

void TeamMember::setNumber(int number){
	this->number = number;
}

const std::string TeamMember::toStr(){
	std::stringstream ss;
	ss << this->number << ". " << this->name << std::endl << this->infoStr();
	return ss.str();
}