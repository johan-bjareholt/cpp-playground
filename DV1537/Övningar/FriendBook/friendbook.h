#ifndef FRIENDBOOK_H
#define FRIENDBOOK_H

#include "friend.h"

#include <string>

const int MAXFRIENDAMOUNT = 100;
const string SAVEFILE = "friends.csv";

class FriendBook
{
private:
	Friend** friends;
public:
	int nextid;
	FriendBook();
	FriendBook(const FriendBook&);
	~FriendBook();
	void addFriend(string);
	bool deleteFriend(string);
	string listFriends();
	Friend* find(string);
	void sort();
	void save();
	void load();
	FriendBook operator=(const FriendBook&);
};

#endif