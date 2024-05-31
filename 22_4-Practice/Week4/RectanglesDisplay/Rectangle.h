#pragma once
#include<string>

class Rectangle {
private:
	int _width;
	int _height;
public:
	int getWidth();
	int getHeight();
	void setWidth(int val);
	void setHeight(int val);
public:
	Rectangle();
	Rectangle(int width, int height);
	std::string toString();
};