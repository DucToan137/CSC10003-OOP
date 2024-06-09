#pragma once
#include<iostream>
using namespace std;


class RandomDoubleGenerator {
private:
	inline static RandomDoubleGenerator* _instance = nullptr;

	RandomDoubleGenerator();
public:
	double next(int left, int right);
	static RandomDoubleGenerator* instance();
};