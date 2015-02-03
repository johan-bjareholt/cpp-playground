#include "question.h"

class YesNoQuestion : public Question {
public:
	YesNoQuestion(std::string, bool);
	std::string showChoices();
};