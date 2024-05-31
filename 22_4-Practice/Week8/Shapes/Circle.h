#pragma once
#include"IShape.h"

class Circle : public IShape {
public:
	inline static const double PI = 2 * asin(1);
private:
	double _radius;
public:
	Circle();
	Circle(double radius);
	double area() override;
	double perimeter() override;
	std::string toString() override;
};