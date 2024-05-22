#pragma once
#include"Category.h"


int Category::id() {
	return _id;
}

void Category::setId(int id) {
	_id = id;
}

string Category::name() {
	return _name;
}

void Category::setName(string name) {
	_name = name;
}

Category::Category() {
	_id = 0;
	_name = "";
}

Category::Category(int id, string name) {
	_id = id;
	_name = name;
}

vector<shared_ptr<Category>> Category::getAll() {
	vector<shared_ptr<Category>> result;

	result.push_back(make_shared<Category>(4, "Tablet"));
	result.push_back(make_shared<Category>(5, "Speaker"));
	result.push_back(make_shared<Category>(6, "VGA"));
	result.push_back(make_shared<Category>(7, "Monitor"));

	return result;
}

vector<shared_ptr<Product>> Category::products() {
	vector<shared_ptr<Product>> result;



	return result;
}

string Category::toString() {
	stringstream builder;

	builder << "	ID= " << _id << ", Name= " << _name;
	string result = builder.str();
	
	return result;
}

vector<shared_ptr<Category>> Category::find(Predicate1 f, void* args) {
	vector<shared_ptr<Category>> a;
	
	a.push_back(make_shared<Category>(4, "Tablet"));
	a.push_back(make_shared<Category>(5, "Speaker"));
	a.push_back(make_shared<Category>(6, "VGA"));
	a.push_back(make_shared<Category>(7, "Monitor"));
	a.push_back(make_shared<Category>(8, "Laptop"));
	a.push_back(make_shared<Category>(9, "Laptop"));
	a.push_back(make_shared<Category>(10, "VGA"));

	vector<shared_ptr<Category>> result;

	for (int i = 0; i < a.size(); i++) {
		if (f(a[i], args)) {
			result.push_back(a[i]);
		}
	}


	return result;
}