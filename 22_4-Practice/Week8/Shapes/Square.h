#pragma once
#include"IShape.h"

class Square : public IShape {
private:
	double _a;
public:
	Square();
	Square(double a);
	double area() override;
	double perimeter() override;
	std::string toString() override;
};