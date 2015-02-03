#include <sstream>

#include "teamhandler.h"

TeamHandler::TeamHandler() {
	this->membercount = 0;
	this->size = 10;
	this->members = new TeamMember*[size];
}

TeamHandler::TeamHandler(TeamHandler& origin){
	// Set variables from origin
	this->membercount = origin.membercount;
	this->size = origin.size;
	// Create new array with the same size as origin
	this->members = new TeamMember*[size];
	// Create duplicates of origins members
	for (int i=0; i<membercount; i++){
		TeamLeader* tl = dynamic_cast<TeamLeader*>(origin.members[i]);
		if (tl != nullptr)
			this->members[i] = new TeamLeader(*tl);
		else {
			TeamPlayer* tp = dynamic_cast<TeamPlayer*>(origin.members[i]);
			this->members[i] = new TeamPlayer(*tp);
		}
	}
}

TeamHandler::~TeamHandler() {
	// Deletes all members and array
	for (int i=0; i<membercount; i++){
		deleteMember(i);
	}
	delete[] this->members;
}

void TeamHandler::operator=(TeamHandler& origin){
	// delete all members and array
	for (int i=0; i<membercount; i++){
		deleteMember(i);
	}
	delete[] this->members;

	// Set variables from origin
	this->membercount = origin.membercount;
	this->size = origin.size;
	// Create new array with the same size as origin
	this->members = new TeamMember*[this->size];
	// Create duplicates of origins members
	for (int i=0; i<this->membercount; i++){
		TeamLeader* tl = dynamic_cast<TeamLeader*>(origin.members[i]);
		if (tl!=nullptr)
			this->members[i] = new TeamLeader(*tl);
		else {
			TeamPlayer* tp = dynamic_cast<TeamPlayer*>(origin.members[i]);
			this->members[i] = new TeamPlayer(*tp);
			if (tp != nullptr)
				delete tl;
		}
	}
}

// Expands array by 10
void TeamHandler::expand(){
	int size = this->size+10;
	TeamMember** members = new TeamMember*[size];
	for (int i=0; i<membercount; i++){
		members[i] = this->members[i];
	}
	delete[] this->members;
	this->members = members;
}

/*
	Creation
*/

const bool TeamHandler::addPlayer(std::string name, int shirtnumber, std::string position){
	this->members[membercount] = new TeamPlayer(name, membercount, shirtnumber, position);
	membercount++;
	if (membercount == size){
		this->expand();
	}
	return true;
}

const bool TeamHandler::addLeader(std::string name, std::string job){
	this->members[membercount] = new TeamLeader(name, membercount, job);
	membercount++;
	if (membercount >= size){
		this->expand();
	}
	return true;
}

/*
	Deletion
*/

// Deletes member from memory, but does not remove from array
void TeamHandler::deleteMember(int i){
	TeamPlayer* tp = dynamic_cast<TeamPlayer*>(members[i]);
	if (tp != nullptr){
		delete tp;
	}
	else {
		TeamLeader* tl = dynamic_cast<TeamLeader*>(members[i]);
		if (tl != nullptr)
			delete tl;
	}
}

// Calls deleteMember to delete member by index, then removes from array
void TeamHandler::removeMember(int index){
	deleteMember(index);
	membercount--;
	for (int i=index; i<membercount; i++){
		members[i] = members[i+1];
		members[i]->setNumber(i);
	}
}

// Calls deleteMember to delete member by name, then removes from array
void TeamHandler::removeMember(std::string name){
	TeamMember* member = getMember(name);
	if (member!=nullptr){
		removeMember(member->getNumber());
	}
}

/*
	Information
*/

// Returns a string of all members
const std::string TeamHandler::allMembersStr(){
	std::stringstream ss;
	for (int i=0; i<membercount; i++){
		ss << members[i]->toStr();
	}
	return ss.str();
}

// Returns a string of all players
const std::string TeamHandler::allPlayersStr(){
	std::stringstream ss;
	TeamPlayer* tp;
	for (int i=0; i<membercount; i++){
		tp = dynamic_cast<TeamPlayer*>(members[i]);
		if (tp)
			ss << tp->toStr();
	}
	return ss.str();
}

// Returns a string of all leaders
const std::string TeamHandler::allLeadersStr(){
	std::stringstream ss;
	TeamLeader* tl;
	for (int i=0; i<membercount; i++){
		tl = dynamic_cast<TeamLeader*>(members[i]);
		if (tl)
			ss << tl->toStr();
	}
	return ss.str();
}

/*
	Access
*/

// Get member by name, returns null if there's no member with that name
TeamMember* TeamHandler::getMember(std::string name){
	TeamMember* result = NULL;
	for (int i=0; i<membercount; i++){
		if (members[i]->getName() == name){
			result = members[i];
			i = membercount;
		}
	}
	return result;
}

bool TeamHandler::changeShirtNumber(std::string name, int newnumber){
	bool result;
	TeamMember* member = getMember(name);

	if (member!=nullptr){
		TeamPlayer* player = dynamic_cast<TeamPlayer*>(member);
		if (player != nullptr){
			player->setShirtNumber(newnumber);
			result = true;
		}
		else {
			result = false;
		}
	}
	else {
		result = false;
	}
	return result;
}