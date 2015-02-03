#ifndef TEAMHANDLER_H
#define TEAMHANDLER_H

#include "teammember.h"
#include "teamplayer.h"
#include "teamleader.h"

class TeamHandler {
	TeamMember** members;
	int size;
	int membercount;

	void expand(); // Expands array by 10
	void deleteMember(int); // Deletes member from memory, but does not remove from array

public:
	TeamHandler();
	TeamHandler(TeamHandler&);
	~TeamHandler();
	void operator=(TeamHandler&);
	// Creation
	const bool addPlayer(std::string, int, std::string);
	const bool addLeader(std::string, std::string);
	// Deletion
	void removeMember(int); // Calls deleteMember to delete member by index, then removes from array
	void removeMember(std::string name); // Calls deleteMember to delete member by name, then removes from array
	// Information
	const std::string allMembersStr(); // Returns a string of all members
	const std::string allPlayersStr(); // Returns a string of all players
	const std::string allLeadersStr(); // Returns a string of all leaders
	// Access
	TeamMember* getMember(std::string); // Get member by name, returns null if there's no member with that name
	bool changeShirtNumber(std::string, int); // Changes players shirt number by name

};

#endif