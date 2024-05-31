#include<iostream>
#include"Line.h"

using namespace std;

int main() {

	cout << "Nhap xuat duong thang\n";

	cout << "Nhap vao hai diem\n";
	Line a;
	a.input();

	cout << "Duong thang vua nhap: ";
	a.output();


	return 0;
}