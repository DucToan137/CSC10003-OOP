#pragma once
#include"IShape.h"
#include"RandomDoubleGenerator.h"

class Rectangle : public IShape {
private:
	double _a;
	double _b;
public:
	double a() { return _a; }
	double b() { return _b; }
public:
	Rectangle();
	Rectangle(double a, double b);
	string toString();
	IShape* generate(int, int);
	string className() { return "Rectangle"; }
	
};