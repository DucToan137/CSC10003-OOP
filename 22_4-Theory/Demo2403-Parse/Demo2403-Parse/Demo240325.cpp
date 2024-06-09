
#include <iostream>
#include <string>
#include <format>
#include <exception>
#include <tuple>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>

#pragma region Fraction.h
class Fraction {
public:
    inline static int instanceCount = 0;
private:
    int _num;
    int _den;
public:
    Fraction();
    Fraction(int num, int den);
    int numerator();
    int denominator();
    void setNumerator(int value);
    void setDenominator(int value);
public:
    std::string toString();
public:
    static Fraction parse(std::string info);
    // Do not try to use these functions
    // static std::tuple<bool, Fraction> create(int num, int den);
    // static bool tryCreate(int num, int den, Fraction& f);
};
#pragma endregion

#pragma region Fraction.cpp

Fraction::Fraction() {
    _num = 0;
    _den = 1;
    instanceCount++;
}

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        throw std::exception("Divided by zero exception");
    }

    _num = num;
    _den = den;
    instanceCount++;
}

//std::tuple<bool, Fraction> Fraction::create(int num, int den) {
//    if (den == 0) {
//        Fraction result;
//        instanceCount--;
//        return std::make_tuple(false, result);
//    }
//
//    Fraction result;
//    result.setNumerator(num);
//    result.setDenominator(den);
//    
//    return std::make_tuple(true, result);
//}

int Fraction::numerator() {
    return _num;
}

int Fraction::denominator() {
    return _den;
}

void Fraction::setNumerator(int value) {
    _num = value;
}

void Fraction::setDenominator(int value) {
    _den = value;
}

std::string Fraction::toString() {
    return std::format("{}/{}", _num, _den);
}

Fraction Fraction::parse(std::string info) {
    if (info.length() == 0) {
        throw std::exception("Empty input value");
    }

    std::regex fractionPattern("\\d+/\\d+");
    if (! std::regex_match(info, fractionPattern)) {
        throw std::exception("Invalid fraction format");
    }

    const char SLASH = '/';
    std::istringstream reader(info);

    std::string left;
    getline(reader, left, SLASH);
    
    std::string right;
    getline(reader, right);

    int num = stoi(left);
    int den = stoi(right);

    if (den == 0) {
        throw std::exception("Divided by zero");
    }

    Fraction result(num, den);
    return result;
}

//bool Fraction::tryCreate(int num, int den, Fraction& f) {
//    if (den == 0) {
//        return false;
//    }
//
//    f.setNumerator(num);
//    f.setDenominator(den);
//    instanceCount++;
//}

#pragma endregion

#pragma region Random Integer
class RandomInteger {
public:
    RandomInteger();
public:
    int next();
    int next(int ceiling);
    int next(int min, int max);
};

RandomInteger::RandomInteger() {
    std::cout << "RandomInteger constructor\n";
    srand(time(NULL));
}

int RandomInteger::next() { return rand(); }
int RandomInteger::next(int ceiling) {
    return rand() % ceiling;
}
int RandomInteger::next(int min, int max) {
    return rand() % (max - min + 1) + min;
}
#pragma endregion

#pragma region Dice.h
class Dice {
private:
    inline static RandomInteger _rng;
    int _facesCount;
public:
    Dice();
    Dice(int faces);
public:
    int roll();
};
#pragma endregion

#pragma region Dice.cpp
Dice::Dice() {
    _facesCount = 6;
}

Dice::Dice(int faces) {
    _facesCount = faces;
}

// 6=> 1-> 6
int Dice::roll() {
    int value = _rng.next(_facesCount) + 1;
    return value;
}
#pragma endregion

class FractionTextProvider {
public:
    static std::tuple<int, std::vector<Fraction>> read(std::string input);
};

std::tuple<int, std::vector<Fraction>> FractionTextProvider::read(std::string input) {
    std::vector <Fraction> fractions;
    std::ifstream reader;
    reader.open(input);

    if (!reader.good()) {
        throw std::exception("File not found");
    }

    std::string buffer;
    getline(reader, buffer);

    std::regex numberPattern("\\d+");
    if (!std::regex_match(buffer, numberPattern)) {
        throw std::exception("Not a number exception");
    }

    int count = stoi(buffer);
    std::cout << count << "\n";

    for (int i = 1; i <= count; i++) {
        std::string line; // temp
        getline(reader, line);

        try
        {
            Fraction f = Fraction::parse(line);
            fractions.push_back(f);
        }
        catch (const std::exception&)
        {
            // eat exception
        }
    }

    reader.close();
    return make_tuple(count, fractions);
}

int main()
{
    //Fraction a;

    //try
    //{
    //    Fraction b(10, 0);
    //    std::cout << b.toString();
    //}
    //catch (const std::exception& ex)
    //{
    //    // eat exception idiom
    //    // fail silently

    //    /*std::cout << "Cannot create Fraction. Reason:" 
    //        << ex.what();*/
    //    // return 0;
    //}

    //std::cout << std::format("Created {} fraction(s) \n",
    //    Fraction::instanceCount);

    //try
    //{
    //    Fraction c = Fraction(10, 11);
    //}
    //catch (const std::exception& ex)
    //{
    //    /*std::cout << "Cannot create Fraction. Reason:"
    //        << ex.what();
    //    return 0;*/
    //}

    //std::cout << std::format("Created {} fraction(s) \n",
    //    Fraction::instanceCount);

    //=====================================
    // 1. Phát sinh số nguyên n ngẫu nhiên trong đoạn [5, 20]
    // 2. Sinh ra n số nguyên, mỗi số có giá trị từ [30, 70]

    // Tên biến không nên viết tắt
    // Thuật ngữ thông dụng, có thể viết tắt
    //const int LOWER = 5;
    //const int UPPER = 20;
    //RandomInteger generator; // random number generator // dob // tbd // gcd
    //int n = generator.next(LOWER, UPPER);

    //const int LEFT = 30;
    //const int RIGHT = 70;
    //std::vector<int> numbers;
    //for (int i = 0; i < n; i++) {
    //    int number = generator.next(LEFT, RIGHT);
    //    numbers.push_back(number);
    //}

    // ========================================
    /*class RandomInteger {
    public:
        RandomInteger();
    public:
        int next();
        int next(int ceiling);
        int next(int min, int max);
    };*/

    /*Dice dice1(20);
    Dice dice2(12);
    Dice dice3(6);

    int count = 10;
    for (int i = 1; i <= count; i++) {
        int value1 = dice1.roll();
        int value2 = dice2.roll();
        int value3 = dice3.roll();
        std::cout << std::format("{} - {} - {} \n",
            value1, value2, value3);
    }*/

    FractionTextProvider reader;
    std::string input = "data.txt";
    try
    {
        auto [count, fractions] = reader.read(input);

        std::cout << std::format(
            "Found {}/{} fractions from the input file\n",
            fractions.size(), count
        );

        for (int i = 0; i < fractions.size(); i++) {
            std::cout << fractions[i].toString() << " ";
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << std::format(
            "Cannot read fraction from {}. Reason: {}",
            input, ex.what());
    }
}
