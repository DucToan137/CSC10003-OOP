#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<memory>
#include<fstream>
#include<regex>
#include<tuple>
#include"Category.h"
#include"Product.h"
#include"Util.h"

using namespace std;



void displayMenu() {
	cout << "What do you want to do?\n";
	cout << "1. Display all categories\n";
	cout << "2. Find products by name\n";
	cout << "3. Find products by price range\n";
	cout <<"4. Find categories by name\n\n";
	cout << "0. Quit\n";
	cout << "Enter your choice: ";
}

tuple<bool, int, string, int> getChoice() {
	const string choicePattern = "[01234]";
	bool success = true;
	int errorCode = 0;
	string message = "";
	int choice = 0;

	string buffer;
	getline(cin, buffer);

	if (buffer.length() == 0) {
		success = false;
		errorCode = 1;
		message = "Input string cannot be empty.";
	}
	else
	{
		bool isValid = regex_match(buffer, regex(choicePattern));

		if (isValid) {
			success = true;
			choice = stoi(buffer);
		}
		else
		{
			success = false;
			errorCode = 2;
			message = "Invalid format.";
		}
	}

	auto result =make_tuple(success, errorCode, message, choice);
	return result;
}

//struct {
//	vector<int> categories;
//} state;

//state.categories[0];

void displayAllCategories() {
	cout << "\n";
	auto categories = Category::getAll();
	cout << "Found " << categories.size() << " category(s)\n";
	// i18n - Ngoi - So, giong 

	for (int i = 0; i < categories.size(); i++)
	{
		auto category = categories[i];
		cout << categories[i]->toString() << "\n";
	}

	cin.get();
}

class Choice {
public:
	static const int quit = 0;
	static const int displayAllCategories = 1;
	static const int findProductsByName = 2;
	static const int findProductsByPriceRange = 3;
	static const int findCategoriesByName = 4;
};

bool shouldContains(shared_ptr<Product> item, void* key) {
	auto product = (shared_ptr<Product>) item;
	auto keyword = *((string*)key); // void* -> string* -> string

	bool found = product->name().find(keyword) != string::npos;

	return found;
}

void findProductsByName() {
	// Nhập keyword
	string keyword;
	bool shouldRepeat = false;

	do {
		cout << "Nhap tu khoa de tim kiem: ";
		getline(cin, keyword);

		if (keyword.length() == 0)
		{
			cout <<"Tu khoa khong duoc de trong.\n\n";
			shouldRepeat = true;
		}
		else
		{
			vector<shared_ptr<Product>> products = Product::find(shouldContains, (void*) &keyword );

			cout << "Found " << products.size() << " product(s).\n";
			for (int i = 0; i < products.size(); i++)
			{
				cout << " " << products[i]->toString() << "\n";
			}

			cout << "\n";
			cin.get();

			shouldRepeat = false;
		}
	}while(shouldRepeat);
	


}

bool priceShouldBeIn(shared_ptr<Product> item, void* args) { // Object
	int min;
	int max;
	tie(min, max) = *((tuple<int, int>*) args);

	bool result =item->price() >= min && item->price() <= max;


	return result;
}

void findProductsByPriceRange() {
	int min = 20000000;
	int max = 30000000;
	tuple<int, int> range = make_pair(min, max);
	bool shouldRepeat = false;

	auto products = Product::find(priceShouldBeIn, (void*)&range);

	cout << "Found " << products.size() << " product(s).\n";
	for (int i = 0; i < products.size(); i++)
	{
		cout << " " << products[i]->toString() << "\n";
	}

	cout << "\n";
	cin.get();

	shouldRepeat = false;

	/*do {
		
		
	} while (shouldRepeat);*/
}	

bool shouldContains1(shared_ptr<Category> item, void* key) {
	auto category = (shared_ptr<Category>) item;
	auto keyword = *((string*)key); // void* -> string* -> string

	bool found = category->name().find(keyword) != string::npos;

	return found;
}

void findCateforiesByName() {
	string keyword;
	bool shouldRepeat = false;

	do {
		cout << "Nhap tu khoa de tim kiem: ";
		getline(cin, keyword);
		
		if (keyword.length() == 0)
		{
			cout << "Tu khoa khong duoc de trong.\n\n";
			shouldRepeat = true;
		}
		else
		{
			vector<shared_ptr<Category>> categories = Category::find(shouldContains1, (void*)&keyword);

			cout << "Found " << categories.size() << " category(s).\n";
			for (int i = 0; i < categories.size(); i++)
			{
				cout << " " << categories[i]->toString() << "\n";
			}

			cout << "\n";
			cin.get();

			shouldRepeat = false;
		}	

	}while(shouldRepeat);
}

int main() {

	bool shouldContinue = true;

	

	bool success = true;
	int errorCode = 0;
	string message = "";
	int choice = 0;

	do {
		displayMenu();

		/*string buffer;
		getline(cin, buffer);*/

		/*if (buffer.length() == 0) {
			cout <<"Please enter your choice\n";
			shouldContinue = true;
		}
		else
		{
			bool isValid = regex_match(buffer, regex(choicePattern));

			if (isValid) {
				int choice = stoi(buffer);
				if (choice == quit)
				{
					shouldContinue = false;
				}
				else if (choice == displayAllCategories)
				{
					shouldContinue = true;
				}
				else if (choice == findProductsByName)
				{
					shouldContinue = true;
				}
				else if (choice == findProductsByPriceRange)
				{
					shouldContinue = true;
				}
			}
			else
			{
				cout <<"Invalid format. Please enter your choice again.\n";
				shouldContinue = true;
			}
		}*/

		tie(success, errorCode, message, choice) = getChoice();
		if (success) {
			if (choice == Choice::quit)
			{
				shouldContinue = false;
			}
			else if (choice == Choice::displayAllCategories)
			{
				displayAllCategories();

				shouldContinue = true;
			}
			else if (choice == Choice::findProductsByName)
			{
				findProductsByName();

				shouldContinue = true;
			}
			else if (choice == Choice::findProductsByPriceRange)
			{
				findProductsByPriceRange();

				shouldContinue = true;
			}
			else if (choice == Choice::findCategoriesByName)
			{
				findCateforiesByName();

				shouldContinue = true;
			}
		}
		else
		{
			cout << "\n" << message << "\n";
			cout << "--------------------------------\n";
			cout << "\n\n";
			shouldContinue = true;
		}
	} while (shouldContinue);

	return 0;
}