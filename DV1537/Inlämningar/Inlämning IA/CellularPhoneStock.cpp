#include "CellularPhoneStock.h"

#include <sstream>

int CellularPhoneStock::modelCount = 0;

CellularPhoneStock::CellularPhoneStock(){

}

CellularPhoneStock::~CellularPhoneStock(){
	for (int i=0; i<modelCount; i++){
		delete stock[i];
	}
}

bool CellularPhoneStock::addCellularPhone(string model, int price, string color, int amount){
	bool returnval;
	int modelIndex = getPhoneIndex(model, color);
	if (modelIndex!=-1){ // If model is found in stock
		stock[modelIndex]->addToStock(amount);
		returnval = true;
	}
	else { // Model doesn't exist yet, adding it to stock
		this->stock[modelCount] = new CellularPhone(model, price, color, amount);;
		this->modelCount++;
		returnval = false;
	}
	this->sort();
	// Returns true if model already existed and returns false if it is a new model
	return returnval;
}

bool CellularPhoneStock::removeCellularPhone(string model, string color, int amount){
	int result;
	int modelIndex = getPhoneIndex(model, color);
	if (modelIndex != -1){
		stock[modelIndex]->removeFromStock(amount);
		if (stock[modelIndex]->getStock()<1){
			delete stock[modelIndex];
			modelCount--;
			for (int i=modelIndex; i<modelCount; i++){
				stock[i] = stock[i+1];
			}
		}
		result = true;
	}
	else {
		result = false;
	}
	this->sort();
	// Returns true if device is found and removed, otherwise false
	return result;
}

int CellularPhoneStock::getPhoneIndex(string model, string color){
	CellularPhone* sameModel = NULL;
	CellularPhone* phone = new CellularPhone(model, 0, color, 0);
	int modelIndex = -1;
	for (int i=0; i<modelCount; i++){
		if ((*phone)==(*stock[i])){
			sameModel = stock[i];
			modelIndex = i;
		}
	}
	return modelIndex;
}

void CellularPhoneStock::sort(){
	for (int max=this->modelCount; max>=0; max--){
		for (int i=0; i<max-1; i++){
			if ((*stock[i+1]) < (*stock[i])){
				CellularPhone* temp = stock[i+1];
				stock[i+1] = stock[i];
				stock[i] = temp;
			}
		}
	}
}

string CellularPhoneStock::allPhones(){
	stringstream ss;
	for (int i=0; i<modelCount; i++){
		ss << stock[i]->getInfo() << endl;
	}
	return ss.str();
}

string CellularPhoneStock::allColorsOfModel(string model){
	stringstream ss;
	for (int i=0; i<modelCount; i++){
		if (stock[i]->getModel() == model){
			ss << stock[i]->getInfo() << endl;
		}
	}
	return ss.str();
}

string CellularPhoneStock::allPhonesBelowPrice(int price){
	stringstream ss;
	for (int i=0; i<modelCount; i++){
		if (stock[i]->getPrice() < price){
			ss << stock[i]->getInfo() << endl;
		}
	}
	return ss.str();
}