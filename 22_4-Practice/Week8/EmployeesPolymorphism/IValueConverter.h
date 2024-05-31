#pragma once
#include"Object.h"
#include<string>

class IValueConverter : public Object {
public:
	virtual std::string convert(Object* Obj) = 0;
	virtual std::string toString() override {
		return "IValueConverter";
	};
};