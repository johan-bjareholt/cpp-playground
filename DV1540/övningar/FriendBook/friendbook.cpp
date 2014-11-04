#include "friendbook.h"

#include <sstream>
#include <fstream>

using namespace std;

int FriendBook::nextid = 0;

FriendBook::FriendBook(){

}

void FriendBook::addFriend(string name){
	this->friends[nextid].setName(name);
	this->friends[nextid].setID(nextid);
	this->nextid++;
}

string FriendBook::listFriends(){
	stringstream ss;
	for (int i=0; i<nextid; i++){
		ss << friends[i].infoStr() << endl;
	}
	return ss.str();
}

Friend* FriendBook::find(string name){
	for(int i=0; i<nextid; i++){
		if (friends[i].getName() == name)
			return &friends[i];
	}
	return NULL;
}

void FriendBook::sort(){
	for (int max=nextid; max>1; max--){
		for (int i=0; i<max; i++){
			if (friends[i]>friends[i+1]){
				Friend temp = friends[i+1];
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
		file << friends[i].infoCsv() << endl;
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
			friends[nextid] = Friend(nextid, name, bday, number);
			nextid++;
		}
	} while(file.good());
}