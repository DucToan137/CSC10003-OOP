#include<iostream>
#include"Dog.h"
#include"Cat.h"
#include"Bird.h"
#include"Pet.h"
#include"Store.h"
#include"Parser.h"

using namespace std;

int main() {


	int testID;
	cin >> testID;
	cout << "Test ID: " << testID << endl;

	/*cout << left << setw(10) << "Type" << " | "
		<< setw(16) << "Name" << " | "
		<< setw(6) << "Age" << " | "
		<< setw(12) << "Price" << " | "
		<< setw(16) << "Special" << "\n";
	cout << string(70, '-') << "\n";*/

	//Pet* pet = new Dog("Buddy", 3, 150.0, "Golden_Retriever");
	////pet->makeSound();
	//pet->displayInfo();

	//
	//pet = new Cat("Whiskers", 2, 100.0, "Black");
	////pet->makeSound();
	//pet->displayInfo();
	//

	//pet = new Bird("Tweety", 1, 50.0, 25.0);
	////pet->makeSound();
	//pet->displayInfo();

	Store store;
	store.addPet(new Bird("Rio", 1, 150.0, 12.5));
	store.addPet(new Dog("Lucky", 3, 120.0, "VietNam"));
	store.addPet(new Cat("Milu", 1, 100.0, "Gray"));

	vector<string> inputs = {
		"Dog Buddy 3 150.0 Golden_Retriever",
		"Cat Whiskers 2 100.0 Black",
		"Bird Tweety 1 50.0 25.0",
	};


	
	for(const auto& input : inputs){
		Pet *pet = Parser::parse(input);
		store.addPet(pet);
	}

	store.display();

	
	

	return 0;
}