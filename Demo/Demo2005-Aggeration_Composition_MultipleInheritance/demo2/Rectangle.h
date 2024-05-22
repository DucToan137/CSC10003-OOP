#pragma once
#include<string>
#include<sstream>
#include"IShape.h"
#include"IntegerGenerator.h"
#include"IRandomGenerate.h"

using namespace std;

class Rectangle : public IShape,public IRandomGenerator {
private:
	double _a;
	double _b;
public:
	Rectangle();
	Rectangle(double a, double b);
	double perimeter();
	double area();
	void * IRandomGenerate();
	string toString();
};