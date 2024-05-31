#pragma once
#include<iostream>
#include"Book.h"
#include<vector>
#include<fstream>

class Library {
private:
	std::vector<Book> _books;
public:
	Library();
	void addBook(const Book& book);
	void removeBook(const std::string& ISBN);
	void displayAllBooks();
	std::vector<Book>searchBooksByAuthor(const std::string& author);
	std::vector<Book> searchBooksByTitle(const std::string& title);
	void borrowBook(const std::string& ISBN);
	void returnBook(const std::string& ISBN);
	void readBooksFromFile(const std::string& filename);

};