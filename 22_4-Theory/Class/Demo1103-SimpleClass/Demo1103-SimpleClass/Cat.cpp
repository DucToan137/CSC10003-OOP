#include "Cat.h"
#include <iostream>

Cat::Cat() {
	_weight = 0.1;  // kg
	_height = 0.05; // m
}

Cat::Cat(float weight, float height) {
	this->_weight = weight;
	this->_height = height;
}

Cat::~Cat() {
	//std::cout << "A cat is killed. 8 lives left\n";
}

float Cat::weight() {
	return _weight;
}

void Cat::setWeight(float value) {
	_weight = value;
}

float Cat::height() {
	return _height;
}

void Cat::setHeight(float value) {
	_height = value;
}


// :: / resolution operator / phân giải phạm vi
void Cat::eat() {
	std::cout << "Eating\n";
}

void Cat::sleep() {
	std::cout << "Sleeping\n";
}

void Cat::run() {
	std::cout << "Running\n";
}

void Cat::input() {
	std::cout << "Nhap can nang:";
	std::cin >> _weight;

	std::cout << "Nhap chieu cao:";
	std::cin >> _height;
}

void Cat::output() {
	std::cout << _weight << " kg, " << _height << "m\n";
}