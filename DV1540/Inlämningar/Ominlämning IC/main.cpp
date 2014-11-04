#include <iostream>
#include <string>
#include <ctime>

#include "turtle.h"

using namespace std;

void inputAndSetNames(Turtle turtles[],int nrOfTurtles){
	string name;
	cout << "Mata in namnen på de " << nrOfTurtles << " tävlande" << endl;
	cin.ignore();cin.clear();
	for (int n=0; n<nrOfTurtles; n++){
		getline(cin, name);
		turtles[n].setName(name);
	}
} 

void makeMove(Turtle turtles[],int nrOfTurtles){
	for (int n=0; n<nrOfTurtles; n++){
		turtles[n].move();
	}
}

void showAll(Turtle turtles[],int nrOfTurtles){
	for (int n=0; n<nrOfTurtles; n++){
		cout << turtles[n].getName() << " är på position " << turtles[n].getPos() << endl;
	}
}

int winner(Turtle turtles[],int nrOfTurtles, int pathLength){
	for (int n=0; n<nrOfTurtles; n++){
		if (turtles[n].arrivedAtPos(pathLength)){
			return n;
		}
	}
	return -1;
}

void waitForEnter(){
	/* 
		Alternativ 1
	*/
	#ifdef _WIN32 // Windows
	system("pause");
	#else // Unix-like operatingsystems
	system("read");
	#endif
	/* 
		Alternativ 2
		Funkar cross platform och behöver inte kalla systemets shell och är därmed säkrare
	*/
	/*
	cin.ignore();
	cin.clear();
	cin.get();
	*/
}

int main(){
	srand(time(NULL));

	// Ask for amount of turtles
	int nrOfTurtles;
	cout << "Hur många sköldpaddor? ";
	cin >> nrOfTurtles;
	// Create turtles
	Turtle turtles[nrOfTurtles];
	// Ask for names of the turtles
	inputAndSetNames(turtles, nrOfTurtles);
	// Ask for path length
	int pathLength;
	cout << "Hur lång bana? ";
	cin >> pathLength;

	int winnern;
	int rounds = 0;
	// Do rounds until someone is in goal
	do {
		rounds++;
		cout << "Omgång " << rounds << endl;
		makeMove(turtles, nrOfTurtles);
		// Gets winner arraypos if someone has won, else returns -1
		winnern = winner(turtles, nrOfTurtles, pathLength);
		// Print turtle positions
		showAll(turtles, nrOfTurtles);
		// Wait until user presses a key
		waitForEnter();
	} while (winnern<0);
	cout << turtles[winnern].getName() << " segrade efter " << rounds << " omgångar" << endl;
}