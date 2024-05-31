#include"NumberFormat.h"
#include<string>

NumberFormat::NumberFormat() {
	_thousandSeparator = ",";
	_decimalSeparator = ".";
	_precision = 1;
}

NumberFormat::NumberFormat(std::string thounsand, std::string dec, int prec) {
	_thousandSeparator = thounsand;
	_decimalSeparator = dec;
	_precision = prec;
}

std::string NumberFormat::getThounsandSeparator() {
	return _thousandSeparator;
}
std::string NumberFormat:: getDecimalSeparator() {
	return _decimalSeparator;
}
int NumberFormat::getPrecision() {
	return _precision;
}