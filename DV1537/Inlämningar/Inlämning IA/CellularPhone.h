#ifndef CELLULAR_PHONE_H
#define CELLULAR_PHONE_H

#include <string>

using namespace std;

class CellularPhone {
private:
	string model;
	string color;
	int price;
	int stock;
public:
	CellularPhone(string,int,string,int=1);
	CellularPhone(CellularPhone&);
	~CellularPhone();

	const bool operator==(CellularPhone&);
	void operator=(CellularPhone&);
	const bool operator<(CellularPhone&);

	const string getModel();
	void setModel(string);

	const string getColor();
	void setColor(string);

	const int getPrice();
	void setPrice(int);

	const int getStock();
	void setStock(int);
	void addToStock(int=1);
	void removeFromStock(int=1);

	const string getInfo();
};

#endif