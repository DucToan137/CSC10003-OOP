#include <iostream>
#include "Fraction.h"
#include "FractionKeyboardProvider.h"
#include"FractionToDecimalConverter.h"
#include"FractionToPercentageConverter.h"

int main()
{
    std::cout << "Nhap xuat phan so\n\n";
    std::cout << "Nhap vao mot phan so.\n";

    FractionKeyboardProvider provider;
    Fraction a = provider.next();
    
    std::cout << "\n";
    std::cout << "Phan so vua nhap la: " << a.toString();

    std::cout << "\n";
    std::cout << "Dinh dang khac: " << a.Lowest_Mixed();
    
    // Hien thi dang thap phan
    //Fraction f(1000, 6);
    NumberFormat format1(",", ".", 3);
    FractionToDecimalConverter converter1(format1);
    std::string message1 = converter1.convert(a);
    std::cout << "\nHien thi phan so dang thap phan: ";
    std::cout << message1;

    // Hien thi dang phan tram
    //Fraction f(100, 6);
    NumberFormat format2(",", ".", 1);
    FractionToPercentageConverter converter2(format2);
    std::string message2 = converter2.convert(a);
    std::cout << "\nHien thi phan so dang phan tram: ";
    std::cout << message2; 

    return 0;
}