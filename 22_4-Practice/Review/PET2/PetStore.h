#pragma once
#include"Pet.h"

class PetStore {
private:
	std::vector<Pet*> _pets;
public:
	PetStore();

	void addPet(Pet* pet);

	void display();
};