#pragma once
#include"Product.h"

int Product::id() {
	return _id;
}

void Product::setId(int id) {
	_id = id;
}

string Product::name() {
	return _name;
}

void Product::setName(string name) {
	_name = name;
}

int Product::price() {
	return _price;
}

void Product::setPrice(int price) {
	_price = price;
}

weak_ptr<Category> Product::category() {
	return _category;
}

void Product::setCategory(weak_ptr<Category> value) {
	_category = value;
}

Product::Product() {
	_id = 0;
	_name = "";
	_price = 0;
}

Product::Product(int id, string name, int price) {
	_id = id;
	_name = name;
	_price = price;
}

string Product::toString() {
	stringstream builder;

	builder << "ID= " << _id << ", Name= " << _name << ", Price= " << _price;
	string result = builder.str();

	return result;
}

vector<shared_ptr<Product>> Product::find(Predicate sastisfy, void* args) {
	vector<shared_ptr<Product>> a; // Đọc từ tập tin
	
	a.push_back(make_shared<Product>(3, "iPad Air 5 64GB", 17000000));
	a.push_back(make_shared<Product>(4, "iPad Mini 5 256GB", 20000000));
	a.push_back(make_shared<Product>(5, "iPad Pro 11 256GB", 25000000));
	a.push_back(make_shared<Product>(6, "iPad Pro 12.9 256GB", 30000000));
	a.push_back(make_shared<Product>(7, "Samsung Pro 12.9 512GB", 35000000));
	a.push_back(make_shared<Product>(8, "Huawei Pro 11 512GB", 40000000));

	vector<shared_ptr<Product>> result;

	// Lọc lại dựa trên hàm kiểm tra
	for (int i = 0; i < a.size(); i++)
	{
		if (sastisfy(a[i], args))
		{
			result.push_back(a[i]);
		}
	}

	return result;
}
