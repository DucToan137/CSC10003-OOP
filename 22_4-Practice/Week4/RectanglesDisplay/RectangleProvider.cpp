#include"RectangleProvider.h"
#include<iostream>
#include<fstream>

std::vector<Rectangle> RectangleProvider::getAll() {
	std::vector<Rectangle> a;

	//return { // Hard code at this week is enough
	//	Rectangle(3, 4),
	//	Rectangle(4, 5),
	//	Rectangle(4, 8)
	//};

	std::ifstream input;
	input.open("rectangle.inp", std::ios::in);

	if (input.is_open())
	{
		int n = 0;
		int h = 0;
		int w = 0;
		input >> n;

		for (int i = 0; i < n; i++)
		{

			input >> w >> h;
			Rectangle b;
			b.setWidth(w);
			b.setHeight(h);

			a.push_back(b);
		}
	}
	else
	{
		std::cout << "Khong the mo file\n";
	}

	return a;
}