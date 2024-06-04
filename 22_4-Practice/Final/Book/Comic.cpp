#include"Comic.h"

Comic::Comic(string name, string author, int year, double price, string special) {
	_name = name;
	_author = author;
	_year = year;
	_price = price;
	_special = special;
}

string Comic::getType() {
	return "Comic";
}

string Comic::getSeries() {
	return _special;
}