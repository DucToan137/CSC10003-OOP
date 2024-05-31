#include"StudentsToTableConverter.h"
#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>
using std::setw;
using std::right;
using std::left;

StudentsToTableConverter::StudentsToTableConverter(){}

StudentsToTableConverter::StudentsToTableConverter(std::vector<std::string> headers, std::vector<int> columnSizes)
{
    _headers = headers;
    _columnSizes = columnSizes;

}
class StudentToRowConverter;

StudentsToTableConverter::StudentToRowConverter::StudentToRowConverter(){}

StudentsToTableConverter::StudentToRowConverter::StudentToRowConverter(std::vector<int> columnSizes)
{
    _columnSizes = columnSizes;
}

std::string StudentsToTableConverter::StudentToRowConverter::convert(Student student)
{
    std::stringstream builder;
    std::string result = "";
    builder << "|" << setw(_columnSizes[0]) << right << student.getID() << "|"
        << setw(_columnSizes[1]) << right << student.getFullname() << "|"
        << setw(_columnSizes[2]) << right << student.getEmail() << "|";

    result = builder.str();

    return result;
}

std::string StudentsToTableConverter::convert(std::vector<Student> students)
{
    std::stringstream builder;
    std::string result = "";

    //builder << "|";
   
    for (int i = 0; i < _columnSizes.size(); i++)
    {
        builder << "|" << setw(_columnSizes[i]) << right << _headers[i];
    }
    builder << "|\n";
 
    result = builder.str();
    for (int i = 0; i < result.size() - 1; i++)
    {
        builder << "-";
    }
    builder << "\n";


   std::string tmp = "";
   std::vector<int> vt;
   for (int i = 1; i < _columnSizes.size(); i++)
   {
       vt.push_back(_columnSizes[i]);
   }

   for (int i = 0; i < students.size(); i++)
   {


       StudentToRowConverter rowConverter(vt);

       std::string tmp = rowConverter.convert(students[i]);

       builder << "|" << setw(_columnSizes[0]) << right << i + 1 << tmp;
       builder << "\n";
   }

    result = builder.str();
    return result;
}