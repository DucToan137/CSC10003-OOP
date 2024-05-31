#include"Book.h"
#include<iostream>

Book::Book() {}

Book::Book(std::string title, std::string author, std::string ISBN) {
	_title = title;
	_author = author;
	_ISBN = ISBN;
	_available = true;
}

std::string Book::getTitle() {
	return _title;
}

void Book::setTitle(std::string title) {
	_title = title;
}

std::string Book::getAuthor() {
	return _author;
}

void Book::setAuthor(std::string author) {
	_author = author;
}

std::string Book::getISBN() {
	return _ISBN;
}

void Book::setISBN(std::string ISBN) {
	_ISBN = ISBN;
}

bool Book::isAvailable() {
	return _available;
}

void Book::returnBook() {
	_available = true;
}

void Book::borrowBook() {
	_available = false;
}


void Book::displayBook() {
	std::cout << "Title: " << _title << std::endl;
	std::cout << "Author: " << _author << std::endl;
	std::cout << "ISBN: " << _ISBN << std::endl;
	std::cout << "Availability: ";
	if (_available) {
		std::cout << "Available\n";
	}
	else {
		std::cout << "Unavailable\n";
	}
}