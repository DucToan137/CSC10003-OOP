
#include<iostream>
#include<fstream>
#include<tuple>
#include<vector>
#include<regex>
#include<string>
#include<iomanip>
#include<sstream>
#include<locale>
#include<cmath> 
#include<format>
#include<string>

class NumberFormat {
private:
    std::string _thousandSeparator; // "." / "," / " "
    std::string _decimalSeparator;  // "," / "."
    int _precision; // 2 / 3
public:
    NumberFormat();
    NumberFormat(std::string thousand, std::string dec, int precision);
    std::string get_thousandSeparator();
    std::string get_decimalSeparator();
    int get_precision();
};

NumberFormat::NumberFormat(std::string thousand, std::string dec, int precision) {
    _thousandSeparator = thousand;
    _decimalSeparator = dec;
    _precision = precision;
}

NumberFormat::NumberFormat() {}

std::string NumberFormat::get_decimalSeparator() {
    return _decimalSeparator;
}

std::string NumberFormat::get_thousandSeparator() {
    return _thousandSeparator;
}

int NumberFormat::get_precision() {
    return _precision;
}

class Fraction {
private:
    int _num;
    int _den;
public:
    int getNumerator();
    int getDenominator();
    void setNumerator(int value);
    void setDenominator(int value);

    Fraction();
    Fraction(int num, int den);
    std::string toString();
};

class FractionTextProvider {
public:
    static std::tuple<int, std::vector<Fraction>> read(std::string filename);
};

class FractionToDecimalConverter {
private:
    NumberFormat _config;
public:
    FractionToDecimalConverter(NumberFormat config);
    FractionToDecimalConverter();
    void set_NumberFormat(NumberFormat config);
    std::string convert(Fraction f);
};

class FractionToLowMix {
public:
    std::string LowMix(Fraction frac);
};

class FractionToPercentageConverter {
private:
    NumberFormat _config;
public:
    FractionToPercentageConverter(NumberFormat config);
    FractionToPercentageConverter();
    std::string convert(Fraction f);
};

class Integer {
public:
    static int gcd(int a, int b);
};

int Fraction::getNumerator() {
    return _num;
}

int Fraction::getDenominator() {
    return _den;
}

void Fraction::setNumerator(int value) {
    _num = value;
}

void Fraction::setDenominator(int value) {
    _den = value;
}

Fraction::Fraction() {
    _num = 0;
    _den = 1;
}

Fraction::Fraction(int num, int den) {
    // Handle divided by zero
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    _num = num;
    _den = den;
}

std::string Fraction::toString() {
    std::stringstream builder;
    builder << _num << "/" << _den;
    return builder.str();
}

std::tuple<int, std::vector<Fraction>> FractionTextProvider::read(std::string filename) {
    const char SLASH = '/';
    std::vector<Fraction> fractionsData;
    std::ifstream getData(filename);
    if (!getData.is_open()) {
        throw std::runtime_error("Unable to open file.");
    }
    std::regex fractionPattern("-?\\d+\\/\\-?\\d+");
    std::string buffer = "";
    getline(getData, buffer);
    int numFraction = std::stoi(buffer);
    for (int i = 0; i < numFraction; i++) {
        getline(getData, buffer);
        if (std::regex_match(buffer, fractionPattern)) {
            int pos = buffer.find(SLASH);
            int num = std::stoi(buffer.substr(0, pos));
            int den = std::stoi(buffer.substr(pos + 1));
            Fraction temp(num, den);
            fractionsData.push_back(temp);
        }
    }
    getData.close();
    return std::make_tuple(numFraction, fractionsData);
}

FractionToDecimalConverter::FractionToDecimalConverter(NumberFormat config) {
    _config = config;
}

FractionToDecimalConverter::FractionToDecimalConverter() {}

void FractionToDecimalConverter::set_NumberFormat(NumberFormat config) {
    _config = config;
}

