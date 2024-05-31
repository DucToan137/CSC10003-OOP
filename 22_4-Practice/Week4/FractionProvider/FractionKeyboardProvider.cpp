#include"FractionKeyboardProvider.h"
#include<regex>
#include<sstream>


Fraction FractionKeyboardProvider::next() {
    try {
        std::string buffer;
        getline(std::cin, buffer);

        Fraction f;

        if (buffer.length() == 0)
        {
            throw std::exception("Empty input string is not allowed");
        }

        std::regex fractionPattern("\\d+/\\d+");
        if (!std::regex_match(buffer, fractionPattern)) {
            throw std::exception("Invalid fraction format is not allowed");
        }

        const char SEPARATOR = '/';
        std::istringstream reader(buffer);
        std::string left;
        getline(reader, left, SEPARATOR);

        std::string right;
        getline(reader, right);

        int num = stoi(left);
        int den = stoi(right);

        if (den == 0) {
            throw std::exception("DividedByZero");
        }
        f.setNumerator(num);
        f.setDenominator(den);

        return f;
    }
    catch (std::exception e) {
        std::cout << "Exception: " << e.what() << "\n";

        std::cout << "Nhap vao mot phan so.\n";

        Fraction f;
        FractionKeyboardProvider provider;
        f = provider.next();

        return f;
    }
   
}