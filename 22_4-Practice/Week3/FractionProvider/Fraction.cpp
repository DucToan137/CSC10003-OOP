#include"Fraction.h"
#include<string>
#include<sstream>
#include<exception>
#include<algorithm>
#include<numeric>


int Fraction::getNum() {
	return _num;
}

int Fraction::getDenom() {
	return _denom;
}

void Fraction::setNum(int val) {
	_num = val;
}

void Fraction::setDenom(int val) {
	_denom = val;
}

Fraction::Fraction() {
	_num = 0;
	_denom = 1;
}

Fraction::Fraction(int num, int den) {
	if (den == 0) {
		throw std::exception("Divided by zero");
	}

	this->_num = num;
	this->_denom = den;
}

std::string Fraction::toString() {
	std::string result = "";
	std::string SEPARATOR = "/";
	std::stringstream out;

	out << _num << SEPARATOR << _denom;
	result = out.str();

	return result;
}

std::string Fraction::Lowest_Mixed() {

	std::string result = "";
	std::string SEPARATOR = "/";
	std::stringstream out;

	int common = std::gcd(_num, _denom);

	if (_num >= _denom)
	{
		if (_num % _denom == 0)
		{
			int res = _num / _denom;
			result = std::to_string(res);
			return result;
		}
		else
		{
			int nguyen = _num / _denom;
			int tu = _num % _denom;
			int mau = _denom / common;
			out << nguyen << " " << tu << SEPARATOR << mau;
			result = out.str();
			return result;
		}
	}
	else
	{
		int tu = _num / common;
		int mau = _denom / common;
		out << tu << SEPARATOR << mau;
		result = out.str();

		if (_num == tu && _denom == mau)
		{
			result = "Khong co dinh dang khac";
		}
	}
	

	return result;
}
