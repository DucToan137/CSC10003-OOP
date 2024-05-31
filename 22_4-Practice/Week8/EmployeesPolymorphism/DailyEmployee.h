#pragma once
#include"Employee.h"

class DailyEmployee : public Employee {
private:
	int _dayCount;
	int _paymentPerDay;
public:
	DailyEmployee();
	DailyEmployee(int dayCount, int paymentPerDay);
	std::string toString() override;
	int salary() override;
};