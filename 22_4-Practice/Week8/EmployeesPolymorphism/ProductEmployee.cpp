#include"ProductEmployee.h"

ProductEmployee::ProductEmployee() {
	_productCount = 0;
	_paymentPerProduct = 0;
}
ProductEmployee::ProductEmployee(int productCount, int paymentPerProduct) {
	_productCount = productCount;
	_paymentPerProduct = paymentPerProduct;
}

std::string ProductEmployee::toString() {
	return "Product employee";
}

int ProductEmployee::salary() {
	return _paymentPerProduct * _productCount;
}