#ifndef CELLULAR_PHONE_STOCK_H
#define CELLULAR_PHONE_STOCK_H

#include "CellularPhone.h"

class CellularPhoneStock {
private:
	const static int STOCKSIZE = 30;
	CellularPhone* stock[STOCKSIZE];
	int modelCount;
public:
	CellularPhoneStock();
	CellularPhoneStock(CellularPhoneStock*);
	~CellularPhoneStock();

	const bool addCellularPhone(string,int,string,int=1);
	const bool removeCellularPhone(string,string,int=1);
	const int getPhoneIndex(string, string);
	void sort();

	void operator=(CellularPhoneStock&);

	const string allPhones();
	const string allColorsOfModel(string);
	const string allPhonesBelowPrice(int);
};

#endif