#pragma once
#include"Booth.h"
#include<string>



class ClothesBooth : public Booth {
private:
	string _id;
	int _area;
	inline static int _extraFee = 0;
	inline static int _price = 560000;
public:
	ClothesBooth(string id, int area);
	int calculateBaseRent();
	int calculateTotalRent();
	string getId();
	int getArea();
	void printInfo(ostream& os) override;
};