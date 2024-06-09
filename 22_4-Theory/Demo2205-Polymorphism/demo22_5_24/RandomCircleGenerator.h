#pragma once
#include"Ishape.h"
#include"Circle.h"
#include"RandomDoubleGenerator.h"

using namespace std;

class RandomCircleGenerator {
private:
	inline static RandomCircleGenerator* _instance = nullptr;

	RandomCircleGenerator() {}
public:
	IShape* next(int left, int right) {
		double r = RandomDoubleGenerator::instance()->next(left, right);

		IShape* result = new Circle(r);

		return result;
	}

	static RandomCircleGenerator* instance() {
		if (_instance == nullptr) {
			_instance = new RandomCircleGenerator();
		}
		return _instance;
	}
};