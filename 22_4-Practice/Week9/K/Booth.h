#pragma once
#include<iostream>
#include<iomanip>

using namespace std;

class Booth {
public:
	virtual void printInfo(ostream& os) = 0;
	virtual int calculateTotalRent() = 0;

};

