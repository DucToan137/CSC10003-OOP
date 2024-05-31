#include"Rectangle.h"
#include<sstream>

Rectangle::Rectangle() {
	_width = 0.0f;
	_height = 0.0f;
}

Rectangle::Rectangle(double width, double height) {
	_width = width;
	_height = height;
}


double Rectangle::area() {
	return round(_width * _height);
}

double Rectangle::perimeter() {
	return round(2 * (_width + _height));
}

std::string Rectangle::toString() {
	std::stringstream builder;
	builder << "Rectangle";
	return builder.str();
}