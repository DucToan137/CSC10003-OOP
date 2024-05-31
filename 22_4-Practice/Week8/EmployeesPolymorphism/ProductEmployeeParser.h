#pragma once
#include"IParsable.h"

class ProductEmployeeParser : public IParsable {
public:
	Object* parse(std::string data) override;
	std::string toString() override;
	std::string parsedObjectName() override;
};

