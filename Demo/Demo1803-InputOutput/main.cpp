#include <iostream>
#include <string>
#include <tuple>
#include <regex>
#include <sstream>
#include <map>
#include <format>
#include <exception>

#pragma region Sodier

// PHM Có chất lượng == Đáp ứng yêu cầu khách hàng trong
//  giới hạn thời gian & ngân sách cho phép
// Time & Budget

// Soldier.h
class Soldier {
private:
    int _hp;
    int _mana;
public:
    int hp();
    int mana();
    void setHp(int value);
    void setMana(int value);
public:
    Soldier();
    Soldier(int, int);
public:

};

// SOldier.cpp

int Soldier::hp() {
    return _hp;
}
int Soldier::mana() {
    return _mana;
}
void Soldier::setHp(int value) {
    _hp = value;
}
void Soldier::setMana(int value) {
    _mana = value;
}

Soldier::Soldier() {
    const int INTIAL_HP = 500;
    const int INTIAL_MANA = 100;
    _hp = INTIAL_HP;
    _mana = INTIAL_MANA;
}

Soldier::Soldier(int hp, int mana) {
    _hp = hp;
    _mana = mana;
}

#pragma endregion

#pragma region Fraction
class Fraction {
private: // Backup fields / Attributes
    int _num;
    int _den;
public:
    int numerator();
    int denominator();
    void setNumerator(int value);
    void setDenominator(int value);
public:
    Fraction();
    Fraction(int num, int den);
    std::string toString(); // Raw info
public:
    Fraction operator+(const Fraction& a);
};

Fraction Fraction::operator+(const Fraction& other) {
    int num = this->_num * other._den + this->_den * other._num;
    int den = this->_den * other._den;

    Fraction result(num, den);
    return result;
}

class FractionKeyboardProvider {
public:
    inline static const int OK = 0;
    inline static const int EMPTY_DATA = 1;
    inline static const int INVALID_FORMAT = 2;
    inline static const int INVALID_DOMAIN = 3;
public:
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    static std::tuple<int, Fraction> next();
};

#pragma region Fraction implementation
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

Fraction::Fraction() {
    _num = 0;
    _den = 1;
}

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        throw std::exception("DividedByZero");
        //throw DividedByZeroException;
    }

    this->_num = num;
    this->_den = den;
}

std::string Fraction::toString() {
    // std::string result = std::format("{}/{}", _num, _den);
    const std::string SEPARATOR = "/";
    std::stringstream builder;
    builder << _num << SEPARATOR << _den;

    std::string result = builder.str();
    return result;
}

#pragma endregion

std::tuple<int, Fraction> FractionKeyboardProvider::next() {
    std::string buffer;
    getline(std::cin, buffer);

    int errorCode = OK; // 0
    Fraction f;
    
    if (buffer.length() == 0) {
        errorCode = EMPTY_DATA;
        return std::make_tuple(errorCode, f);
    }

    std::regex fractionPattern("\\d+/\\d+");
    if (! std::regex_match(buffer, fractionPattern)) {
        errorCode = INVALID_FORMAT;
        return std::make_tuple(errorCode, f);
    }

    // "Left/Right"
    const char SEPARATOR = '/';
    std::istringstream reader(buffer);
    std::string left;
    getline(reader, left, SEPARATOR);

    std::string right;
    getline(reader, right);

    int num = stoi(left);
    int den = stoi(right);
    f.setNumerator(num);
    f.setDenominator(den);

    errorCode = OK;
    auto result = std::make_tuple(errorCode, f);
    return result;
}

#pragma endregion

// TODO: 03 Khai bao va cai dat lop Soldier
int main()
{
    std::map<int, std::string> vnDict;
    vnDict.insert({ FractionKeyboardProvider::EMPTY_DATA, "Du lieu nhap khong the de trong" });
    vnDict.insert({ FractionKeyboardProvider::INVALID_FORMAT, "Khong dung dinh dang phan so: Tu/Mau" });

    std::map<int, std::string> enDict;
    enDict.insert({ FractionKeyboardProvider::EMPTY_DATA, "Input data cannot be empty" });
    enDict.insert({ FractionKeyboardProvider::INVALID_FORMAT, "Invalid format: Numerator/Denominator" });
    
    // A Soldier that has Hit points and Mana, can attack and defend
    Fraction f1;
    
    int code;
    FractionKeyboardProvider provider;

    do {
        std::cout << "Please enter the first fraction.\n";
        std::tie(code, f1) = provider.next();

        if (code == FractionKeyboardProvider::OK) {
            break;
        }
        else {
            std::cout << "Error: " << enDict[code] << "\n";
            std::cout << "Please enter again.\n\n";
        }
    } while (true);
    
    std::cout << "Newly enter input fraction:"
        << f1.toString() << "\n";
    
    // 1. Đặc trưng C++
    // 2. Lỗi?
    // 3. Nhập lại?
    // 4. friend
    /*cin >> f1;
    cin >> f2;
    cin >> f3;*/

    Fraction temp(5, 0);


    Fraction f2;
    std::cout << "Enter second fraction:";
    std::tie(code, f2) = provider.next();

    Fraction f3 = f1 + f2;
    std::cout << std::format("{0} + {1} = {2}",
        f1.toString(), f2.toString(), f3.toString());
}
