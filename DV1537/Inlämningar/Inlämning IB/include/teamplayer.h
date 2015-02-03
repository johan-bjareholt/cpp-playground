#ifndef TEAMPLAYER_H
#define TEAMPLAYER_H

#include "teammember.h"

class TeamPlayer : public TeamMember {
private:
	std::string position;
	int shirtnumber;
public:
	TeamPlayer(std::string, int, int, std::string);
	TeamPlayer(TeamPlayer&);
	~TeamPlayer();

	const std::string getPosition();
	void setPosition(std::string);
	const int getShirtNumber();
	void setShirtNumber(int);

	const std::string infoStr();
};

#endif