#include<iostream>
#include"Date.h"
using namespace std;

int main() {
	cout << "Nhap xuat 1 ngay trong nam\n";
	
	Date a;
	a.input();

	cout << "Ngay vua duoc nhap: ";
	a.output();
}