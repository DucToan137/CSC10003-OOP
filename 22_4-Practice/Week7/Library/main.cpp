#include<iostream>
#include"Library.h"

int main() {
    Library library;
    library.readBooksFromFile("library.txt");
    library.addBook(Book("Thien ac va smartphone", "Dang Hoang Giang", "456abc"));
    library.displayAllBooks();

    library.addBook(Book("Buc xuc khong lam ta vo can", "Dang Hoang Giang", "123xyz"));
    std::vector<Book> books = library.searchBooksByAuthor("Dang Hoang Giang");
    for (Book book : books) library.borrowBook(book.getISBN());
    books = library.searchBooksByTitle("Thien ac va smartphone");
    for (Book book : books) library.removeBook(book.getISBN());
    library.removeBook("978-3-16-148413-1");
    library.displayAllBooks();

	return 0;
}