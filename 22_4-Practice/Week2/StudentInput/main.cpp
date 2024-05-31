#include<iostream>
#include"Student.h"
using namespace std;

int main() {
	cout << "Nhap xuat thong tin cua 1 hoc sinh\n";
	Student a;
	a.input();

	cout << "Thong tin hoc sinh vua duoc nhap: ";
	a.output();
	return 0;
}