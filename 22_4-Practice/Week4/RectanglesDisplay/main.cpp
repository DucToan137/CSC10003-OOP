#include<iostream>
#include"Rectangle.h"
#include"RectangleConverter.h"
#include"RectangleProvider.h"
#include<string>
using namespace std;

int main() {
	
	
	auto rectangles = RectangleProvider::getAll();
	
	SolidRectangleConverter solid("*");
	HollowRectangleConverter hollow("-");

	for (auto rectangle : rectangles) {
		std::cout << rectangle.toString() << "\n";
		std::cout << solid.convert(rectangle) << "\n";
		std::cout << hollow.convert(rectangle) << "\n";
		std::cout << "\n";
	}




	return 0;
}