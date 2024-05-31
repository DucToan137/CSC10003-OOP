#include<iostream>
#include<iomanip>
#include"Date.h"

using namespace std;

int Date::Day() {
	return _day;
}

int Date::Month() {
	return _month;
}

int Date::Year() {
	return _year;
}

void Date::setDay(int value) {
	_day = value;
}

void Date::setMonth(int value) {
	_month = value;
}

void Date::setYear(int value) {
	_year = value;
}

Date::Date() {
	_day = 1;
	_month = 1;
	_year = 2000;
}

void Date::input() {
	cout << "Nhap ngay:";
	cin >> _day;

	cout << "Nhap thang:";
	cin >> _month;

	cout << "Nhap nam:";
	cin >> _year;
}

void Date::output() {
	cout << setw(2) << setfill('0') << _day << "/" << setw(2) << setfill('0') << _month << "/" << _year;
}
