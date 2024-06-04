#pragma once
#include"Book.h"

class NonFiction : public Book {
public:
	NonFiction() {};
	NonFiction(string name, string author, int year, double price, string special);
	string getType() override;
	string getGenre();
	void display();
};

