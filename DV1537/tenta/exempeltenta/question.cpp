#include "question.h"

Question::Question(std::string question){
	this->question = question;
	choicecount = 0;
}

void Question::addChoice(std::string choice, bool correct){
	if (choicecount < MAXCHOICES){
		this->choice[choicecount] = choice;
		if (correct)
			rightChoice(choicecount);
		choicecount++;
	}
}

bool Question::rightChoice(int choice){
	bool result;
	if (choice == answer)
		result = true;
	else
		result = false;
	return result;
}

void Question::changeAnswer(int answer){
	if (answer < choicecount)
		this->answer = answer;
}

std::string Question::getQuestion(){
	return choice[answer];
}