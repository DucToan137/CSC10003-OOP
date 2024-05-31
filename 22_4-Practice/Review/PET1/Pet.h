#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"Object.h"

using namespace std;

class Pet : public Object {
protected:
	string _name;
	int _age;
	double _price;
public:
	virtual void makeSound() = 0;
	virtual void displayInfo() = 0;
};