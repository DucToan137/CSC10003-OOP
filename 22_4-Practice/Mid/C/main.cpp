#include<fstream>
#include<iostream>
#include<vector>
#include<iomanip>	
#include<string>
using namespace std;

class Product {
private:
	string _productName;
	int _productID;
	float _price;
	int _quantity;

public:
	Product();
	Product(string name, int id, float price, int quantity);
public:
	string getProductName();
	void setProductName(string name);
	int getProductID();
	void setProductID(int id);
	float getPrice();
	void setPrice(float price);
	int getQuantity();
	void setQuantity(int quantity);
};

Product::Product() 
{
	_productName = "";
	_productID = 0;
	_price = 0;
	_quantity = 0;
}

Product::Product(string name, int id, float price, int quantity) 
{
	_productName = name;
	_productID = id;
	_price = price;
	_quantity = quantity;
}

string Product::getProductName() 
{
	return _productName;
}

void Product::setProductName(string name) 
{
	_productName = name;
}

int Product::getProductID() 
{
	return _productID;
}

void Product::setProductID(int id) 
{
	_productID = id;
}

float Product::getPrice() 
{
	return _price;
}

void Product::setPrice(float price) 
{
	_price = price;
}

int Product::getQuantity() 
{
	return _quantity;
}

void Product::setQuantity(int quantity) 
{
	_quantity = quantity;
}



class Inventory {
private:
	vector<Product> _products;

public:
	void addProduct(const Product& product);
	void removeProduct(int productID);
	void readFromFile(string filename);
	void displayAllProducts();
	Product* findProductByID(int productID);
};



void Inventory::addProduct(const Product& product) 
{
	_products.push_back(product);
}

void Inventory::removeProduct(int productID) 
{
	for (int i = 0; i < _products.size(); i++) 
	{
		if (_products[i].getProductID() == productID) 
		{
			_products.erase(_products.begin() + i);
		}
	}
}

void Inventory::readFromFile(string filename) 
{
	ifstream input(filename);
	if (input.fail()) {
		return;
	}

	int n; 
	input >> n;

	for (int i = 0; i < n; i++) 
	{
		string productName;
		int productID;
		float price;
		int quantity;

		input >> productName >> productID >> price >> quantity;
		addProduct({ productName, productID, price, quantity });
	}
}

void Inventory::displayAllProducts() 
{
	cout << "Product Name,Product ID,Price,Quantity\n";
	for (int i = 0; i < _products.size(); i++) {
		cout << _products[i].getProductName() << "," 
			<< _products[i].getProductID() << ","
			<< std::fixed << std::setprecision(2) 
			<<_products[i].getPrice() << "," 
			<< _products[i].getQuantity() << "\n";
	}
}

Product* Inventory::findProductByID(int productID) 
{
	for (int i = 0; i < _products.size(); i++) 
	{
		if (_products[i].getProductID() == productID) 
		{
			return &_products[i];
		}
	}
	return nullptr;
}


int main() {


	return 0;
}

//#include "main.h"

