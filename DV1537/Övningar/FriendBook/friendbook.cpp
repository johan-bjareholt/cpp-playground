#include "friendbook.h"

#include <sstream>
#include <fstream>

#include <iostream>

using namespace std;

FriendBook::FriendBook(){
	this->nextid = 0;
	this->friends = new Friend*[MAXFRIENDAMOUNT];
}


FriendBook::FriendBook(const FriendBook& friendbook){
	this->friends = new Friend*[MAXFRIENDAMOUNT];
	this->nextid = friendbook.nextid;
	for (int i=0; i<nextid; i++){
		cout << friendbook.friends[i]->getName() << endl;
		this->friends[i] = new Friend(*friendbook.friends[i]);
	}
}

FriendBook::~FriendBook(){
	for (int i=0; i<nextid; i++){
		delete this->friends[i];
	}
	delete[] this->friends;
}

void FriendBook::addFriend(string name){
	this->friends[nextid] = new Friend(nextid, name);
	this->nextid++;
}

bool FriendBook::deleteFriend(string name){
	bool success=true;
	Friend* myfriend = this->find(name);
	if (myfriend!=NULL){
		this->nextid--;
		for (int i=myfriend->getID(); i<nextid; i++){
			friends[i] = friends[i+1];
			friends[i]->setID(i);
		}
		delete myfriend;
	}
	else 
		success = false;
	return success;
}

string FriendBook::listFriends(){
	stringstream ss;
	for (int i=0; i<nextid; i++){
		std::cout << "id: " << i << "\t";
		std::cout << "namn: " << friends[i]->getName() << endl;
		ss << friends[i]->infoStr() << endl;
	}
	return ss.str();
}

Friend* FriendBook::find(string name){
	for(int i=0; i<nextid; i++){
		if (friends[i]->getName() == name)
			return friends[i];
	}
	return NULL;
}

void FriendBook::sort(){
	for (int max=nextid; max>1; max--){
		for (int i=0; i<max; i++){
			if (friends[i]>friends[i+1]){
				Friend* temp = new Friend(friends[i+1]);
				friends[i+1] = friends[i];
				friends[i] = temp;
				i--;
			}
		}
	}
}

void FriendBook::save(){
	ofstream file;
	file.open(SAVEFILE);
	for (int i=0; i<nextid; i++){
		file << friends[i]->infoCsv() << endl;
	}
	file.close();
}

void FriendBook::load(){
	ifstream file;
	file.open(SAVEFILE);
	string name;
	string bday;
	string number;
	do {
		getline(file, name, ',');
		getline(file, bday, ',');
		getline(file, number);
		if (name != ""){
			friends[nextid] = new Friend(nextid, name, bday, number);
			nextid++;
		}
	} while(file.good());
}