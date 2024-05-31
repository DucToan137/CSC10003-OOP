#pragma once
#include <algorithm>
#include <iomanip>
#include<vector>
#include<string>
#include <sstream>
#include<fstream>
#include<iostream>


using namespace std;

class Booth {
public:
	virtual void printInfo(ostream& os) = 0;
	virtual int calculateTotalRent() = 0;

};