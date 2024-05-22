#include"Circle.h"

Circle::Circle() {
	_r = 0;
}

Circle::Circle(double r) {
	_r = r;
}

double Circle::perimeter() {
	double result = 2 * PI * _r;

	return result;
}

double Circle::area() {
	double result = PI * _r * _r;

	return result;
}

void* Circle::IRandomGenerate() {
	IShape* result = new Circle(
		IntegerGenerator::instance()->next(1, 100)
	);

	return result;
}

string Circle::toString() {
	stringstream ss;
	ss << "Circle: r= " << _r;
	string result = ss.str();

	return result;
}