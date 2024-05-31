#include"Circle.h"
#include<sstream>

Circle::Circle() {
	_radius = 0.0f;
}

Circle::Circle(double radius) {
	_radius = radius;
}

double Circle::area() {
	return round(PI * _radius * _radius);
}

double Circle::perimeter() {
	return round(PI * _radius * 2);
}

std::string Circle::toString() {
	std::stringstream builder;
	builder << "Circle";
	return builder.str();
}