#ifndef CELLULAR_PHONE_STOCK_H
#define CELLULAR_PHONE_STOCK_H

#include "CellularPhone.h"

class CellularPhoneStock {
private:
	CellularPhone* stock[30];
	static int modelCount;
public:
	CellularPhoneStock();
	~CellularPhoneStock();

	bool addCellularPhone(string,int,string,int=1);
	bool removeCellularPhone(string,string,int=1);
	int getPhoneIndex(string, string);
	void sort();

	string allPhones();
	string allColorsOfModel(string);
	string allPhonesBelowPrice(int);
};

#endif