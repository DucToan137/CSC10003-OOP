#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<iomanip>
#include<chrono>
#include<ctime>
#include<format>
#include<fstream>
#include<conio.h>

#pragma warning(disable : 4996)
using namespace std;

// 1 Getting an integer till death - DeathLoop
void deathLoop()
{
	string s = "";
	do {
		getline(cin, s);
		if (s.empty())
		{
			cout << "The input value is empty\n";
			continue;
		}
		bool flag = true;
		for (char c : s)
		{
			if (!isdigit(c))
			{
				cout << "The input is not in the correct format for an integer (all digits)\n";
				flag = false;
				break;
			}
		}
	
		if (!flag)
		{
			continue;
		}
		int d = stoi(s);
		if (d < 1 || d>10)
		{
			cout << "The value is not in the correct domain\n";
			continue;
		}
	} while (true);
}

// 2 Entering password too many times - WrongPassword
void wrongPassword(string s)
{
	string password = "abcd";
	int times = 3;
	while (times>0)
	{
		cout << "Password: ";
		getline(cin, s);
		if (s == password)
		{
			cout << "Password is correct";
			break;
		}
		else
		{
			times--;
			cout << "Times: " << times << endl;
		}
	}
	cout << "Wrong password 3 times";
}

// 3 VN and Dollar currency display - CurrencyDisplay
string xuliChuoi(string s)
{
	string tmp = s;
	tmp = tmp.substr(2, tmp.length() - 4);
	return tmp;
}

void CurrencyDisplay()
{
	string vnd = "";
	string tigia = "";
	cout << "Nhap so tien: ";
	getline(cin, vnd);
	cout << "Nhap ty gia: ";
	getline(cin, tigia);
	vnd = xuliChuoi(vnd);
	tigia = xuliChuoi(tigia);
	//cout << vnd << " " << tigia;
	double result = (double)stoi(vnd) / stoi(tigia);
	int pos = vnd.length() - 3;
	while (pos > 0) {
		vnd.insert(pos, ".");
		pos -= 3;
	}
	cout << vnd << " d = $ " << result << endl;
}

// 4 Random numbers generator - RandomIntegers
bool checkNguyenTo(int n)
{
	int dem = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			dem++;
		}
	}
	if (dem == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void randomIntegers()
{
	srand(time(0));
	int left = 10;
	int right = 20;
	int n = rand() % (right - left + 1) + left;
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		int b = rand() % 100;
		a.push_back(b);
	}
	cout << "Tat ca cac so: ";
	for (int x : a)
	{
		cout << x <<" ";
	}
	int demC = 0;
	int demL = 0;

	for (int x : a)
	{
		if (x % 2 == 0)
		{
			demC++;
		}
		else
		{
			demL++;
		}
	}
	cout << "\nSo so chan: " << demC << endl;
	cout << "So so le: " << demL << endl;
	cout << "Tat ca so nguyen to: ";
	for (int x : a)
	{
		if (checkNguyenTo(x))
			cout << x << " ";
	}
}

// 5 Current date and next date - NextDay
int maxDayofMonth(int month, int year)
{
	if (month == 2)
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
	else
	{
		return 31;
	}
}

void NextDay()
{
	string a = "";
	time_t tgian = time(nullptr);
	tm* localTime = localtime(&tgian);

	int day = localTime->tm_mday;
	int month = localTime->tm_mon + 1;
	int year = localTime->tm_year + 1900;

	//string day = to_string(localTime->tm_mday);
	//string month = to_string(localTime->tm_mon + 1);
	//string year = to_string(localTime->tm_year + 1900);
	/*int day = 28;
	int month = 2;
	int year = 2005;*/

	cout << "Dinh dang dd/MM/yyy: ";
	cout << setw(2) << setfill('0') << day << "/" << setw(2) << setfill('0') << month << "/" << year << endl;
	cout << "Dinh dang MM/dd/yy: ";
	cout << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << "/" << year % 100 << endl;

	if (month == 2)
	{
		day++;
		if (day > maxDayofMonth(month, year))
		{
			day = 1;
			month++;
		}
	}
	else
	{
		day++;
		if (day > maxDayofMonth(month, year))
		{
			day = 1;
			month++;
			if (month > 12)
			{
				month = 1;
				year++;
			}
		}
	}
	cout << "Ngay ke tiep dinh dang dd/MM/yyyy: ";
	cout << setw(2) << setfill('0') << day << "/" << setw(2) << setfill('0') << month << "/" << year << endl;

	
	cout << "Ngay ke tiep dinh dang MM/dd/yy: ";
	cout << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << "/" << year % 100 << endl;
}

