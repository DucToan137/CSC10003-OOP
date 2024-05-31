#include"Manager.h"

Manager::Manager() {
	_employeeCount = 0;
	_paymentPerEmployee = 0;
	_baseSalary = 0;
}
Manager::Manager(int employeeCount, int paymentPerEmployee, int baseSalary) {
	_employeeCount = employeeCount;
	_paymentPerEmployee = paymentPerEmployee;
	_baseSalary = baseSalary;
}

std::string Manager::toString() {
	return "Manager";
}
int Manager::salary() {
	return _employeeCount * _paymentPerEmployee + _baseSalary;
}