#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question {
protected:
	std::string question;
	static const int MAXCHOICES = 6;
	std::string choice[MAXCHOICES];
	int choicecount;
	int answer;
public:
	Question(std::string);
	virtual void addChoice(std::string, bool);
	bool rightChoice(int);
	void changeAnswer(int);
	std::string getQuestion();
	virtual std::string showChoices()=0;
};

#endif