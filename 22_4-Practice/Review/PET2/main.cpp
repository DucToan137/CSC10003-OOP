#include<iostream>
#include"Dog.h"
#include"Cat.h"
#include"Parser.h"
#include"PetStore.h"


using namespace std;


int main() {
	int testID;
	cin >> testID;
	cout << "Test ID: " << testID << endl;


	PetStore store;
	store.addPet(new Bird("Rio", 1, 150.0, 12.5));
	store.addPet(new Dog("Lucky", 3, 120.0, "VietNam"));
	store.addPet(new Cat("Milu", 1, 100.0, "Gray"));

	vector<string> inputs = {
		"Dog Buddy 3 150.0 Golden_Retriever",
		"Cat Whiskers 2 100.0 Black",
		"Bird Tweety 1 50.0 25.0",
	};



	for (const auto& input : inputs) {
		Pet* pet = Parser::parse(input);
		store.addPet(pet);

	}

	store.display();


	return 0;
}