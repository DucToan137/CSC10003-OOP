#include"RandomIntergerGenerator.h"

RandomIntegerGenerator::RandomIntegerGenerator() {
	srand(time(NULL));
}

RandomIntegerGenerator* RandomIntegerGenerator::instance() {
	if (_instance == NULL) {
		_instance = new RandomIntegerGenerator();
	}
	return _instance;
}

int RandomIntegerGenerator::next(int left, int right) {
	int result = left + rand() % (right - left + 1);

	return result;
}

int RandomIntegerGenerator::next(int ceiling) {
	int result = rand() % ceiling;

	return result;
}

