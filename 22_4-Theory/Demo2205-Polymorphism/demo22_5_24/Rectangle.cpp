#include"Rectangle.h"

Rectangle::Rectangle() {
	_a = 0;
	_b = 0;
}

Rectangle::Rectangle(double a, double b) {
	_a = a;
	_b = b;
}

string Rectangle::toString() {
	stringstream builder;

	builder << "Rectangle: a=" << _a << ", b=" << _b;


	string result = builder.str();
	return result;
}

IShape* Rectangle::generate(int left, int right) {
	double a = RandomDoubleGenerator::instance()->next(left, right);
	double b = RandomDoubleGenerator::instance()->next(left, right);

	IShape* result = new Rectangle(a, b);

	return result;
}