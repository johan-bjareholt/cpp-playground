#include <iostream>
#include <string>
#include <ctime>
#include <vector>

// Funktion för tärningskastning
int roll_dices(int rolls=1){
	int sum = 0;
	int roll1, roll2;
	// Gör dubbelkast
	for (int n=0; n<rolls; n++){
		roll1 = rand() % 6+1;
		roll2 = rand() % 6+1;
		std::cout << roll1 << " " << roll2 << " = " << roll1+roll2 << std::endl;
		sum += roll1 + roll2;
	}
	std::cout << "Summa: " << sum << std::endl;
	return sum;
}

int main(){
	// Genererar en seed till rand
	srand(time(NULL));

	bool running = true;

	std::cout << "Nu spelare vi \"Otur i tärning\"" << std::endl;

	// Fråga efter antal dubbelkast per spelare
	unsigned int rolls_per_player;
	std::cout << "Hur många tärningskast per spelare? ";
	std::cin >> rolls_per_player;

	// Variabel deklarering för spelare och förlorare
	unsigned int points, loserPoints = 0;
	std::string name, loserName;

	std::cin.ignore();
	// Lägg till spelare tills en spelare med namnet "slut" kommer
	while(running){
		std::cout << "Namn: ";
		std::getline(std::cin, name);
		if (name == "slut")
			running = false;
		else {
			// Kasta tärningar
			points = roll_dices(rolls_per_player);
			// Kolla om det är den nya förloraren
			if (points < loserPoints || loserPoints == 0){
				loserPoints = points;
				loserName = name;
			}
		}
	}
	// Resultat
	std::cout << "Förloraren är " << loserName << " med " << loserPoints << " poäng" << std::endl;
	return 0;
}