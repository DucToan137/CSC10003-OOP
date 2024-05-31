#include"DailyEmployee.h"

DailyEmployee::DailyEmployee() {
	_dayCount = 0;
	_paymentPerDay = 0;
}
DailyEmployee::DailyEmployee(int dayCount, int paymentPerDay) {
	_dayCount = dayCount;
	_paymentPerDay = paymentPerDay;
}

std::string DailyEmployee::toString() {
	return "Daily employee";
}
int DailyEmployee::salary() {
	return _paymentPerDay * _dayCount;
}

