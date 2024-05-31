#pragma once
#include"Object.h"
#include<vector>
#include<string>

class IParsable : public Object {
public:
	virtual Object* parse(std::string) = 0;
	std::string toString() override {
		return "IParsable";
	};
	virtual std::string parsedObjectName() = 0;
};