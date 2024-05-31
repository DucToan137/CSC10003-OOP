#pragma once
#include"Employee.h"

class Manager : public Employee {
private:
	int _employeeCount;
	int _paymentPerEmployee;
	int _baseSalary;
public:
	Manager();
	Manager(int employeeCount, int paymentPerEmployee, int baseSalary);
	std::string toString() override;
	int salary() override;
};