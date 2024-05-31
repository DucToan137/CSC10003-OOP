#pragma once


class Date {
private:
	int _day;
	int _month;
	int _year;
public:
	int Day();
	int Month();
	int Year();
	void setDay(int value);
	void setMonth(int value);
	void setYear(int value);
public:
	Date();
public:
	void input();
	void output();
};