#ifndef ISHAPE_H
#define ISHAPE_H

#include<string>

using namespace std;


class IShape {
public:
	virtual double perimeter() = 0;
	virtual double area() = 0;
	virtual string toString() = 0;
};

#endif // ISHAPE_H