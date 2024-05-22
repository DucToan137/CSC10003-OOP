#pragma once
#include"IShape.h"
#include"RandomDoubleGenerator.h"

class Triangle : public IShape {
private:
	double _a;
	double _b;
	double _c;
public:
	double a() { return _a; }
	double b() { return _b; }
	double c() { return _c; }
public:
	Triangle();
	Triangle(double a, double b, double c);
	string toString();
	IShape* generate(int, int);
	string className() { return "Triangle"; }
};