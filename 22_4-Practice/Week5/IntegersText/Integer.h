#pragma once
#include<iostream>
#include<vector>

class Integer {
private:
	int _num;
public:
	/*std::vector<int> OddNumber(std::vector<int> a);
	std::vector<int> EvenNumber(std::vector<int> a);
	std::vector<int> PalindromicNumber(std::vector<int> a);
	std::vector<int> PrimeNumber(std::vector<int> a);
	std::vector<int> SquareNumber(std::vector<int> a);
	std::vector<int> PerfectNumber(std::vector<int> a);
	int Minimum(std::vector<int>a);
	int Maximum(std::vector<int>a);
	double Average(std::vector<int>a);
	int Sum(std::vector<int>a);*/
	void setNum(int val) { _num = val; }
	int getNum() { return _num; }

	int OddEven();
	int PalindromicNumber();
	int PrimeNumber();
	int SquareNumber();
	int PerfectNumber();
};