#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include <string>

#include "teammember.h"

class TeamLeader : public TeamMember {
private:
	std::string job;
public:
	TeamLeader(std::string, int, std::string);
	TeamLeader(TeamLeader&);
	~TeamLeader();

	const std::string getJob();
	void setJob(std::string);

	const std::string infoStr();
};

#endif