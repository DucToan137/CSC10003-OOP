#include"RectangleConverter.h"
#include<iostream>
#include<string>
#include<sstream>


SolidRectangleConverter::SolidRectangleConverter(std::string val)
{
	_solid = val;
}

std::string SolidRectangleConverter::convert(Rectangle infor)
{
	std::stringstream builder;
	for (int i = 0; i < infor.getWidth(); i++)
	{
		for (int j = 0; j < infor.getHeight(); j++)
		{
			builder << _solid;
		}
		builder << "\n";
	}
	std::string result = "";
	result = builder.str();


	return result;
}

HollowRectangleConverter::HollowRectangleConverter(std::string val)
{
	_hollow = val;
}

std::string HollowRectangleConverter::convert(Rectangle infor)
{
	std::stringstream builder;
	for (int i = 0; i < infor.getWidth(); i++)
	{
		for (int j = 0; j < infor.getHeight(); j++)
		{
			if (i > 0 && i < infor.getWidth() - 1 && j>0 && j < infor.getHeight() - 1)
			{
				builder << " ";
			}
			else
			{
				builder << _hollow;

			}
		}
		builder << "\n";
	}
	std::string result = "";
	result = builder.str();

	return result;
}