#include <sstream>

#include "yesnoquestion.h"

YesNoQuestion::YesNoQuestion(std::string question, bool answer) : Question(question) {
	this->addChoice("Yes", false);
	this->addChoice("No", false);
	changeAnswer(!answer);
}

std::string YesNoQuestion::showChoices(){
	std::stringstream ss;
	ss << "1. " << choice[0] << std::endl;
	ss << "2. " << choice[1] << std::endl;
	return ss.str();
}