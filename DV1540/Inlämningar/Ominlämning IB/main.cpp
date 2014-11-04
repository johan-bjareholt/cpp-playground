#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

const int CARDAMOUNT = 52;
const int HANDSIZE = 12;
const int PLAYERAMOUNT = 2;

bool yesOrNo(){
	char choice;
	bool result;
	bool validchoice = false;
	while (!validchoice) {
		cin >> choice;
		switch (choice){
			case 'j':
			case 'J':
				result = true;
				validchoice = true;
				break;
			case 'n':
			case 'N':
				result = false;
				validchoice = true;
				break;
			default:
				cout << "Ogiltigt alternativ, ja eller nej (j/n)? ";
		}
	}
	return result;
}

int drawCard(int hand[], int deck[], int cardIndex){
	int card;
	do {
		card = rand() % CARDAMOUNT;
	} while (deck[card] == 0);
	hand[cardIndex] = deck[card];
	deck[card] = 0;

	return hand[cardIndex];
}

int handSum(int hand[], int cardsdrawn){
	int sum=0;
	for (int i=0; i<cardsdrawn; i++){
		sum += hand[i];
	}
	return sum;
}

void getPlayernames(string names[]){
	cout << "Mata in namnet på spelare 1: ";
	getline(cin, names[0]);
	cout << "Mata in namnet på spelare 2: ";
	getline(cin, names[1]);
}

void saveScore(string name1, int points1, string name2, int points2){
	ofstream file;
	// Open up results file
	file.open("resultat.txt");
	// Write score to file
	file << name1 << " " << points1 <<" segrar" << endl;
	file << name2 << " " << points2 <<" segrar" << endl;
	// Close file
	file.close();
}

void clearScreen(){
	#ifdef _WIN32 // Om det är windows
	system("CLS");
	#else // Om det är något unix liknande/kör bash
	system("clear");
	#endif
}

int main(){
	// Initialize rand seed
	srand(time(NULL));

	clearScreen();

	// Ask for names
	string name[PLAYERAMOUNT];
	getPlayernames(name);

	// Scores
	int player1wins = 0;
	int player2wins = 0;

	// Card drawing
	bool play=true;
	do {
		// Initialize deck
		int deck[CARDAMOUNT];
		for (int color=0; color<4; color++){
			for (int cardval=1; cardval<=13; cardval++){
				deck[(color*13)+(cardval-1)] = cardval;
			}
		}
		// Initialize hands
		int hand1[HANDSIZE];
		int hand2[HANDSIZE];
		int hand1cardsdrawn = 0;
		int hand2cardsdrawn = 0;
		bool hand1full=false;
		bool hand2full=false;

		clearScreen();
		// Card drawing
		bool player1draw;
		bool player2draw;
		do {
			player1draw = false;
			player2draw = false;
			if (!hand1full){
				// Player 1 turn
				cout << name[0] << "s kortsumma är " << handSum(hand1, hand1cardsdrawn) << ", vill du dra ett kort till (j/n)? ";
				player1draw = yesOrNo();
				if (player1draw==true){
					// Draw card
					int cardval = drawCard(hand1, deck, hand1cardsdrawn);
					cout << name[0] << " drog ett kort som ger " << cardval << " poäng" << endl;
					hand1cardsdrawn++;
					int cardsum = handSum(hand1, hand1cardsdrawn);
					cout << name[0] << "s nya poäng är " << cardsum << endl;
					// If full, end player
					if (cardsum > 21){
						hand1full = true;
						cout << name[0] << " blev tjock!" << endl;
					}
				}
				cout << endl;
			}
			if (!hand2full){
				// Player 2 turn
				cout << name[1] << "s kortsumma är " << handSum(hand2, hand2cardsdrawn) << ", vill du dra ett kort till (j/n)? ";
				player2draw = yesOrNo();
				if (player2draw==true){
					// Draw card
					int cardval = drawCard(hand2, deck, hand2cardsdrawn);
					cout << name[1] << " drog ett kort som ger " << cardval << " poäng" << endl;
					hand2cardsdrawn++;
					int cardsum = handSum(hand2, hand2cardsdrawn);
					cout << name[1] << "s nya poäng är " << cardsum << endl;
					// If full, end player
					if (cardsum > 21){
						hand2full = true;
						cout << name[1] << " blev tjock!" << endl;
					}
				}
				cout << endl;
			}
		} 
		while (player1draw==true || player2draw==true);

		// Gather results
		int hand1sum = handSum(hand1, hand1cardsdrawn);
		int hand2sum = handSum(hand2, hand2cardsdrawn);
		// Congratulate winner
		if ((hand1sum > hand2sum && hand1sum <= 21) || hand2sum > 21){
			cout << name[0] << " van med " << hand1sum << " mot " << hand2sum << "!" << endl;
			player1wins++;
		}
		else if ((hand2sum > hand1sum && hand2sum <= 21) || hand1sum > 21){
			cout << name[1] << " van med " << hand2sum << " mot " << hand1sum << "!" << endl;
			player2wins++;
		}
		else {
			cout << "Det blev lika!" << endl;
		}

		cout << "Vill ni spela igen (j/n)? ";
		play = yesOrNo();
		clearScreen();
	} while (play==true);

	saveScore(name[0], player1wins, name[1], player2wins);
}