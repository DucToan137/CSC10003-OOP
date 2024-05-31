#pragma once
#include"Fraction.h"
#include"NumberFormat.h"
#include<string>


class FractionToDecimalConverter {
private:
	NumberFormat _config;
public:
	FractionToDecimalConverter(NumberFormat config);
	std::string convert(const Fraction& f);
};