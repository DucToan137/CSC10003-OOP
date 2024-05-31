#pragma once
#include"Object.h"
#include"IShape.h"

class IParsable : public Object {
public:
	virtual Object* parse(std::string shape) = 0;
	virtual std::string parsedObjectName() = 0;

	std::string toString() override {
		return "IParsable";
	};
};