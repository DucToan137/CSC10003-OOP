#pragma once
#include"Object.h"

class Integer : public Object {
private:
	int _value;
public:
	Integer();
	Integer(int);
	int value();
	std::string toString();
};