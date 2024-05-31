#pragma once
#include"IValueConverter.h"
#include<string>
#include<sstream>
#include<vector>
#include<regex>

class IntegerToCurrencyConverter : public IValueConverter {
public:
	std::string convert(Object* Obj) override;
	std::string toString() override;
};