#include "IntegerToCurrencyConverter.h"
#include "NumberFormatInfo.h"
#include"Integer.h"
#include "Object.h"
#include <regex> // Add this line to include the regex library

std::string IntegerToCurrencyConverter::convert(Object* object) {
	auto number = dynamic_cast<Integer*>(object);
	int value = number->value();

	std::stringstream builder;
	NumberFormatInfo info;
	int count = 0;

	while (value != 0) {
		int lastDigit = value % 10;
		builder << lastDigit;

		count++;
		value /= 10;
		if (count == 3 && value != 0) {
			builder << info.currencyDecimalSeparator();
			count = 0;
		}
	}

	std::string numberSeparated = builder.str(); // "000.000.1"
	std::reverse(numberSeparated.begin(), numberSeparated.end()); // Use std::reverse instead of reverse

	std::string format = info.currencyPositiveFormat(); //"n $" ==> "1.000.000 d"
	std::string symbol = info.currencySymbol(); // "d"
	std::string result = std::regex_replace(format, std::regex("n"), numberSeparated); // Use std::regex_replace instead of regex_replace
	result = std::regex_replace(result, std::regex("\\$"), symbol); // Use std::regex_replace instead of regex_replace

	return result;
}

std::string IntegerToCurrencyConverter::toString() {
	return "IntegerToCurrencyConverter";
}
