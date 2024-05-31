#pragma once
#include"Parsable.h"
#include"Bird.h"

class BirdParser : public Parsable {
public:
	Pet* parse(string line) override {
		istringstream iss(line);
		string type, name;
		int age;
		double price;
		double special;
		iss >> type >> name >> age >> price >> special;
		return new Bird(name, age, price, special);
	}
};