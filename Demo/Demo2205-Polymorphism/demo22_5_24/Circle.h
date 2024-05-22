#pragma once
#include"IShape.h"
#include"RandomDoubleGenerator.h"
#include<math.h>

using namespace std;

class Circle : public IShape {
private:
	double _r;
	inline static double PI = 2 * asin(1);
public:
	double r() { return _r; }
public:
	Circle();
	Circle(double r);
	string toString();
	IShape* generate(int, int);
	string className() { return "Circle"; }
};