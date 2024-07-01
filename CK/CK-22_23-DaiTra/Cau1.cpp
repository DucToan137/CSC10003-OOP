#include <iostream>
#include <string>
using namespace std;

class Date;
class Mobile;

class Date
{
private:
    int _day;
    int _month;
    int _year;

public:
    friend istream &operator>>(istream &, Date &);
    friend ostream &operator<<(ostream &, Date &);
    bool operator>(Date &b);
};

istream &operator>>(istream &is, Date &date)
{
    cout << "Day: ";
    is >> date._day;
    cout << "Month: ";
    is >> date._month;
    cout << "Year: ";
    is >> date._year;
    return is;
}

ostream &operator<<(ostream &os, Date &date)
{
    os << date._day << "/" << date._month << "/" << date._year;
    return os;
}

bool Date::operator>(Date &b)
{
    if (this->_year > b._year)
        return true;
    else if (this->_year == b._year)
    {
        if (this->_month > b._month)
            return true;
        else if (this->_month == b._month)
        {
            if (this->_day > b._day)
                return true;
        }
    }
    return false;
}

//----------Lop Mobile----------------
class Mobile
{
private:
    string _code;
    string _name;
    string _brand;
    Date _manufacturingDate;

public:
    friend istream &operator>>(istream &is, Mobile &mobile);
    friend ostream &operator<<(ostream &os, Mobile &mobile);
    bool operator>(Mobile &b);
};

istream &operator>>(istream &is, Mobile &mobile)
{
    cout << "Code: ";
    is >> mobile._code;
    cout << "Name: ";
    is >> mobile._name;
    cout << "Brand: ";
    is >> mobile._brand;
    cout << "-- Input date --\n";
    is >> mobile._manufacturingDate;
    return is;
}

ostream &operator<<(ostream &os, Mobile &mobile)
{
    os << "Code: " << mobile._code << endl;
    os << "Name: " << mobile._name << endl;
    os << "Brand: " << mobile._brand << endl;
    os << "Manufacturing date: ";
    os << mobile._manufacturingDate << endl;
    return os;
}

bool Mobile::operator>(Mobile &b)
{
    if (this->_manufacturingDate > b._manufacturingDate)
        return true;
    return false;
}

int main()
{
    Mobile a, b;

    cout << "Mobile a:  \n";
    cin >> a;
    cout << "Mobile b:  \n";
    cin >> b;

    if(a > b)
        cout << "Ngay san xuat a lon hon b" << endl;
    else
        cout << "Ngay san xuat b lon hon a" << endl;

    return 0;
}