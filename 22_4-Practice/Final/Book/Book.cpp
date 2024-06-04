#include"Book.h"

Book::Book() {
	_name = "";
	_author = "";
	_year = 0;
	_price = 0;
	_special = "";
}

string Book::getName() {
	return _name;
}

string Book::getAuthor() {
	return _author;
}

int Book::getYear() {
	return _year;
}

double Book::getPrice() {
	return _price;
}

Book::Book(string name, string author, int year, double price, string special) {
	_name = name;
	_author = author;
	_year = year;
	_price = price;
	_special = special;
}

string Book::getSpecial() {
	return _special;
}

void Book::display()
{
	stringstream builder;
	builder << std::left << setw(10) << this->getType() << " | "
		<< setw(24) << _name << " | "
		<< setw(18) << _author << " | "
		<< setw(6) << _year << " | ";
	builder << setw(10) << std::fixed << std::setprecision(2) << _price << " | " << this->getSpecial() << "\n";
	cout << builder.str();
}