// 6 Automatically logger - Logger
void Logger(const string& message) {
	// Lấy ngày hiện tại
	time_t currentTime = time(nullptr);
	tm* localTime = localtime(&currentTime);

	// Tạo tên tệp nhật ký theo định dạng log-yymmdd.txt
	ostringstream filenameStream;
	filenameStream << "log-" << put_time(localTime, "%y%m%d") << ".txt";
	string filename = filenameStream.str();

	// Mở tệp văn bản để ghi
	ofstream logFile(filename, ios_base::app);
	if (logFile.is_open()) {
		// Ghi vào tệp văn bản
		logFile << message << "\n";
		// Đóng tệp
		logFile.close();
	}
	else {
		cout << "khong the mo file" << endl;
	}
}

// 7 Menu for selection - Menu
void displayMenu(int select) {
	system("cls"); // Xóa màn hình (Windows)
	cout << "Menu:\n";
	cout << (select == 1 ? "->" : "  ") << "1. Categories\n";
	cout << (select == 2 ? "->" : "  ") << "2. Products\n";
	cout << (select == 3 ? "->" : "  ") << "3. Orders\n";
	cout << (select == 4 ? "->" : "  ") << "4. Report\n";
	cout << (select == 5 ? "->" : "  ") << "5. Quit\n";
}

void Menu()
{
	int select = 1;
	char key;

	do {
		displayMenu(select);

		key = _getch(); // Đọc một phím từ bàn phím

		switch (key) {
		case 72: // Phím mũi tên lên
			if (select > 1)
				select--;
			break;
		case 80: // Phím mũi tên xuống
			if (select < 5)
				select++;
			break;
		case 13: // Phím enter
			//system("cls"); // Xóa màn hình (Windows)
			cout << "Ban da chon muc " << select << ".\n";
			system("pause");
			break;
		}
	} while (key != 27);
}

// 8 String to fraction conversion - FractionToDouble
void FractionToDouble(string s)
{
	getline(cin, s);
	string num = "";
	string denom = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '/')
		{
			denom = s.substr(i+1);
			num = s.substr(0, i);
		}
	}
	double result = (double)stoi(num) / (double)stoi(denom);
	cout << num << "/" << denom << " = ";
	cout << fixed << setprecision(2) << result;
}

// 9 Read integers from text file - IntegersCsv
void selectionSort(vector<int>& a)
{
	int i, j, min;
	for (i = 0; i < a.size() - 1; i++)
	{
		min = i;
		for (j = i + 1; j < a.size(); j++)
			if (a[j] < a[min])
				min = j;
		swap(a[min], a[i]);
	}
}

void IntegerCSV()
{
	ifstream file("data.txt"); 
	vector<int> so; 

	if (file.is_open()) { 
		string line;
		while (getline(file, line)) { 
			stringstream ss(line); 
			string numberStr;
			while (getline(ss, numberStr, ',')) { 
				int number;
				istringstream(numberStr) >> number; 
				so.push_back(number); 
			}
		}
		file.close(); 
	}
	else {
		cout << "Khong the mo tep" << endl;
	}

	selectionSort(so);
	cout << "Reading data.txt...\n";
	cout << "Found " << so.size() << " numbers.\n";

	for (int x : so) {
		cout << x << " ";
	}

}

// 10 Path parser - FileInfo
void FileInfo(string s)
{
	getline(cin, s);
	string extension = "";
	string name = "";
	string folder = "";

	// Find the position of the last '\' character
	int x = s.find_last_of('\\');

	// Extract folder and name
	if (x != s.length()) {
		folder = s.substr(1, x);
		name = s.substr(x + 1,s.length());
	}

	// Find the position of the last '.' character
	int c = name.find_last_of('.');

	// Extract extension
	if (c != s.length())
	{
		extension = name.substr(c,4);
		name = name.substr(0, c);
	}

	cout << "Folder: " << folder << endl;
	cout << "Filename: " << name + extension << endl;
	cout << "Extension: " << extension << endl;
}

int main() {
	string s="";
	// 1
	// deathLoop();
	
	// 2
	// wrongPassword(s);
	
	// 3
	// CurrencyDisplay();

	// 4
	//randomIntegers();
	// 
	// 5
	// NextDay();
	
	// 6
	// Logger("Exception tai ham export. Li do: Invalid input exception");
	
	// 7
	// Menu();
	
	// 8
	//FractionToDouble(s);
	
	// 9
	// IntegerCSV();
	
	// 10
	// FileInfo(s);
	return 0;
}