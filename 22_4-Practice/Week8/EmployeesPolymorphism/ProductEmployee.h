#pragma once
#include"Employee.h"

class ProductEmployee : public Employee {
private:
	int _productCount;
	int _paymentPerProduct;
public:
	ProductEmployee();
	ProductEmployee(int productCount, int paymentPerProduct);
	std::string toString() override;
	int salary() override;
};


