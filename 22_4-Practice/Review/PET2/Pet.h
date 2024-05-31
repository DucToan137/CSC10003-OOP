#pragma once
#include"Object.h"
#include<iomanip>
#include<sstream>
#include<vector>


class Pet : public Object {
protected:
	string _name;
	int _age;
	double _price;
public:
	virtual void makeSound() = 0;
	virtual void displayInfo() = 0;
};