#include"RectangleParser.h"
#include"Utils.h"
#include<string>
#include<vector>


Object* RectangleParser::parse(std::string data) {
	std::vector<string> token = Utils::String::split(data, ", ");
	double width = stod((Utils::String::split(token[0], "="))[1]);
	double height = stod((Utils::String::split(token[1], "="))[1]);
	return new Rectangle(width, height);
}

std::string RectangleParser::toString() {
	return "Convert to Rectangle";
}

std::string RectangleParser::parsedObjectName() {
	return "Rectangle";
}