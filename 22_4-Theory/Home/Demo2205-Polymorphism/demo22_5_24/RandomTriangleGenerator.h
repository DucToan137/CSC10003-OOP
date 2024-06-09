#pragma once
#include"Ishape.h"
#include"Triangle.h"
#include"RandomDoubleGenerator.h"

using namespace std;

class RandomTriangleGenerator {
private:
	inline static RandomTriangleGenerator* _instance = nullptr;

	RandomTriangleGenerator() {}
public:
	IShape* next(int left, int right) {
		double a = RandomDoubleGenerator::instance()->next(left, right);
		double b = RandomDoubleGenerator::instance()->next(left, right);
		double c = RandomDoubleGenerator::instance()->next(left, right);
		IShape* result = new Triangle(a, b, c);

		return result;
	}

	static RandomTriangleGenerator* instance() {
		if (_instance == nullptr) {
			_instance = new RandomTriangleGenerator();
		}
		return _instance;
	}
};