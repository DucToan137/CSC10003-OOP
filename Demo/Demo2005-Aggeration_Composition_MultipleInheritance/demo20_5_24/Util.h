#include<iostream>
#include<vector>
#include<memory>

class Category;
class Product;

typedef bool(*Predicate)(std::shared_ptr<Product> item, void* args); // void* ==> object*

typedef bool(*Predicate1)(std::shared_ptr<Category> item, void* key);

