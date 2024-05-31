#include"ProductEmployeeParser.h"
#include"ProductEmployee.h"
#include"Utils.h"

Object* ProductEmployeeParser::parse(std::string data) {
	std::vector<std::string> token = Utils::String::split(data, ", ");
	int productCount = stoi((Utils::String::split(token[0], "="))[1]);
	int paymentPerProduct = stoi((Utils::String::split(token[1], "="))[1]);
	return new ProductEmployee(productCount, paymentPerProduct);
}
std::string ProductEmployeeParser::toString() {
	return "convert to ProductEmployee";
}

std::string ProductEmployeeParser::parsedObjectName() {
	return "ProductEmployee";
}