#include"Fraction.h"
#include<string>
#include<sstream>
#include<exception>
#include<algorithm>
#include<numeric>


int Fraction::getNumerator() {
	return _num;
}

int Fraction::getDenominator() {
	return _denom;
}

void Fraction::setNumerator(int num) {
	_num = num;
}

void Fraction::setDenominator(int den) {
	_denom = den;
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

void Fraction::simplify() {
	int common = std::gcd(_num, _denom);
	_num = _num / common;
	_denom = _denom / common;
	if (_denom < 0)
	{
		_num = -_num;
		_denom = -_denom;
	}
}

Fraction Fraction::add(Fraction other)
{
	Fraction result;
	
	int tu = other.getNumerator() * _denom + other.getDenominator() * _num;
	int mau = other.getDenominator() * _denom;

	result.setNumerator(tu);
	result.setDenominator(mau);

	result.simplify();
	return result;

}
Fraction Fraction::subtract(Fraction other)
{
	Fraction result;

	int tu =  other.getDenominator() * _num - other.getNumerator() * _denom;
	int mau = other.getDenominator() * _denom;

	result.setNumerator(tu);
	result.setDenominator(mau);

	result.simplify();
	return result;
}

Fraction Fraction::multiply(Fraction other)
{
	Fraction result;

	int tu = other.getNumerator() * _num;
	int mau = other.getDenominator() * _denom;

	result.setNumerator(tu);
	result.setDenominator(mau);

	result.simplify();
	return result;
}

Fraction Fraction::divide(Fraction other)
{
	Fraction result;

	int tu = _num * other.getDenominator();
	int mau = _denom * other.getNumerator();

	result.setNumerator(tu);
	result.setDenominator(mau);

	result.simplify();
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
