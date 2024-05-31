#include"ClothesBooth.h"

ClothesBooth::ClothesBooth(string id, int area) : _id(id), _area(area) {}

int ClothesBooth::calculateTotalRent() {
	return _area * 560000 + _extraFee;
}

int ClothesBooth::calculateBaseRent() {
	return _area * 560000;
}

string ClothesBooth::getId() {
	return _id;
}

int ClothesBooth::getArea() {
	return _area;
}

void ClothesBooth::printInfo(ostream& os) {
	os << setw(6) << _id << " | "
		<< setw(10) << "Quan ao" << " | "
		<< setw(7) << _area << " m2 | "
		<< setw(9) << _price << " | "
		<< setw(15) << calculateBaseRent() << " | "
		<< setw(11) << _extraFee << " | "
		<< setw(14) << calculateTotalRent() << " d" << endl;
}