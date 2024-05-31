#include"JewelryBooth.h"

JewelryBooth::JewelryBooth(string id, int area, int extraFee) : _id(id), _area(area), _extraFee(extraFee) {}

int JewelryBooth::calculateTotalRent() {
	return _area * 560000 + _extraFee;
}

int JewelryBooth::calculateBaseRent() {
	return _area * 560000;
}

string JewelryBooth::getId() {
	return _id;
}

int JewelryBooth::getArea() {
	return _area;
}

int JewelryBooth::getExtraFee() {
	return _extraFee;
}

void JewelryBooth::printInfo(ostream& os) {
	os << setw(6) << _id << " | "
		<< setw(10) << "Da qui" << " | "
		<< setw(7) << _area << " m2 | "
		<< setw(9) << _price << " | "
		<< setw(15) << calculateBaseRent() << " | "
		<< setw(11) << _extraFee << " | "
		<< setw(14) << calculateTotalRent() << " d" << endl;
}