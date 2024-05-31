#include<iostream>
#include<vector>
#include<iomanip>
#include<string>

using namespace std;

class Student {
private:
	std::string _fullName;
	std::string _studentID;
	int _age;
	std::string _addresss;
	float _gpa;
public:
	Student();
	Student(std::string name, std::string id, int age, std::string address, float gpa);
	void displayInfo();
public:
	std::string getFullName();
	void setFullName(std::string name);
	std::string getStudentID();
	void setStudentID(std::string id);
	int getAge();
	void setAge(int age);
	std::string getAddress();
	void setAddress(std::string address);
	float getGPA();
	void setGPA(float gpa);
};


Student::Student() {}

Student::Student(std::string name, std::string id, int age, std::string address, float gpa)
{
	_fullName = name;
	_studentID = id;
	_age = age;
	_addresss = address;
	_gpa = gpa;
}

void Student::displayInfo()
{
	std::cout << "Name: " << getFullName() << "\n";
	std::cout << "Student ID: " << getStudentID() << "\n";
	std::cout << "Age: " << getAge() << "\n";
	std::cout << "Address: " << getAddress() << "\n";
	std::cout << "GPA: " << fixed << setprecision(1) << getGPA() << "\n";
}

std::string Student::getFullName()
{
	return _fullName;
}

void Student::setFullName(std::string name)
{
	_fullName = name;
}

std::string Student::getStudentID()
{
	return _studentID;
}

void Student::setStudentID(std::string id)
{
	_studentID = id;
}

int Student::getAge()
{
	return _age;
}
void Student::setAge(int age)
{
	_age = age;
}

std::string Student::getAddress()
{
	return _addresss;
}

void Student::setAddress(std::string address)
{
	_addresss = address;
}

float Student::getGPA()
{
	return _gpa;
}

void Student::setGPA(float gpa)
{
	_gpa = gpa;
}

class StudentManager {
private:
	std::vector<Student> _students;
public:
	void addStudent(const Student& student);
	void removeStudent(const std::string& studentID);
	void displayAllStudents();
	Student findStudentByID(const std::string& studentID);
};


void StudentManager::addStudent(const Student& student)
{
	_students.push_back(student);
}

void StudentManager::removeStudent(const std::string& studentID)
{
	int pos = -1;
	for (int i = 0; i < _students.size(); i++)
	{
		if (_students[i].getStudentID() == studentID)
		{
			pos = i;
			_students.erase(_students.begin() + i);
		}
	}
}

void StudentManager::displayAllStudents()
{
	for (int i = 0; i < _students.size(); i++)
	{
		if (i == 0)
		{
			_students[i].displayInfo();
		}
		else
		{
			std::cout << "--------------------\n";
			_students[i].displayInfo();
		}
	}
}

Student StudentManager::findStudentByID(const std::string& studentID)
{
	for (int i = 0; i < _students.size(); i++)
	{
		if (_students[i].getStudentID() == studentID)
			return _students[i];
	}
	Student a;
	return a;
}

int main()
{
	return 0;
}