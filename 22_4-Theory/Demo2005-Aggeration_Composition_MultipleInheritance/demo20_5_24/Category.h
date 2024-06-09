#pragma once
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<sstream>
#include"Product.h"
#include"Util.h"

using namespace std;

class Category {
private:
	int _id;
	string _name;
public:
	
public:
	int id();
	void setId(int id);
	string name();
	void setName(string name);
	vector<shared_ptr<Product>> products();
public:
	Category();
	Category(int id, string name);
	string toString();
public:
	static vector<shared_ptr<Category>> getAll();
	static vector<shared_ptr<Category>> find(Predicate1 f, void* args);
};