std::string FractionToDecimalConverter::convert(Fraction f) {
    int num = f.getNumerator();
    int den = f.getDenominator();
    double ans = static_cast<double>(num) / static_cast<double>(den);
    std::string thousand = _config.get_thousandSeparator();
    std::string dec = _config.get_decimalSeparator();
    int precision = _config.get_precision();
    std::stringstream builder;
    builder << std::fixed << std::setprecision(precision) << ans;
    std::string exchanger = builder.str();
    for (char& c : exchanger) {
        if (c == ',' && _config.get_decimalSeparator() != ",") {
            c = *(thousand.c_str());
        }
        if (c == '.' && _config.get_decimalSeparator() != ".") {
            c = *(dec.c_str());
        }
    }
    return exchanger;
}

std::string FractionToLowMix::LowMix(Fraction frac) {
    int num = frac.getNumerator();
    int den = frac.getDenominator();
    std::string result = "";
    if (abs(num) >= abs(den) && num % den == 0) {
        result = std::to_string(num / den);
        return result;
    }
    Integer a;
    int common = a.gcd(num, den);
    num = num / common;
    den = den / common;
    if (den < 0) {
        num = -num;
        den = -den;
    }
    std::stringstream builder;
    if (abs(num) >= den) {
        int whole = num / den;
        int remain = abs(num % den);
        if (remain)
            builder << whole << " " << remain << "/" << den;
        result = builder.str();
        return result;
    }
    builder << num << "/" << den;
    result = builder.str();
    return result;
}

FractionToPercentageConverter::FractionToPercentageConverter(NumberFormat config) {
    _config = config;
}

FractionToPercentageConverter::FractionToPercentageConverter() {}

std::string FractionToPercentageConverter::convert(Fraction f) {
    int num = f.getNumerator();
    int den = f.getDenominator();
    double ans = static_cast<double>(num) / static_cast<double>(den) * 100;
    int precision = _config.get_precision();
    std::stringstream builder;
    builder << std::fixed << std::setprecision(precision) << ans << "%";
    return builder.str();
}

int Integer::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    std::stringstream builder;
    std::string namefile = "input.txt";
    std::vector<std::string> nameConverter{ "Lowest term: ", "Decimal: ", "Percentage: " };
    builder << "Working with fraction arrays from text files\n\n";
    builder << "Reading data from " << namefile << ".\n";
    FractionTextProvider getData;
    NumberFormat formatd(".", ".", 2);
    NumberFormat formatp(",", ".", 0);
    FractionToDecimalConverter decConvert(formatd);
    FractionToPercentageConverter perConvert(formatp);
    FractionToLowMix LMConvert;
    try {
        auto [expectFractions, dataFractions] = getData.read(namefile);
        int numFractions = dataFractions.size();
        builder << "Expected to find " << expectFractions << " fractions.\n\n";
        if (numFractions == 0) {
            builder << "There's no fraction in file.\n";
        }
        else {
            builder << "Found " << numFractions << " fractions: ";
            for (int i = 0; i < numFractions; i++) {
                builder << dataFractions[i].toString();
                if (i < numFractions - 1) {
                    builder << ", ";
                }
            }

            builder << "\n" << nameConverter[0];
            for (int i = 0; i < numFractions; i++) {
                builder << LMConvert.LowMix(dataFractions[i]);
                if (i < numFractions - 1) {
                    builder << ", ";
                }
            }

            builder << "\n" << nameConverter[1];
            for (int i = 0; i < numFractions; i++) {
                builder << decConvert.convert(dataFractions[i]);
                if (i < numFractions - 1) {
                    builder << ", ";
                }
            }

            builder << "\n" << nameConverter[2];
            for (int i = 0; i < numFractions; i++) {
                builder << perConvert.convert(dataFractions[i]);
                if (i < numFractions - 1) {
                    builder << ", ";
                }
            }
        }
    }
    catch (const std::exception& e) {
        builder << "Error: " << e.what();
    }
    builder << "\n\nProgram is exiting. Press enter to quit...\n";
    std::cout << builder.str();
    return 0;
}