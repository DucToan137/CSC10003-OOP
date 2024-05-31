#include"PetStore.h"

PetStore::PetStore() {}

void PetStore::addPet(Pet* pet) {
	_pets.push_back(pet);
}

void PetStore::display() {
	cout << left << setw(10) << "Type" << " | "
		<< setw(16) << "Name" << " | "
		<< setw(6) << "Age" << " | "
		<< setw(12) << "Price" << " | "
		<< setw(16) << "Special" << "\n";
	cout << string(70, '-') << "\n";

	for (auto pet : _pets) {
		pet->displayInfo();
	}
}