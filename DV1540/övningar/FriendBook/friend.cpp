#include "friend.h"

#include <sstream>

// 0 = name
// 1 = bday
// 2 = number
int Friend::COMP = 0;

Friend::Friend(){
	this->bday = 0;
	this->number = "";
}

Friend::Friend(int id){
	this->id = id;
	this->bday = 0;
	this->number = "";
}

Friend::Friend(int id, string name){
	this->id = id;
	this->setName(name);
}

Friend::Friend(int id, string name, string bday, string number){
	this->id = id;
	this->name = name;
	this->number = number;
	this->bday = atoi(bday.c_str());
}

Friend::~Friend(){}

void Friend::setID(int id){
	this->id = id;
}

string Friend::infoStr(){
	stringstream ss;
	ss << this->id << ": ";
	ss << this->name;
	if (this->bday!=0)
		ss << "\n\t" << this->bday;
	if (this->number!="")
		ss << "\n\t" << this->number;
	return ss.str();
}
string Friend::infoCsv(){
	stringstream ss;
	ss << this->name << ',';
	ss << this->bday << ',';
	ss << this->number;
	return ss.str();
}

void Friend::setName(string name){
	this->name = name;
}

string Friend::getName(){
	return this->name;
}

void Friend::setBday(int day,int month,int year){
	this->bday = 0;
	if (day>0 && day<=31)
		this->bday = day;
	if (month>0 && month<=12)
		this->bday += month*100;
	if (year>1900 && year<=2014)
		this->bday += year*10000;
}

int Friend::getBday(){
	return this->bday;
}

void Friend::setNumber(string number){
	this->number = number;
}

string Friend::getNumber(){
	return this->number;
}

// Operators

bool Friend::operator==(Friend& otherFriend){
	bool ans=0;
	if (COMP==0)
		ans = (this->name == otherFriend.getName());
	else if (COMP==1)
		ans = (this->bday == otherFriend.getBday());
	else if (COMP==2)
		ans = (this->number == otherFriend.getNumber());
	return ans;
}

bool Friend::operator<(Friend& otherFriend){
	bool ans = 0;
	if (COMP==0)
		ans = (this->name < otherFriend.getName());
	else if (COMP==1)
		ans = (this->bday < otherFriend.getBday());
	else if (COMP==2)
		ans = (this->number < otherFriend.getNumber());
	return ans;
}
bool Friend::operator>(Friend& otherFriend){
	bool ans = 0;
	if (COMP==0)
		ans = (this->name > otherFriend.getName());
	else if (COMP==1)
		ans = (this->bday > otherFriend.getBday());
	else if (COMP==2)
		ans = (this->number > otherFriend.getNumber());
	return ans;
}