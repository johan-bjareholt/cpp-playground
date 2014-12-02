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

	bool operator==(CellularPhone&);
	void operator=(CellularPhone&);
	bool operator<(CellularPhone&);

	string getModel();
	void setModel(string);

	string getColor();
	void setColor(string);

	int getPrice();
	void setPrice(int);

	int getStock();
	void setStock(int);
	void addToStock(int=1);
	void removeFromStock(int=1);

	string getInfo();
};

#endif