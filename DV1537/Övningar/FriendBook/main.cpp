#include <iostream>

#include "friendbook.h"

using namespace std;

string inputDialog(string question){
	string input;
	cin.ignore();
	cin.clear();
	cout << question;
	getline(cin, input);
	return input;
}


void editFriend(FriendBook& myFriends){
	bool done=false;
	string name = inputDialog("Namn: ");

	Friend* f = myFriends.find(name);
	if (f!=NULL){
		char choice;
		string temp;
		do {
			cout << "1. Ändra namn" << endl;
			cout << "2. Ändra nummer" << endl;
			cout << "3. Ta bort vän" << endl;
			cout << "q. tillbaka" << endl;
			cin >> choice;
			switch (choice){
				case '1':
					cin.ignore();cin.clear();
					getline(cin, temp);
					f->setName(temp);
					break;
				case '2':
					cin.ignore();cin.clear();
					cout << "New number: ";
					getline(cin, temp);
					f->setNumber(temp);
					break;
				case 'q':
					done=true;
					break;
				default:
					cout << "Ogiltigt alternativ" << endl;
			}
		} while(!done);
	}
	else {
		cout << "Kunde inte hitta någon vän med namnet " << name << endl;
	}
}

void showFriendsSorted(FriendBook& myFriends){
	/*
	FriendBook sortedFriends = FriendBook(myFriends);
	sortedFriends.sort();
	cout << sortedFriends.listFriends();
	*/
	myFriends.sort();
	cout << myFriends.listFriends();
}

int main(){
	bool running=true;

	FriendBook myFriends = FriendBook();

	string input;

	char choice;
	do {
		cout << "1. Lägg till vän" << endl;
		cout << "2. Ta bort vän" << endl;
		cout << "3. Redigera vän" << endl;
		cout << "4. Visa alla vänner" << endl;
		cout << "5. Visa alla vänner sorterade" << endl;
		cout << "6. Spara vänner" << endl;
		cout << "7. Ladda vänner" << endl;
		cout << "q. Avsluta" << endl;
		cout << "> ";
		cin >> choice;
		switch (choice){
			case '1':
				input = inputDialog("Namn: ");
				myFriends.addFriend(input);
				break;
			case '2':
				input = inputDialog("Namn: ");
				myFriends.deleteFriend(input);
				break;
			case '3':
				editFriend(myFriends);
				break;
			case '4':
				cout << myFriends.listFriends();
				break;
			case '5':
				showFriendsSorted(myFriends);
				break;
			case '6':
				myFriends.save();
				break;
			case '7':
				myFriends.load();
				break;
			case 'q':
				running=false;
				break;
			default:
				cout << "Ogiltigt alternativ" << endl;
		}
	}
	while (running);
}