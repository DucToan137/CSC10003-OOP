#pragma once
#include<iostream>
#include<string>

class Book {
private:
	std::string _title;
	std::string _author;
	std::string _ISBN;
	bool _available;
public:
	Book();
	Book(std::string title, std::string author, std::string ISBN);
	std::string getTitle();
	std::string getAuthor();
	std::string getISBN();
	void setTitle(std::string title);
	void setAuthor(std::string author);
	void setISBN(std::string ISBN);
	bool isAvailable();
	void borrowBook();
	void returnBook();
	void displayBook();
};