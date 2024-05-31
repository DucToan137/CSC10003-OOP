#include"SquareParser.h"
#include"Utils.h"
#include<vector>
#include<string>

Object* SquareParser::parse(std::string data) {
	vector<string> token = Utils::String::split(data, "=");
	double a = stod(token[1]);
	return new Square(a);
}

std::string SquareParser::toString() {
	return "Convert to Square";
}

std::string SquareParser::parsedObjectName() {
	return "Square";
}