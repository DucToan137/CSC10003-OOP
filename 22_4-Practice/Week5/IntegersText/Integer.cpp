#include"Integer.h"
#include<iostream>
#include<string>



int Integer::OddEven()
{
	if (_num % 2 == 0)
	{
		return 0;
	}
	return 1;
}
int Integer::PalindromicNumber()
{
	std::string xau1 = std::to_string(_num);
	
	std::string xau2(xau1.rbegin(), xau1.rend());

	if (xau1 == xau2)
	{
		return 1;
	}
	return 0;
}


int Integer::PrimeNumber()
{
	int dem = 0;
	for (int i = 1; i <= _num; i++)
	{
		if (_num % i == 0)
		{
			dem++;
		}
	}
	if (dem == 2)
	{
		return 1;
	}
	return 0;
}


int Integer::SquareNumber()
{
	for (int i = 1; i < _num; i++)
	{
		if (i * i == _num)
		{
			return 1;
		}
	}
	return 0;

}


int Integer::PerfectNumber()
{
	int sum = 0;
	for (int i = 1; i < _num; i++)
	{
		if (_num % i == 0)
			sum += i;
	}
	if (sum == _num)
	{
		return 1;
	}
	return 0;
}