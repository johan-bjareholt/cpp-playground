#include <iostream>

#include "friendbook.h"

using namespace std;

void editFriend(FriendBook& myFriends){
	bool done=false;
	string name;

	cin.ignore(); cin.clear();
	getline(cin, name);

	Friend* f = myFriends.find(name);
	if (f!=NULL){
		char choice;
		string temp;
		do {
			cout << "1. Change name" << endl;
			cout << "2. asd" << endl;
			cout << "b. back" << endl;
			cin >> choice;
			switch (choice){
				case '1':
					cin.ignore();cin.clear();
					getline(cin, temp);
					f->setName(temp);
					break;
				case '2':
					cin.ignore();cin.clear();
					getline(cin, temp);
					f->setNumber(temp);
					break;
				case 'b':
					done=true;
					break;
				default:
					cout << "Invalid choice" << endl;
			}
		} while(!done);
	}
	else {
		cout << "Could not find any friend named " << name << endl;
	}
}

void addFriendDialog(FriendBook& myFriends){
	string name;
	cin.ignore();
	cin.clear();
	cout << "Namn: ";
	getline(cin, name);
	myFriends.addFriend(name);
}

int main(){
	bool running=true;

	FriendBook myFriends = FriendBook();

	char choice;
	do {
		cout << "1. Add friend" << endl;
		cout << "2. Edit friend" << endl;
		cout << "3. List friends" << endl;
		cout << "4. Sort friends" << endl;
		cout << "5. Save friends" << endl;
		cout << "6. Load friends" << endl;
		cout << "q. Quit" << endl;
		cin >> choice;
		switch (choice){
			case '1':
				addFriendDialog(myFriends);
				break;
			case '2':
				editFriend(myFriends);
				break;
			case '3':
				cout << myFriends.listFriends();
				break;
			case '4':
				myFriends.sort();
				break;
			case '5':
				myFriends.save();
				break;
			case '6':
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