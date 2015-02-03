#ifndef TEAMMEMBER_H
#define TEAMMEMBER_H

#include <string>

class TeamMember {
private:
	std::string name;
	int number;
public:
	TeamMember(std::string, int);
	TeamMember(TeamMember&);
	virtual ~TeamMember();

	const std::string getName();
	void setName(std::string);
	const int getNumber();
	void setNumber(int);

	const std::string toStr();
	virtual const std::string infoStr()=0;
};

#endif