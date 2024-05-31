#include<iostream>
#include"Point.h"
using namespace std;

float Point::X() {
	return _x;
}

float Point::Y() {
	return _y;
}

void Point::setX(float value) {
	_x = value;
}

void Point::setY(float value) {
	_y = value;
}

Point::Point() {
	_x = 0;
	_y = 0;
}

void Point::input() {
	cout << "Nhap x:";
	cin >> _x;
	cout << "Nhap y:";
	cin >> _y;
}

void Point::output() {
	cout << "(" << _x << "," << _y << ")\n";
}
