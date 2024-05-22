#pragma once
#include<string>
#include<sstream>
#include"IShape.h"
#include"IRandomGenerate.h"
#include"IntegerGenerator.h"
#include <math.h>

using namespace std;

class Circle : public IShape, public IRandomGenerator {
private:
	double _r;
public:
	inline static const double PI = 2 * asin(1);
public:
	Circle();
	Circle(double r);
	double perimeter();
	double area();
	void * IRandomGenerate();
	string toString();

};