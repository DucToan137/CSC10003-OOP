#include<iostream>
#include"Point.h"
using namespace std;


int main() {
	cout << "Nhap xuat diem\n";

	cout << "Nhap vao mot diem\n";
	Point a;
	a.input();

	cout << "Diem vua nhap: ";
	a.output();

	return 0;
}