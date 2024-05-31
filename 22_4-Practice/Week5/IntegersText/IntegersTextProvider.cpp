#include"IntegersTextProvider.h"


std::vector<int> IntegersTextProvider::read(std::string filename)
{
	std::vector<int> result;

	std::ifstream input;
	input.open(filename, std::ios::in);

	if (!input.good())
	{
		std::cout << "Mo file that bai\n";
	}

	std::string line;
	getline(input, line);

	int n = stoi(line);

	while (!input.eof())
	{
		std::getline(input, line);
		int num = std::stoi(line);
		result.push_back(num);
	}
	return result;
}

void IntegersTextProvider::DinhDangXuat(std::vector<int> a, std::string config)
{
	if (config == "")
	{
		std::cout << "Found " << a.size() << config << " numbers: ";
	}
	else
	{
		std::cout << "Found " << a.size() << " " << config << " numbers: ";
	}
	if (a.size() == 0)
	{
		std::cout << "\n";
		return;
	}
	std::cout << a[0];
	for (int i = 1; i < a.size(); i++)
	{
		std::cout << ", " << a[i];
	}
	std::cout << "\n";

}

void IntegersTextProvider::Xuat(std::vector<int> a)
{
	if (a.empty())
	{
		return;
	}

	std::vector<int> Chan;
	std::vector<int> Le;
	std::vector<int> DoiXung;
	std::vector<int> NguyenTo;
	std::vector<int> ChinhPhuong;
	std::vector<int> HoanHao;

	int min = a[0];
	int max = a[0];
	int tong = 0;
	double avg = 0;

	for (int i : a)
	{
		num.setNum(i);
		if (i < min)
		{
			min = i;
		}
		if (i > max)
		{
			max = i;
		}
		tong += i;
		// so chan, le
		if (num.OddEven() == 1)
		{
			Le.push_back(i);
		}
		else
		{
			Chan.push_back(i);
		}

		// so doi xung
		if (num.PalindromicNumber() == 1)
		{
			DoiXung.push_back(i);
		}
		
		// so nguyen to
		if (num.PrimeNumber() == 1)
		{
			NguyenTo.push_back(i);
		}

		// so chinh phuong
		if (num.SquareNumber() == 1)
		{
			ChinhPhuong.push_back(i);
		}

		// so hoan hao
		if (num.PerfectNumber() == 1)
		{
			HoanHao.push_back(i);
		}
	}

	


	avg = (double)tong / a.size();


	DinhDangXuat(a, "");
	DinhDangXuat(Le, "odd");
	DinhDangXuat(Chan, "even");
	DinhDangXuat(DoiXung,"palindromic");
	DinhDangXuat(NguyenTo, "prime");
	DinhDangXuat(ChinhPhuong, "square");
	DinhDangXuat(HoanHao, "perfect");
	
	std::cout << "Minimum value: " << min << "\n";
	std::cout << "Maximum value: " << max << "\n";
	std::cout << "Average value: " << avg << "\n";
	std::cout << "Sum of all numbers: " << tong << "\n";
}