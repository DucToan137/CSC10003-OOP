#pragma once

#pragma once

#include<iostream>
#include<string>

class Fraction {
private:
	int _num;
	int _denom;
public:
	int getNum();
	int getDenom();
	void setNum(int val);
	void setDenom(int val);
public:
	Fraction();
	Fraction(int num, int den);
	std::string toString();
public:
	std::string Lowest_Mixed();

};