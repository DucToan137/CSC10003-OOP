#pragma once
#include"IParsable.h"
#include"Circle.h"


class CircleParser : public IParsable {
public:
	Object* parse(std::string data) override;
	std::string toString() override;
	std::string parsedObjectName() override;
};