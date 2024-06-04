#include"Parser.h"

Book* Parser::parseBook(string input) {
	stringstream ss(input);
	string type;
	string name;
	string author;
	string special;
	int year;
	double price;
	
	getline(ss, type, ',');
	getline(ss, name, ',');
	getline(ss, author, ',');

	ss >> year;
	ss.ignore();
	ss >> price;
	ss.ignore();

	getline(ss, special, ',');

	if (type == "Fiction") {
		return new Fiction(name, author, year, price, special);
	}
	else if (type == "NonFiction") {
		return new NonFiction(name, author, year, price, special);
	}
	else if (type == "Comic") {
		return new Comic(name, author, year, price, special);
	}
	else {
		return nullptr;
	}
}