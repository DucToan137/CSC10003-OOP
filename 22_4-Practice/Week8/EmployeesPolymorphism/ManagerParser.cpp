#include"ManagerParser.h"
#include"Manager.h"
#include"Utils.h"

Object* ManagerParser::parse(std::string data) {
	std::vector<std::string> token = Utils::String::split(data, ", ");
	int employeeCount = stoi((Utils::String::split(token[0], "="))[1]);
	int paymentPerEmployee = stoi((Utils::String::split(token[1], "="))[1]);
	int baseSalary = stoi((Utils::String::split(token[2], "="))[1]);
	return new Manager(employeeCount, paymentPerEmployee, baseSalary);
}

std::string ManagerParser::toString() {
	return "convert to Manager";
}

std::string ManagerParser::parsedObjectName() {
	return "Manager";
}