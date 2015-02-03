#include "dialogs.h"


void addPlayerDialog(TeamHandler& th){
	std::string name,
				position;
	int shirtnumber;

	std::cin.ignore(); std::cin.clear();
	std::cout << "Name: ";
	std::getline(std::cin, name);
	std::cout << "Position: ";
	std::getline(std::cin, position);
	std::cout << "Shirtnumber: ";
	std::cin >> shirtnumber;

	th.addPlayer(name, shirtnumber, position);
}

void addLeaderDialog(TeamHandler& th){
	std::string name,
				job;
	int shirtnumber;

	std::cin.ignore(); std::cin.clear();
	std::cout << "Name: ";
	std::getline(std::cin, name);
	std::cout << "Job: ";
	std::getline(std::cin, job);

	th.addLeader(name, job);
}

void playerInfoDialog(TeamHandler& th){
	std::string name;

	std::cin.ignore();std::cin.clear();
	std::cout << "Name: ";
	std::getline(std::cin, name);

	TeamMember* member = th.getMember(name);

	if (member!=NULL){
		std::cout << member->toStr();
	}
	else {
		std::cout << "Could not find member with name " << name << std::endl;
	}
}

void changePlayerShirtNumberDialog(TeamHandler& th){
	std::string name;

	std::cin.ignore();std::cin.clear();
	std::cout << "Name: ";
	std::getline(std::cin, name);

	int newshirtnum;
	std::cout << "New shirt number: ";
	std::cin >> newshirtnum;

	if (!th.changeShirtNumber(name, newshirtnum))
		std::cout << "Couldn't find a player with the name " << name << std::endl;
}

void removeMemberDialog(TeamHandler& th){
	std::string name;

	std::cin.ignore(); std::cin.clear();
	std::cout << "Name: ";
	std::getline(std::cin, name);

	th.removeMember(name);
}