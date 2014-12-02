#include <sstream>

#include "CellularPhone.h"

CellularPhone::CellularPhone(string model, int price, string color, int amount){
	this->model = model;
	this->color = color;
	this->price = price;
	this->stock = amount;
}
CellularPhone::CellularPhone(CellularPhone& origin){
	this->model = origin.getModel();
	this->color = origin.getColor();
	this->price = origin.getPrice();
	this->stock = origin.getStock();
}

CellularPhone::~CellularPhone(){

}

bool CellularPhone::operator==(CellularPhone& other){
	// If modelname and color are equal
	if (this->getModel()==other.getModel() && this->getColor()==other.getColor()){
		return true;
	}
	return false;
}
void CellularPhone::operator=(CellularPhone& other){
	this->model = other.getModel();
	this->color = other.getColor();
	this->stock = other.getStock();
}

bool CellularPhone::operator<(CellularPhone& other){
	if (this->getStock() < other.getStock())
		return true;
	else
		return false;
}

string CellularPhone::getModel(){
	return this->model;
}
void CellularPhone::setModel(string model){
	this->model = model;
}

string CellularPhone::getColor(){
	return this->color;
}
void CellularPhone::setColor(string color){
	this->color = color;
}

int CellularPhone::getPrice(){
	return this->price;
}
void CellularPhone::setPrice(int price){
	this->price = price;
}

int CellularPhone::getStock(){
	return this->stock;
}
void CellularPhone::setStock(int stock){
	this->stock = stock;
}
void CellularPhone::addToStock(int amount){
	this->stock+=amount;
}
void CellularPhone::removeFromStock(int amount){
	this->stock-=amount;
}

string CellularPhone::getInfo(){
	stringstream ss;
	ss 	<< this->getModel() << endl
		<< "\tFärg: " << this->getColor() << endl
		<< "\tPris: " << this->getPrice() << "kr" << endl
		<< "\tAntal på lager: " << this->getStock();
	return ss.str();
}