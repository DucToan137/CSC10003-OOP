#pragma once
#include"Book.h"

class Fiction : public Book {
public:
	Fiction() {};
	Fiction(string name, string author, int year, double price, string special);
	string getType() override;
	string getAward();
	void display();
};

