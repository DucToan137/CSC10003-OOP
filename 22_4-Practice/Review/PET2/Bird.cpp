#include"Bird.h"

Bird::Bird() {};

Bird::Bird(string name, int age, double price, double wingSpan) {
	_name = name;
	_age = age;
	_price = price;
	_wingSpan = wingSpan;
}

void Bird::makeSound() {
	cout << "Chirp!" << endl;
}

string Bird::toString() {
	return "Bird";
}

void Bird::displayInfo() {
	cout << left << setw(10) << toString() << " | "
		<< fixed << setprecision(1)
		<< setw(16) << _name << " | "
		<< setw(6) << _age << " | "
		<< setw(12) << _price << " | "
		<< setw(16) << _wingSpan << "\n";
}