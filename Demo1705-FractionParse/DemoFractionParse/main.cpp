#include<iostream>
#include<string>
#include<tuple>
#include<sstream>
#include<regex>
#include<vector>
#include<memory>
#include<fstream>

using namespace std;

class Integer {
public:
	/// <summary>
	/// Chuyển chuỗi sang số nguyên
	/// Error code:
	/// 0: Thành công
	/// 1: Lỗi chuỗi không đúng định dạng
	/// 2: Không có giá trị đầu vào
	/// 3: Miền giá trị không đúng
	/// </summary>
	/// <param name="val">Chuỗi</param>
	/// <returns></returns>
	static tuple<bool, int, string, int> parse(string val) 
	{
		bool successfull = true;
		int errorCode = 0;
		string message = "";
		int number = 0;

		if (val.size() == 0)
		{
			errorCode = 3;
			message = "Input string cannot be empty";
		}

		try {
			number= stoi(val);
		} 
		catch (exception ex) {
			successfull = false;
			errorCode = 1;
			message = ex.what();
		}

		auto result = make_tuple(successfull, errorCode, message, number);

		return result; 
	}


	// Ưu: Luồng xử lí không bị bẽ gãy đột ngột khi có exception
	// Nhược: 
	//	1. Không thể biết được lỗi xảy ra ở đâu
	//	2. Không có cách thông báo cho người dùng
	// 	3. Giá trị mặc định đội khi không nên có
	static bool tryParse(string val, int& result)
	{
		bool succesfull = false;

		try
		{
			result = stoi(val);
			succesfull = true;
		}
		catch (exception ex)
		{
			succesfull = false;
		}
		return succesfull;
	}
};


class StringHelper {
public:
	static vector<string> split(string line, string separator)
	{
		vector<string> result;

		int startPostion = 0;
		size_t foundPostion = line.find(separator, startPostion);

		while(foundPostion != string::npos)
		{
			string token = line.substr(startPostion, foundPostion - startPostion);
			result.push_back(token);

			startPostion = foundPostion + separator.size();
			foundPostion = line.find(separator, startPostion);

		}

		string token = line.substr(startPostion, line.size() - startPostion);
		result.push_back(token);

		return result;
	}
};


class Fraction { // Data transfer object
private:
	int _num;
	int _den;
public:
	int Numerator() { return _num; }
	void setNumerator(int value) { _num = value; }
	int Denominator() { return _den; }
	void setDenominator(int value) { _den = value; }
public:
	Fraction() {
		_num = 0;
		_den = 0;
	}
	Fraction(int num, int den) {
		_num = num;
		_den = den;
	}
	~Fraction()
	{
		cout << "Fraction destructor\n";
	}
public:
	
	string toString() {
		stringstream ss;
		ss << _num << "/" << _den;
		string result = ss.str();
		return result;
	}

	// Không nên viết như thế này
	void input() {
		cout << "Nhap tu: ";
		cin>> _num;
		cout<<"Nhap mau: ";
		cin >> _den;
	}


	// Không nên
	// 1.Truy cập đến giao diện trong lớp DTO (vi phạm nguyên tắc 3 lớp)
	// 2.friend phá vỡ nguyên tắc hướng đối tượng mà mình học chỉ để phục vụ cú pháp ngôn ngữ
	friend istream& operator>>(istream& is, Fraction& f) {
		cout << "Nhap tu: ";
		is >> f._num;
		cout << "Nhap mau: ";
		is >> f._den;
		return is;
	}

	/// <summary>
	/// Chuyển chuỗi sang phân số
	/// </summary>
	/// <param name="line">Phan6 số dưới định dạng Tu/Mau</param>
	/// <returns>
	/// 0: Thành công
	/// 1: Không có dữ liệu(chuỗi rỗng)
	/// 2: Chuỗi không đúng định dạng
	/// 3: Không đúng miền giá trị(mẫu = 0)
	/// </returns>
	static tuple<bool, int, string, shared_ptr<Fraction>> parse(string line) {
		bool successfull = false;
		int errorCode = 0;
		string message = "";
		shared_ptr<Fraction> f = nullptr;

		if (line.size() == 0)
		{
			successfull = false;
			errorCode = 1;
			message = "Input string cannot be empty";
		}
		else
		{
			string pattern = "\\d+\\/\\d+";
			bool isMatched = regex_match(line, regex(pattern));

			if (!isMatched)
			{
				//successfull = false;
				errorCode = 2;
				message = "Invalid fraction format";
			}
			else
			{
				// Tách chuỗi thành 2 phần dựa vào dấu /
				 const string separator = "/";
				 auto tokens = StringHelper::split(line, separator);
				int num = stoi(tokens[0]);
				int den = stoi(tokens[1]);

				if (den == 0)
				{
					//successfull = false;
					errorCode = 3;
					message = "Denominator cannot be 0";
				}
				else
				{
					successfull = true;
					// f = new Fraction(num, den);
					f = make_shared<Fraction>(num, den);
				}
			}
		}


		auto result = make_tuple(successfull, errorCode, message, f);
		return result;
	}
	
	
};

int main() {

	// Thao tác với tuple
	/*auto point = make_tuple(1, 2);
	get<0>(point) = 99;

	cout <<get<0>(point) << ",  " << get<1>(point) << "\n";

	int x;
	int y;
	tie(x, y) = point;
	x = 101;

	cout << x << ", " << y << "\n";
	cout << get<0>(point) << ",  " << get<1>(point) << "\n";*/

	// 1.Chuyển chuỗi sang số nguyên

	/*string val = "hello";
	bool successfull = false;
	do {

		cout << "Please enter an integer: ";
		string line = "";

		int number = 0;
		getline(cin, line);

		successfull = Integer::tryParse(line, number);
		if (successfull)
		{
			int result = number + 2;
			cout << result << "\n";
		}
		else
		{
			cout << "Invalid input. Please try again.\n";
		}
	} while (!successfull);*/

	bool successful = false;
	int errorCode = 0;
	string message = "";
	int number = 0;
	// Con trỏ thông minh
	shared_ptr<Fraction> f; // reference counting: đếm tham chiếu

	
	/*do {

		cout << "Please enter an integer: ";
		string line = "";
		
		getline(cin, line);
		int number = 0;

		tie(successful, errorCode, message, number) = Integer::parse(line);

		if (successful)
		{
			int result = number + 2;
			cout << result << "\n";
		}
		else
		{
			cout << "Cannot converte to integer. Reason: " << message << "\n";
			cout << "Please try again.\n";
		}
	} while (!successful);*/


	/*do {
		cout << "Please enter a fraction: ";
		string line = "";
		getline(cin, line);

		tie(successful, errorCode, message, f) = Fraction::parse(line);

		if (successful)
		{
			cout << f->toString() << "\n";
		}
		else
		{
			cout << "Cannot converte to fraction. Reason: " << message << "\n";
			cout << "Please try again.\n";
		}
	} while (!successful);
	*/


	const string filepath = "data.txt";
	ifstream reader;
	reader.open(filepath);

	vector<shared_ptr<Fraction>> a;


	while (!reader.eof())
	{
		string line;
		getline(reader, line);

		tie(successful, errorCode, message, f) = Fraction::parse(line);

		a.push_back(f);

		
	}
	
	ofstream writer;
	writer.open("output.txt");

	for (int i = 0; i < a.size(); i++)
	{
		writer << a[i]->toString() << "\n";
	}
	//cout << "\n";




	
	//delete f; // không dùng con trỏ thông minh phải hủy thủ công
	return 0;
}