#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<map>
#include<iomanip>

using namespace std;

class Object {
	virtual string toString() = 0;
};

class Pet : public Object{
protected:
	string _name;
	int _age;
	double _price;
public:
	virtual void makeSound() = 0;
	virtual void displayInfo() = 0;

};

class Dog : public Pet {
private:
	string _breed;
public:
	Dog() {};
	Dog(string name, int age, double price, string breed)
	{
		_name = name;
		_age = age;
		_price = price;
		_breed = breed;
	}
	void makeSound() override
	{
		cout << "Woof!" << endl;
	}

	
	string toString() override {
		return "Dog";
	}

	void displayInfo() override {
		cout << left << setw(10) << toString() << " | "
			<< fixed << setprecision(1)
			<< setw(16) << _name << " | "
			<< setw(6) << _age << " | "
			<< setw(12) << _price << " | "
			<< setw(16) << _breed << "\n";

	}
};

class Cat : public Pet {
private:
	string _color;
public:
	Cat() {};
	Cat(string name, int age, double price, string color) {
		_name = name;
		_age = age;
		_price = price;
		_color = color;
	}
	void makeSound() override
	{
		cout << "Meow!" << endl;
	}

	string toString() override {
		return "Cat";
	}

	void displayInfo() override {
		cout << left << setw(10) << toString() << " | "
			<< fixed << setprecision(1)
			<< setw(16) << _name << " | "
			<< setw(6) << _age << " | "
			<< setw(12) << _price << " | "
			<< setw(16) << _color << "\n";
	}

};

class Bird : public Pet {
private:
	double _wingSpan;
public:
	Bird() {};
	Bird(string name, int age, double price, double wingSpan) {
		_name = name;
		_age = age;
		_price = price;
		_wingSpan = wingSpan;
	}
	void makeSound() override
	{
		cout << "Chirp!" << endl;
	}

	string toString() override {
		return "Bird";
	}

	void displayInfo() override {
		cout << left << setw(10) << toString() << " | "
			<< fixed << setprecision(1)
			<< setw(16) << _name << " | "
			<< setw(6) << _age << " | "
			<< setw(12) << _price << " | "
			<< setw(16) << _wingSpan << "\n";
	}
};

class Parsable {
public:
	virtual Pet* parse(const string& line) = 0;
};


class DogParser : public Parsable {
public:
	Pet* parse(const string& line) override {
		istringstream iss(line);
		string type, name, special;
		int age;
		double price;
		iss >> type >> name >> age >> price >> special;
		return new Dog(name, age, price, special);
	}
};

class CatParser : public Parsable {
public:
	Pet* parse(const string& line) override {
		istringstream iss(line);
		string type, name, special;
		int age;
		double price;
		iss >> type >> name >> age >> price >> special;
		return new Cat(name, age, price, special);
	}
};

class BirdParser : public Parsable {
public:
	Pet* parse(const string& line) override {
		istringstream iss(line);
		string type, name;
		int age;
		double price;
		double special;
		iss >> type >> name >> age >> price >> special;
		return new Bird(name, age, price, special);
	}
};

class Parser {
public:
    static Parsable* create(const string& type);
    static Pet* parse(const string& line);
};

Parsable* Parser::create(const string& type) {
    if (type == "Dog") {
        return new DogParser();
    }
    else if (type == "Cat") {
        return new CatParser();
    }
    else if (type == "Bird") {
        return new BirdParser();
    }
    else {
        return nullptr;
    }
}

Pet* Parser::parse(const string& line) {
	istringstream iss(line);
	string type;
	iss >> type;
	Parsable* parser = create(type);
	if (parser) {
		return parser->parse(line);
	}
	else {
		return nullptr;
	}
}


class PetStore {
private:
	std::vector<Pet*> _pets;
public:
	PetStore() {};

	void addPet(Pet* pet) {
		_pets.push_back(pet);
	}

	void display() {
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
};

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

