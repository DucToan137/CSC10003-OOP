#include"Dog.h"

Dog::Dog(string name, int age, double price, string breed) {
	_name = name;
	_age = age;
	_price = price;
	_breed = breed;
}

void Dog::makeSound() {
	cout << "Woof!" << endl;
}

string Dog::toString() {
	return "Dog";
}

void Dog::displayInfo() {
	cout << left << setw(10) << toString() << " | "
		<< fixed << setprecision(1)
		<< setw(16) << _name << " | "
		<< setw(6) << _age << " | "
		<< setw(12) << _price << " | "
		<< setw(16) << _breed << "\n";
}

