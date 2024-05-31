#pragma once
#include"Parsable.h"
#include"Dog.h"

class DogParser : public Parsable {
public:
	Pet* parse(string line) override {
		istringstream iss(line);
		string type, name, special;
		int age;
		double price;
		iss >> type >> name >> age >> price >> special;
		return new Dog(name, age, price, special);
	}
};