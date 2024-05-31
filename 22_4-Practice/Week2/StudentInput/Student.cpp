#include<iostream>
#include"Student.h"
#include"../DateInput/Date.h"



std::string Student::Id() {
	return _id;
}

std::string Student::Fullname() {
	return _fullname;
}


std::string Student::Address() {
	return _address;
}

std::string Student::Email() {
	return _email;
}

Date Student::DoB() {
	return _dob;
}

void Student::setID(std::string& value) {
	_id = value;
}

void Student::setFullname(std::string& value) {
	_fullname = value;
}

void Student::setAddress(std::string& value) {
	_address = value;
}

void Student::setEmail(std::string& value) {
	_email = value;
}

void Student::setDoB(Date value) {
	_dob = value;
}

Student::Student() {}

void Student::input() {
	std::cout << "Nhap Id: ";
	std::getline(std::cin, _id);

	std::cout << "Nhap ho ten: ";
	std::getline(std::cin, _fullname);

	std::cout << "Nhap dia chi: ";
	std::getline(std::cin, _address);

	std::cout << "Nhap email: ";
	std::getline(std::cin, _email);

	std::cout << "Nhap ngay sinh \n";
	_dob.input();
}

void Student::output() {
	std::cout << "ID: " << _id << std::endl;
	std::cout << "Fullname: " << _fullname << std::endl;
	std::cout << "Address: " << _address << std::endl;
	std::cout << "Email: " << _email << std::endl;
	std::cout << "DOB: ";
	_dob.output();
}