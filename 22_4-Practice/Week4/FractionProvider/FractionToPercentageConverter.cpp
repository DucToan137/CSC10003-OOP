#include"FractionToPercentageConverter.h"
#include<sstream>
#include<iomanip>

FractionToPercentageConverter::FractionToPercentageConverter(NumberFormat config) {
	_config = config;
}

std::string FractionToPercentageConverter :: convert(const Fraction& f) {
	std::string result = "";
    Fraction Ftmp = f;
	FractionToPercentageConverter converter(_config);
	

	double res = ((double)Ftmp.getNumerator() / Ftmp.getDenominator()) * 100;

	std::stringstream builder1;
	builder1 << std::fixed << std::setprecision(_config.getPrecision()) << res;

	result = builder1.str();

    const char SEPARATOR = '.';
    const char PERCENT = '%';

    //result = builder1.str();

    std::istringstream reader(result);
    std::string left;
    getline(reader, left, SEPARATOR);

    std::string right;
    getline(reader, right);

    int count = 0;
    std::string tmp = "";

    for (int i = left.length() - 1; i >= 0; --i) {
        tmp = left[i] + tmp;
        count++;
        if (count % 3 == 0 && i != 0) {
            tmp = _config.getThounsandSeparator() + tmp;
        }
    }
    left = tmp;

	std::stringstream builder2;

	builder2 << left << _config.getDecimalSeparator() << right << PERCENT;
	result = builder2.str();

	return result;
}