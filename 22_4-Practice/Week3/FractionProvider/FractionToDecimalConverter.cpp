#include"FractionToDecimalConverter.h"
#include"NumberFormat.h"
#include"Fraction.h"
#include<iomanip>
#include<sstream>


FractionToDecimalConverter::FractionToDecimalConverter(NumberFormat config) {
	_config = config;
}

std::string FractionToDecimalConverter::convert(const Fraction& f) {
    Fraction Ftmp = f;
    FractionToDecimalConverter converter(_config);
    
    std::string result = "";
    double res = (double)Ftmp.getNum() / Ftmp.getDenom();
    std::string thphan = std::to_string(res);

    std::stringstream builder1;
    builder1 << std::fixed << std::setprecision(_config.getPrecision()) << res;
    
    const char SEPARATOR = '.';
    result = builder1.str();

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

    builder2 << left << _config.getDecimalSeparator() << right;
    result = builder2.str();

    return result;
}

