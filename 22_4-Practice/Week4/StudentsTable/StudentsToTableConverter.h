#pragma once
#include"StudentProvider.h"

class StudentsToTableConverter {
private:
    std::vector<std::string> _headers;
    std::vector<int> _columnSizes;
public:
    StudentsToTableConverter();
    StudentsToTableConverter(std::vector<std::string> headers,
        std::vector<int> columnSizes);
    std::string convert(std::vector<Student> students);

private: // Inner class
    class StudentToRowConverter {
    private:
        std::vector<int> _columnSizes;
    public:
        StudentToRowConverter();
        StudentToRowConverter(std::vector<int> columnSizes);
        std::string convert(Student student);
    };
};
