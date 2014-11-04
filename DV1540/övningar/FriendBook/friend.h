#ifndef FRIEND_H
#define FRIEND_H

#include <string>

using namespace std;

class Friend {
private:
	string name;
	int id;
	int bday;
	string number;
	string pNr;

	static int COMP;
public:
	Friend();
	Friend(int);
	Friend(int,string);
	Friend(int,string,string,string);
	~Friend();
	void setID(int);
	string infoStr();
	string infoCsv();
	void setName(string);
	string getName();
	void setBday(int,int,int);
	int getBday();
	void setNumber(string);
	string getNumber();

	bool operator==(Friend&);
	bool operator<(Friend&);
	bool operator>(Friend&);
};


#endif
