#pragma once
#include"Book.h"
#include<vector>

class Library {
private:
	vector<Book*> books;
public:
	Library();
	void addBook(Book* book);
	void display();
};