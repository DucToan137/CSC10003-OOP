#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>

using namespace std;

class Book {
protected:
	string _name;
	string _author;
	int _year;
	double _price;
	string _special;
public:
	string getSpecial();
	virtual string getType() = 0;
public:
	Book();
	string getName();
	string getAuthor();
	int getYear();
	double getPrice();
	Book(string name, string author, int year, double price, string special);
	void display();
};


