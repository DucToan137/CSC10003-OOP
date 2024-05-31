#include"Pet.h"
#include"Cat.h"
#include"Dog.h"
#include"Bird.h"
#include<memory>
#include<sstream>

class Parser {
public:

	static Pet* parse(const string& line) {
		std::stringstream ss(line);
		std::string type;
		ss >> type;

		string name;
		int age;
		double price;
		string special;


		if (type == "Cat") {
			ss >> name >> age >> price >> special;
			return new Cat(name, age, price, special);
		}
		else if (type == "Dog") {
			ss >> name >> age >> price >> special;
			return new Dog(name, age, price, special);
		}
		else if (type == "Bird") {
			ss >> name >> age >> price >> special;
			return new Bird(name, age, price, stod(special));
		}
		else {
			return nullptr;
		}
	}
};