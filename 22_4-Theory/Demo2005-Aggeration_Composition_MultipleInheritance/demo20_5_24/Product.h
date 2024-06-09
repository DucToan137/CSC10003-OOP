#pragma once
#include<iostream>
#include<memory>
#include<vector>
#include<string>
#include<sstream>
#include"Util.h"


using namespace std;

class Category;
class Product {
private:
	int _id;
	string _name;
	int _price;
	weak_ptr<Category> _category;
public:
	int id();
	void setId(int id);
	string name();
	void setName(string name);
	int price();
	void setPrice(int price);
	weak_ptr<Category> category();
	void setCategory(weak_ptr<Category> value);
public:
	Product();
	Product(int id, string name, int price);
	string toString();
	static vector<shared_ptr<Product>> find(Predicate f, void* args);
};