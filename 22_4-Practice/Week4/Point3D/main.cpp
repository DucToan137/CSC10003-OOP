#include<iostream>
#include"Point3D.h"

int main() {
	Point3D a(1, 0, 3);
	Point3D b(0, 0, 0);
	a.rotate();

	std::cout << a.getX() << a.getY() << a.getZ();

	//std::cout << a.distance(b);
	return 0;
}