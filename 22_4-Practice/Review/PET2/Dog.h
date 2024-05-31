#pragma once
#include"Pet.h"

class Dog : public Pet {
private:
	string _breed;
public:
	Dog();
	Dog(string name, int age, double price, string breed);
	void makeSound() override;
	string toString() override;
	void displayInfo() override;
};