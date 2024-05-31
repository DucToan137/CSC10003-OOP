#pragma once
#include"Pet.h"

class Cat : public Pet {
private:
	string _color;
public:
	Cat() = default;
	Cat(string name, int age, double price, string color);
	void makeSound() override;
	string toString() override;
	void displayInfo() override;

};