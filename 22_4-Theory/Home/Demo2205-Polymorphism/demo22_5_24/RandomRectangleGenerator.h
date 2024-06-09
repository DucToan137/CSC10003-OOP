#pragma once
#include"Ishape.h"
#include"Rectangle.h"
#include"RandomDoubleGenerator.h"

using namespace std;

class RandomRectangleGenerator {
private:
	inline static RandomRectangleGenerator* _instance = nullptr;

	RandomRectangleGenerator() {}
public:
	IShape* next(int left, int right) {
		double a = RandomDoubleGenerator::instance()->next(left, right);
		double b = RandomDoubleGenerator::instance()->next(left, right);
		IShape * result = new Rectangle(a, b);

		return result;
	}

	static RandomRectangleGenerator* instance() {
		if (_instance == nullptr) {
			_instance = new RandomRectangleGenerator();
		}
		return _instance;
	}
};