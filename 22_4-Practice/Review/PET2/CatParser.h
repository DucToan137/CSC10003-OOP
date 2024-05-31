#pragma once
#include"Parsable.h"
#include"Cat.h"

class CatParser : public Parsable {
public:
	Pet* parse(string line) override {
		istringstream iss(line);
		string type, name, special;
		int age;
		double price;
		iss >> type >> name >> age >> price >> special;
		return new Cat(name, age, price, special);
	}
};