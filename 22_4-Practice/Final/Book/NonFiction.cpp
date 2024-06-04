#include"NonFiction.h"


NonFiction::NonFiction(string name, string author, int year, double price, string special) {
	_name = name;
	_author = author;
	_year = year;
	_price = price;
	_special = special;
}

string NonFiction::getType() {
	return "NonFiction";
}

string NonFiction::getGenre() {
	return _special;
}
