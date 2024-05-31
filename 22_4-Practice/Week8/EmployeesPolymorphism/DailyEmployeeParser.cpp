#include"DailyEmployeeParser.h"
#include"DailyEmployee.h"
#include"Utils.h"

Object* DailyEmployeeParser::parse(std::string data) {
	std::vector<std::string> token = Utils::String::split(data, ", ");
	int dayCount = std::stoi((Utils::String::split(token[0], "="))[1]);
	int paymentPerPay = stoi((Utils::String::split(token[1], "="))[1]);
	return new DailyEmployee(dayCount, paymentPerPay);
}
std::string DailyEmployeeParser::toString() {
	return "convert to EmployeeDaily";
}

std::string DailyEmployeeParser::parsedObjectName() {
	return "DailyEmployee";
}