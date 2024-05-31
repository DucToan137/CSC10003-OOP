#pragma once
#include<string>

class NumberFormat {
private:
	std::string _thousandSeparator; // "." / "," / " "
	std::string _decimalSeparator;  // "," / "."
	int _precision; // 2 / 3
public:
	std::string getThounsandSeparator();
	std::string getDecimalSeparator();
	int getPrecision();



	NumberFormat();
	NumberFormat(std::string thousand, std::string dec, int precision);
};