#pragma once
#include"Booth.h"

class FoodBooth : public Booth {
private:
	string _id;
	int _area;
	int _extraFee;
	inline static int _price = 560000;
public:
	FoodBooth(string id, int area, int extraFee);
	int calculateBaseRent();
	int calculateTotalRent();
	string getId();
	int getArea();
	int getExtraFee();

	void printInfo(ostream& os) override;
};
