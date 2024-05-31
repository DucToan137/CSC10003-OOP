#include"CircleParser.h"
#include"Utils.h"
#include<vector>
#include<string>

Object* CircleParser::parse(std::string data) {
	std::vector<std::string> token = Utils::String::split(data, "=");
	double radius = stod(token[1]);
	return new Circle(radius);
}

std::string CircleParser::toString() {
	return "Convert to Circle";
}

std::string CircleParser::parsedObjectName() {
	return "Circle";
}


