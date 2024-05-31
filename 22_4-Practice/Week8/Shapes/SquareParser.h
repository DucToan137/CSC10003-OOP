#pragma once
#include"IParsable.h"
#include"Square.h"
#include<sstream>

class SquareParser : public IParsable {
public:
	Object* parse(std::string data) override;
	std::string toString() override;
	std::string parsedObjectName() override;
};