#include"Cat.h"

Cat::Cat(string name, int age, double price, string color) {
	_name = name;
	_age = age;
	_price = price;
	_color = color;
}

void Cat::makeSound() {
	cout << "Meow!" << endl;
}

string Cat::toString() {
	return "Cat";
}

void Cat::displayInfo() {
	cout << left << setw(10) << toString() << " | "
		<< fixed << setprecision(1)
		<< setw(16) << _name << " | "
		<< setw(6) << _age << " | "
		<< setw(12) << _price << " | "
		<< setw(16) << _color << "\n";
}