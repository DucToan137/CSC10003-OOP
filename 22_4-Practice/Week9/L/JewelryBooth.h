#pragma once
#include"Booth.h"

class JewelryBooth : public Booth {
private:
	string _id;
	int _area;
	int _extraFee;
	inline static int _price = 560000;
public:
	JewelryBooth(string id, int area, int extraFee);
	int calculateTotalRent();
	int calculateBaseRent();
	string getId();
	int getArea();
	int getExtraFee();
	void printInfo(ostream& os);
};