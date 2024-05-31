#include"Square.h"
#include<sstream>


Square::Square() {
	_a = 0.0f;
}

Square::Square(double a) {
	_a = a;
}


double Square::area() {
	return round(_a * _a);
}


double Square::perimeter() {
	return round(_a * 4);
}

std::string Square::toString() {
	std::stringstream builder;
	builder << "Square";
	return builder.str();
}