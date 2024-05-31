#pragma once
#include"NumberFormat.h"
#include"Fraction.h"
#include<string>


class FractionToPercentageConverter {
private:
	NumberFormat _config;
public:
	FractionToPercentageConverter(NumberFormat config);
	std::string convert(const Fraction& f);
};