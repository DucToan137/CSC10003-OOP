#include"StudentProvider.h"
#include<iostream>
#include<string>
#include<fstream>

std::vector<Student> StudentProvider::getAll() {
   /* return {
        Student("001", "Nguyen Van Minh", "nvminh@gmail.com"),
        Student("002", "Cao Ha Thang", "chthang@gmail.com"),
        Student("003", "Tran Duc Tri", "tdtri@gmail.com")
    };*/

	std::vector<Student> a;

	std::ifstream input;
	input.open("student.inp", std::ios::in);

	if (input.is_open())
	{
		int n = 0;
		std::string line;
		std::string id;
		std::string fullname;
		std::string email;
		input >> n;
		std::getline(input, line);
		std::cout << line;

		for (int i = 0; i < n; i++)
		{

			std::getline(input, id);
			std::getline(input, fullname);
			std::getline(input, email);

			Student b;
			b.setID(id);
			b.setFullname(fullname);
			b.setEmail(email);

			a.push_back(b);

		}
	}
	else
	{
		std::cout << "Khong the mo file\n";
	}
	
	return a;

}