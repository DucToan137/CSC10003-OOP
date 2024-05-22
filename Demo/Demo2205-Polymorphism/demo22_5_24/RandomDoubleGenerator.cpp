#include"RandomDoubleGenerator.h"

RandomDoubleGenerator::RandomDoubleGenerator() {
	srand(time(NULL));
}

RandomDoubleGenerator* RandomDoubleGenerator::instance() {
	if (_instance == NULL) {
		_instance = new RandomDoubleGenerator();
	}
	return _instance;
}

double RandomDoubleGenerator::next(int left, int right) {
	double result =left + (double)(rand()) / ((double)(RAND_MAX/(right-left)));

	return result;
}