#include "Data.h"
Data::Data() {//default constructor
	this->stock = 0.0;
	this->option = 0.0;
}
Data::Data(double st, double op) {//argument constructor
	this->set(st, op);
}
void Data::set(double st, double op) {//set data
	this->stock = st;
	this->option = op;
}
double Data::getStock() {// returns  stock data
	return this->stock;
}
double Data::getOption() { //return option data
	return this->option;
}
Data::~Data() {
}

