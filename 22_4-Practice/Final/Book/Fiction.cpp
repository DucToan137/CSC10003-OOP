#include"Fiction.h"

Fiction::Fiction(string name, string author, int year, double price, string special) {
	_name = name;
	_author = author;
	_year = year;
	_price = price;
	_special = special;
}

string Fiction::getType() {
	return "Fiction";
}

string Fiction::getAward() {
	return _special;
}