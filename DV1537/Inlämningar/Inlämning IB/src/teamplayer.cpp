#include <sstream>

#include "teamplayer.h"

TeamPlayer::TeamPlayer(std::string name, int number, int shirtnumber, std::string position) : TeamMember(name, number) {
	this->shirtnumber = shirtnumber;
	this->position = position;
}

TeamPlayer::TeamPlayer(TeamPlayer& other) : TeamMember(other){
	this->shirtnumber = other.shirtnumber;
	this->position = other.shirtnumber;
}

TeamPlayer::~TeamPlayer(){
	
}

const std::string TeamPlayer::getPosition(){
	return this->position;
}

void TeamPlayer::setPosition(std::string position){
	this->position = position;
}

const int TeamPlayer::getShirtNumber(){
	return this->shirtnumber;
}

void TeamPlayer::setShirtNumber(int shirtnumber){
	this->shirtnumber = shirtnumber;
}

const std::string TeamPlayer::infoStr(){
	std::stringstream ss;
	ss << "\tShirtnumber: " << this->shirtnumber << std::endl
	   << "\tPosition: " << this->position << std::endl;
	return ss.str();
}