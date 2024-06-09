#include "RandomInteger.h"
#include <time.h>
#include <cstdlib>

RandomInteger::RandomInteger() {
	srand(time(NULL));
}

int RandomInteger::next() {
	return rand();
}

int RandomInteger::next(int max) {
	int result = rand() % max;
	return result;
}

int RandomInteger::next(int left, int right) {
	return 0;
}