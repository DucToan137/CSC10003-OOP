#include"Circle.h"

Circle::Circle() {
	_r = 0;
}

Circle::Circle(double r) {
	_r = r;
}

string Circle::toString() {
	stringstream builder;

	builder << "Circle: r=" << _r;

	string result =builder.str();
	return result;
}

IShape* Circle::generate(int left, int right) {
	double r = RandomDoubleGenerator::instance()->next(left, right);

	IShape* result = new Circle(r);

	return result;
}