#include <iostream>

#include "CellularPhoneStock.h"

using namespace std;

void addPhoneDialog(CellularPhoneStock& stock){
	string 	model,
			color;
	int price;

	cin.clear();cin.ignore();
	cout << "Modell:";
	getline(cin, model);
	cout << "Färg:";
	getline(cin, color);
	cout << "Pris: ";
	cin >> price;

	bool exists = stock.addCellularPhone(model, price, color);
	if (exists){
		cout << "Modellen och färgen fanns redan, lägger till fler med det gamla priset" << endl;
	}
}

void listAllColorsOfModelDialog(CellularPhoneStock& stock){
	string model;
	cin.ignore();cin.clear();
	cout << "Modell: ";
	getline(cin, model);
	cout << stock.allColorsOfModel(model);
}

void listPhonesBelowPriceDialog(CellularPhoneStock& stock){
	int price;
	cin.ignore();cin.clear();
	cout << "Pris: ";
	cin >> price;
	cout << stock.allPhonesBelowPrice(price);
}

void removePhoneDialog(CellularPhoneStock& stock){
	string 	model,
			color;

	cin.clear();cin.ignore();
	cout << "Modell:";
	getline(cin, model);
	cout << "Färg:";
	getline(cin, color);

	int success = stock.removeCellularPhone(model, color);
	if (success){
		cout << "Tog bort en telefon från lagret" << endl;
	}
	else {
		cout << "Kunde inte hitta någon telefon med det namnet och/eller färgen" << endl;
	}
}

int main(){
	bool running=true;

	CellularPhoneStock stock2 = CellularPhoneStock();
	// Standard models for debugging, uncomment if you want to use them
	
	stock2.addCellularPhone("Apple iPhone 6", 6000, "Guld",3);
	stock2.addCellularPhone("Apple iPhone 6", 6000, "Silver",4);
	stock2.addCellularPhone("LG G3", 5000, "Svart",2);
	stock2.addCellularPhone("Samsung Galaxy S5", 5800, "Blå",5);

	// Stock deepcopying test, uncomment to try it
	
	CellularPhoneStock stock = CellularPhoneStock();
	stock.addCellularPhone("Motorola Moto X", 6000, "Svart", 2);
	stock = stock2;
	std::cout << stock2.allPhones();

	char choice;
	cout << "Välkommen till Telefon Varuhuset!" << endl;
	do {
		cout << "1. Lägg till en telefon" << endl
			<< "2. Visa alla telefoner" << endl
			<< "3. Visa alla telefoner under ett pris" << endl
			<< "4. Visa alla färger av en telefonmodell" << endl
			<< "5. Ta bort en telefon" << endl
			<< "q. Avsluta" << endl
			<< "Alternativ: ";
		cin >> choice;
		switch (choice){
			case '1':
				addPhoneDialog(stock);
				break;
			case '2':
				cout << stock.allPhones();
				break;
			case '3':
				listPhonesBelowPriceDialog(stock);
				break;
			case '4':
				listAllColorsOfModelDialog(stock);
				break;
			case '5':
				removePhoneDialog(stock);
				break;
			case 'q':
				running=false;
				break;
			default:
				cout << "Ogiltigt alternativ" << endl;
		}
	} while (running);
}
