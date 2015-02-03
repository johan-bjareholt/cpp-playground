#include <iostream>
#include <string>

#include "teamhandler.h"

#include "dialogs.h"

int main(){
	bool running = true;

	TeamHandler th;
	
	/*
		Default test members, comment if you want to start from scratch
	*/
	// Players
	th.addPlayer("Kalle", 20, "Back");
	th.addPlayer("Lars", 1, "Goalie");
	th.addPlayer("Filippa", 5, "Fourward");
	// Leaders
	th.addLeader("Pär", "Chef");

	// TeamHandler copying tests, uncomment if you want to try that memory management works correctly
	/*
	TeamHandler th2 (th);
	TeamHandler th3;
	th3.addPlayer("test",1,"asd");
	th3 = th2;
	*/

	char choice;
	do {
		std::cout 	<< "1. Present all members" << std::endl
					<< "2. Present member by name" << std::endl
					<< "3. Change shirt number of player by name" << std::endl
					<< "4. Present all players" << std::endl
					<< "5. Present all leaders" << std::endl
					<< "6. Add player" << std::endl
					<< "7. Add leader" << std::endl
					<< "8. Remove a member by name" << std::endl
					<< "q. Quit" << std::endl
					<< "choice: ";
		std::cin >> choice;
		switch(choice){
			case '1':
				std::cout << th.allMembersStr();
				break;
			case '2':
				playerInfoDialog(th);
				break;
			case '3':
				changePlayerShirtNumberDialog(th);
				break;
			case '4':
				std::cout << th.allPlayersStr();
				break;
			case '5':
				std::cout << th.allLeadersStr();
				break;
			case '6':
				addPlayerDialog(th);
				break;
			case '7':
				addLeaderDialog(th);
				break;
			case '8':
				removeMemberDialog(th);
				break;
			case 'q':
				running = false;
				break;
			default:
				std::cout << "Ogiltigt alternativ" << std::endl;
		}
	} while (running);
}