#pragma once
#include"Pet.h"


class Parsable {
public:
	virtual Pet* parse(string line) = 0;
};
