#pragma once
#include"../DateInput/Date.h"
#include<string>

class Student {
private:
	std::string _id;
	std::string _fullname;
	std::string _address;
	std::string _email;
	Date _dob;
public:
	std::string Id();
	std::string Fullname();
	std::string Address();
	std::string Email();
	Date DoB();
	void setID(std::string& value);
	void setFullname(std::string& value);
	void setAddress(std::string& value);
	void setEmail(std::string& value);
	void setDoB(Date value);
public:
	Student();
public:
	void input();
	void output();
};