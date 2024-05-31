#pragma once

#pragma once

#include<iostream>
#include<string>

class Fraction {
private:
	int _num;
	int _denom;
public:
	int getNumerator();
	int getDenominator();
	void setNumerator(int val);
	void setDenominator(int val);
public:
	Fraction();
	Fraction(int num, int den);
	std::string toString();
public:
	std::string Lowest_Mixed();
	void simplify();
	Fraction add(Fraction other);
	Fraction subtract(Fraction other);
	Fraction multiply(Fraction other);
	Fraction divide(Fraction other);

};