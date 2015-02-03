#include <sstream>

#include "teamleader.h"

TeamLeader::TeamLeader(std::string name, int number, std::string job) : TeamMember(name, number){
	this->job = job;
}

TeamLeader::TeamLeader(TeamLeader& other) : TeamMember(other){
	this->job = other.job;
}

TeamLeader::~TeamLeader(){
	
}

const std::string TeamLeader::getJob(){
	return this->job;
}

void TeamLeader::setJob(std::string job){
	this->job = job;
}

const std::string TeamLeader::infoStr(){
	std::stringstream ss;
	ss  << "\tJob: " << this->job << std::endl;
	return ss.str();
}