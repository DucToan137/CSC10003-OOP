#include"Rectangle.h"
#include<sstream>

int Rectangle::getWidth() {
	return _width;
}

int Rectangle::getHeight() {
	return _height;
}

void Rectangle::setWidth(int val) {
	_width = val;
}

void Rectangle::setHeight(int val) {
	_height = val;
}

Rectangle::Rectangle() {
	_width = 2;
	_height = 3;
}

Rectangle::Rectangle(int width, int height) {
	_width = width;
	_height = height;
}

std::string Rectangle::toString() {
	std::string result;

	std::stringstream out;
	out << "Rectangle Width=" << _width << ", Height=" << _height;

	result = out.str();

	return result;
}