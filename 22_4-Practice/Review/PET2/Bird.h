#pragma once
#include"Pet.h"

class Bird : public Pet {
private:
	double _wingSpan;
public:
	Bird();
	Bird(string name, int age, double price, double wingSpan);
	void makeSound() override;
	string toString() override;
	void displayInfo() override;
};