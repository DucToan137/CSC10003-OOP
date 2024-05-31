#pragma once
#include"IParsable.h"
#include"Rectangle.h"
#include<sstream>

class RectangleParser : public IParsable {
public:
	Object* parse(std::string data) override;
	std::string toString() override;
	std::string parsedObjectName() override;
};