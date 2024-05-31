#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

class Employee {
private:
	std::string _fullName;
	std::string _employeeID;
	int _age;
	std::string _department;
	float _salary;
public:
	Employee();
	Employee(std::string name, std::string id, int age, std::string department, float salary);
	void displayInfor();
public:
	std::string getFullName();
	void setFullName(std::string name);

	std::string getEmployeeID();
	void setEmployeeID(std::string id);

	int getAge();
	void setAge(int age);

	std::string getDepartment();
	void setDepartment(std::string department);

	float getSalary();
	void setSalary(float salary);
};

class EmployeeManager {
private:
	std::vector<Employee> _employess;
public:
	void addEmployee(const Employee& employee);
	void removeEmployee(const std::string& employeeID);
	void displayAllEmployees();
	Employee findEmployeeByID(const std::string& employeeID);
};

Employee::Employee() {
	_fullName = "Nguyen Van A";
	_employeeID = "A01";
	_age = 27;
	_department = "Acting";
	_salary = 10000;
}

Employee::Employee(std::string name, std::string id, int age, std::string department, float salary)
{
	_fullName = name;
	_employeeID = id;
	_age = age;
	_department = department;
	_salary = salary;
}

void Employee::displayInfor()
{
	std::cout << "Name: " << _fullName << "\n";
	std::cout << "Employee ID: " << _employeeID << "\n";
	std::cout << "Age: " << _age << "\n";
	std::cout << "Department: " << _department << "\n";
	std::cout << "Salary: " << std::fixed << std::setprecision(2) << _salary << "\n";
}

std::string Employee::getFullName()
{
	return _fullName;
}

void Employee::setFullName(std::string name)
{
	_fullName = name;
}

std::string Employee::getEmployeeID()
{
	return _employeeID;
}

void Employee::setEmployeeID(std::string id)
{
	_employeeID = id;
}

int  Employee::getAge()
{
	return _age;
}

void Employee::setAge(int age)
{
	_age = age;
}

std::string Employee::getDepartment()
{
	return _department;
}

void Employee::setDepartment(std::string department)
{
	_department = department;
}

float Employee::getSalary()
{
	return _salary;
}

void Employee::setSalary(float salary)
{
	_salary = salary;
}

void EmployeeManager::addEmployee(const Employee& employee)
{
	_employess.push_back(employee);
}

void EmployeeManager::removeEmployee(const std::string& employeeID)
{
	int pos = -1;
	for (int i = 0; i < _employess.size(); i++)
	{
		if (_employess[i].getEmployeeID() == employeeID)
		{
			pos = i;
			_employess.erase(_employess.begin() + i);
		}
	}
}

void EmployeeManager::displayAllEmployees()
{
	for (int i = 0; i < _employess.size(); i++)
	{
		if (i == 0)
		{
			_employess[i].displayInfor();
		}
		else
		{
			std::cout << "==============================\n";
			_employess[i].displayInfor();
		}
	}
}


Employee EmployeeManager::findEmployeeByID(const std::string& employeeID)
{
	for (int i = 0; i < _employess.size(); i++)
	{
		if (_employess[i].getEmployeeID() == employeeID)
			return _employess[i];
	}
	Employee a;
	return a;
}

int main() {

	return 0;
}