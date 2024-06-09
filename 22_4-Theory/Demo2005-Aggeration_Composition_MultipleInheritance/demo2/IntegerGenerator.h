#pragma once
#include<iostream>

class IntegerGenerator {
private:
	inline static IntegerGenerator* _instance = nullptr;

	IntegerGenerator()
	{
		srand(time(NULL));
	};
public:
	int next() {
		return rand();
	}

	int next(int ceiling) {
		return rand() % ceiling;
	}

	int next(int left, int right) {
		return rand() % (right - left + 1) + left;
	}

	static IntegerGenerator* instance() {
		if (_instance == nullptr)
		{
			_instance = new IntegerGenerator();
		}

		return _instance;
	}
};