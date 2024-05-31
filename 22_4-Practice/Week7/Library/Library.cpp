#include"Library.h"

Library::Library() {

}

void Library::addBook(const Book& book) {
	_books.push_back(book);
}

void Library::removeBook(const std::string& ISBN) {
	for (int i = 0; i < _books.size(); i++) {
		if (_books[i].getISBN() == ISBN) {
			_books.erase(_books.begin() + i);
			break;
		}
	}
}

void Library::displayAllBooks() {
	std::cout << "There are " << _books.size() << " books in the library: \n";


	for (int i = 0; i < _books.size(); i++) {
		_books[i].displayBook();
		if (i < _books.size() - 1)
		{
			std::cout << "======================\n";
		}
		else
		{
			std::cout << "****************************************\n";

		}

	}
}

std::vector<Book> Library::searchBooksByAuthor(const std::string& author) {
	std::vector<Book> booksByAuthor;
	for (int i = 0; i < _books.size(); i++) {
		if (_books[i].getAuthor() == author) {
			booksByAuthor.push_back(_books[i]);
		}
	}
	return booksByAuthor;
}

std::vector<Book> Library::searchBooksByTitle(const std::string& title) {
	std::vector<Book> booksByTitle;
	for (int i = 0; i < _books.size(); i++) {
		if (_books[i].getTitle() == title) {
			booksByTitle.push_back(_books[i]);
		}
	}
	return booksByTitle;
}

void Library::borrowBook(const std::string& ISBN) {
	for (int i = 0; i < _books.size(); i++) {
		if (_books[i].getISBN() == ISBN) {
			_books[i].borrowBook();
			break;
		}
	}
}

void Library::returnBook(const std::string& ISBN) {
	for (int i = 0; i < _books.size(); i++) {
		if (_books[i].getISBN() == ISBN) {
			_books[i].returnBook();
			break;
		}
	}
}

void Library::readBooksFromFile(const std::string& filename) {
	std::ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		std::cout << "Error opening file\n";
		return;
	}
	int n;
	file >> n;
	
	file.ignore();	
	for (int i = 0; i < n; i++)
	{
		std::string title, author, ISBN;

		getline(file,title);
		getline(file, author);
		getline(file, ISBN);

		Book book(title, author, ISBN);
		addBook(book);
	}
	file.close();
}
