#include<iostream>
#include<string>
#include<iomanip>
#include"Book.h"
#include"Fiction.h"
#include"NonFiction.h"
#include"Comic.h"
#include"Parser.h"
#include"Library.h"


using namespace std;


int main() {


	// CAU 1
	/*int testID;
	std::cin >> testID;
	std::cout << std::fixed << std::setprecision(2) << "Test " << testID << ":" << std::endl;


	Fiction a("To Kill a Mockingbird", "Harper Lee", 1960, 18.99, "Pulitzer Prize");
	std::cout << a.getType() << "," << a.getName() << "," << a.getAuthor() << ","
		<< a.getYear() << "," << a.getPrice() << "," << a.getAward() << std::endl;

	NonFiction b("Sapiens", "Yuval Noah Harari", 2011, 22.50, "History");
	std::cout << b.getType() << "," << b.getName() << "," << b.getAuthor() << ","
		<< b.getYear() << "," << b.getPrice() << "," << b.getGenre() << std::endl;

	Comic c("Spider-Man", "Stan Lee", 1962, 12.75, "Superhero");
	std::cout << c.getType() << "," << c.getName() << "," << c.getAuthor() << ","
		<< c.getYear() << "," << c.getPrice() << "," << c.getSeries() << std::endl;

	Book* book;
	book = new Fiction("To Kill a Mockingbird", "Harper Lee", 1960, 18.99, "Pulitzer Prize");
	std::cout << book->getType() << "," << book->getName() << "," << book->getAuthor() << ","
		<< book->getYear() << "," << book->getPrice() << "," << book->getSpecial() << std::endl;

	book = new NonFiction("Sapiens", "Yuval Noah Harari", 2011, 22.50, "History");
	std::cout << book->getType() << "," << book->getName() << "," << book->getAuthor() << ","
		<< book->getYear() << "," << book->getPrice() << "," << book->getSpecial() << std::endl;

	book = new Comic("Spider-Man", "Stan Lee", 1962, 12.75, "Superhero");
	std::cout << book->getType() << "," << book->getName() << "," << book->getAuthor() << ","
		<< book->getYear() << "," << book->getPrice() << "," << book->getSpecial() << std::endl;*/



		// CAU 2
		/*int testID;
		std::cin >> testID;
		std::cout << "Test " << testID << ":" << std::endl;

		std::cout << std::left << std::setw(10) << "Type" << " | "
			<< std::setw(24) << "Name" << " | "
			<< std::setw(18) << "Author" << " | "
			<< std::setw(6) << "Year" << " | "
			<< std::setw(10) << "Price" << " | "
			<< "Special" << std::endl;
		std::cout << std::string(100, '-') << std::endl;

		Book* book;
		book = new Fiction("To Kill a Mockingbird", "Harper Lee", 1960, 18.99, "Pulitzer Prize");
		book->display();
		book = new NonFiction("Sapiens", "Yuval Noah Harari", 2011, 22.50, "History");
		book->display();
		book = new Comic("Spider-Man", "Stan Lee", 1962, 12.75, "Superhero");
		book->display();*/



		// CAU 3
	int testID;
	std::cin >> testID;
	std::cout << "Test " << testID << ":" << std::endl;

	Library library;
	library.addBook(new Fiction("To Kill a Mockingbird", "Harper Lee", 1960, 18.99, "Pulitzer Prize"));
	library.addBook(new NonFiction("Sapiens", "Yuval Noah Harari", 2011, 22.50, "History"));
	library.addBook(new Comic("Spider-Man", "Stan Lee", 1962, 12.75, "Superhero"));

	std::vector<std::string> inputs = {
		"Fiction,1984,George Orwell,1949,15.00,Dystopian",
		"NonFiction,Educated,Tara Westover,2018,20.00,Memoir",
		"Comic,Batman,Bob Kane,1939,13.99,Detective"
	};

	for (const auto& input : inputs) {
		Book* book = Parser::parseBook(input);
		library.addBook(book);
	}

	library.display();





	return 0;
}