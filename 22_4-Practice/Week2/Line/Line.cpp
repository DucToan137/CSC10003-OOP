#include<iostream>
#include"Line.h"
using namespace std;

float Line::X1() {
	return _x1;
}

float Line::Y1() {
	return _y1;
}

float Line::X2() {
	return _x2;
}

float Line::Y2() {
	return _y2;
}

void Line::setX1(float value) {
	_x1 = value;
}

void Line::setY1(float value) {
	_y1 = value;
}

void Line::setX2(float value) {
	_x2 = value;
}

void Line::setY2(float value) {
	_y2 = value;
}

Line::Line() {
	_x1 = 0;
	_y1 = 0;
	_x2 = 1;
	_y2 = 1;
}

void Line::input() {
	cout << "Nhap x1:";
	cin >> _x1;

	cout << "Nhap y1:";
	cin >> _y1;

	cout << "Nhap x2:";
	cin >> _x2;

	cout << "Nhap y2:";
	cin >> _y2;
}

void Line::output() {
	cout << "((" << _x1 << "," << _y1 << "),(" << _x2 << "," << _y2 << "))";
}