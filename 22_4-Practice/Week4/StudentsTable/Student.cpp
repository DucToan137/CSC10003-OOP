#include"Student.h"

std::string Student::getID() {
	return _id;
}

std::string Student::getFullname() {
	return _fullname;
}

std::string Student::getEmail() {
	return _email;
}

void Student::setID(std::string value) {
	_id = value;
}

void Student::setFullname(std::string value) {
	_fullname = value;
}

void Student::setEmail(std::string value) {
	_email = value;
}

Student::Student()
{
	_id = 1;
	_fullname = "Nguyen Van A";
	_email = "nva@gmail.com";
}

Student::Student(std::string id, std::string fullname, std::string email)
{
	_id = id;
	_fullname = fullname;
	_email = email;
}