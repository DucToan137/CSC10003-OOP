#pragma once
#include<string>

class Student {
public:
    std::string _id;
    std::string _fullname;
    std::string _email;
public:
    Student();
    Student(std::string id, std::string fullname, std::string email);
public:
    std::string getID();
    std::string getFullname();
    std::string getEmail();
    void setID(std::string val);
    void setFullname(std::string val);
    void setEmail(std::string val);

};