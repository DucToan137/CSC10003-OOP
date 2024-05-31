#include<iostream>
#include<vector>
#include"StudentsToTableConverter.h"
#include"StudentProvider.h"
#include"Student.h"

int main() {
    auto students = StudentProvider::getAll();

    std::vector<std::string> headers = { "SoTT", "Ma SV", "Ho ten", "mail" };
    std::vector<int> columnSizes = { 8, 11, 21, 22 };
    StudentsToTableConverter table(headers, columnSizes);

    auto info = table.convert(students);
    std::cout << info;


    
    return 0;
}