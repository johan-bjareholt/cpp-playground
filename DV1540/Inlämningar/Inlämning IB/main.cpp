#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <string>

const int PLAYERAMOUNT = 2;
const int BOARDSIZE = 15;

std::string playernames[PLAYERAMOUNT];
bool 	boats[PLAYERAMOUNT][BOARDSIZE];
short 	shots[PLAYERAMOUNT][BOARDSIZE];
int 	shipsleft[PLAYERAMOUNT];

void generateShips(int shipamount){
	for (int playeri=0; playeri<2; playeri++){
		shipsleft[playeri]  = shipamount;
		// Add board
		for (int boatn=0; boatn<shipamount; boatn++){
			int position = rand() % 15;
			// Check so there's not already a ship at that position
			while (boats[playeri][position])
				position = rand() % 15;
			boats[playeri][position] = true;
		}
	}
}

void pprintBoard(int playeri){
	for (int n=0; n<BOARDSIZE; n++){
		switch (shots[playeri][n]){
			case 0:
				std::cout << "-";
				break;
			case 1:
				std::cout << "0";
				break;
			case 2:
				std::cout << "X";
				break;
		}
	}
	std::cout << std::endl;
}

void shoot(int playeri, int position){
	if (boats[playeri][position]){
		shipsleft[playeri]--;
		boats[playeri][position] = false;
		shots[playeri][position] = 2;
		std::cout << "Skottet träffade!" << std::endl;
		pprintBoard(playeri);
	}
	else {
		shots[playeri][position] = 1;
		std::cout << "Skott missade!" << std::endl;
		pprintBoard(playeri);
	}
}


void clearScreen(){
	#ifdef _WIN32
	system("CLS");
	#else
	system("clear");
	#endif
}


int main(){
	srand(time(NULL));

	clearScreen();

	// Ask for shipamount
	std::cout << "Hur många skepp ska varje spelare ha? ";
	int shipamount;
	std::cin >> shipamount;
	generateShips(shipamount);


	// Create players
	std::cin.clear();std::cin.ignore();
	std::string name;
	
	std::cout << "Vad är första spelarens namn? ";
	std::getline(std::cin, name);
	playernames[0] = name;

	std::cout << "Vad är den andra spelarens namn? ";
	std::getline(std::cin, name);
	playernames[1] = name;

	int currentPlayer = 0;
	int otherPlayer = 1;

	// Shoot loop
	while (shipsleft[0]>0 && shipsleft[1]>0)
	{
		std::cout << std::endl << "Nu är det " << playernames[currentPlayer] << "'s tur" << std::endl;
		// Shoot
		std::cout << "Skjut: ";
		int shootposition;
		std::cin >> shootposition;
		// Must clear buffer, else it will loop forever if you input a character instead of a number
		std::cin.clear();std::cin.ignore();

		if (shootposition<15 && shootposition>=0)
		{
			shoot(otherPlayer, shootposition);

			// Change player
			if (currentPlayer == 0){
				currentPlayer = 1;
				otherPlayer = 0;
			}
			else {
				currentPlayer = 0;
				otherPlayer = 1;
			}
		}
		else 
		{
			std::cout << "Felaktigt alternativ, måste välja ett nummber mellan 0 och 14" << std::endl;
		}
	}

	clearScreen();

	int winner;
	if (shipsleft[0] > 0)
		winner = 0;
	else
		winner = 1;

	std::cout << "Och vinnaren är..." << std::endl << std::endl;
	std::cout << playernames[winner] << "!" << std::endl << std::endl << std::endl;
}