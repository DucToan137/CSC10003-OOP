#include"Pet.h"
#include"Cat.h"
#include"Dog.h"
#include"Bird.h"
#include<vector>

class Store{
private:
	vector<Pet*> _store;
public:
	Store() {};

	void addPet(Pet* pet) {
		_store.push_back(pet);
	}

	void display(){
		cout << left << setw(10) << "Type" << " | "
			<< setw(16) << "Name" << " | "
			<< setw(6) << "Age" << " | "
			<< setw(12) << "Price" << " | "
			<< setw(16) << "Special" << "\n";
		cout << string(70, '-') << "\n";

		for (auto pet : _store) {
			pet->displayInfo();
		}
	}
};