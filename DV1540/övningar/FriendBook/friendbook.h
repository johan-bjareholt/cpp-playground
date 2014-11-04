#ifndef FRIENDBOOK_H
#define FRIENDBOOK_H

#include "friend.h"

#include <string>

const int MAXFRIENDAMOUNT = 100;
const string SAVEFILE = "friends.csv";

class FriendBook
{
private:
	Friend friends[MAXFRIENDAMOUNT];
public:
	static int nextid;
	FriendBook();
	void addFriend(string);
	string listFriends();
	Friend* find(string);
	void sort();
	void save();
	void load();
};

#endif