#pragma once
#include"Book.h"

class Comic : public Book {
public:
	Comic() {};
	Comic(string name, string author, int year, double price, string special);
	string getType() override;
	string getSeries();
	void display();
};

