#pragma once

#include"Rectangle.h"


class SolidRectangleConverter {
private:
	std::string _solid;
public:
	SolidRectangleConverter(std::string val);
	std::string convert(Rectangle infor);
};

class HollowRectangleConverter {
private:
	std::string _hollow;
public:
	HollowRectangleConverter(std::string val);
	std::string convert(Rectangle infor);
};