#pragma once
#include<iostream>
using namespace std;

class RandomIntegerGenerator {
private:
	inline static RandomIntegerGenerator* _instance = nullptr;

	RandomIntegerGenerator();
public:
	int next(int left, int right);
	int next(int ceiling);
	static RandomIntegerGenerator* instance();
};