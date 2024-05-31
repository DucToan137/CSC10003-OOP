#include"FoodBooth.h"

FoodBooth::FoodBooth(string id, int area, int extraFee) : _id(id), _area(area), _extraFee(extraFee) {}

int FoodBooth::calculateTotalRent() {
	return _area * _price + _extraFee;
}

int FoodBooth::calculateBaseRent() {
	return _area * _price;
}

string FoodBooth::getId() {
	return _id;
}	

int FoodBooth::getArea() {
	return _area;
}

int FoodBooth::getExtraFee() {
	return _extraFee;
}


void FoodBooth::printInfo(ostream& os) {
	os << setw(6) << _id << " | "
		<< setw(10) << "Thuc pham" << " | "
		<< setw(7) << _area << " m2 | "
		<< setw(9) << _price << " | "
		<< setw(15) << calculateBaseRent() << " | "
		<< setw(11) << _extraFee << " | "
		<< setw(14) << calculateTotalRent() << " d" << endl;
}