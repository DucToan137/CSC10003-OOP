#pragma once
#include"Student.h"
#include<vector>

class StudentProvider {
public:
    static std::vector<Student> getAll();
};