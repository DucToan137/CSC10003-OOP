#include<iostream>
#include<vector>
#include<tuple>
#include<string>
#include<regex>

using namespace std;


tuple<bool, int ,string, int> getInteger(int left, int right) {
	bool success = false;
	int errorCode = 0;
	string message = "";
	int data = 0;

	string buffer;
	getline(cin, buffer);

	if (buffer.length() == 0) {
		success = false;
		errorCode = 1;
		message ="Chuoi khong duoc rong";
	}
	else {
		string pattern = "\\d+";

		if (regex_match(buffer, regex(pattern))) {
			data = stoi(buffer);

			if (data< left || data > right) {
				success = false;
				errorCode = 4;
				message = "So nhap vao khong nam trong doan [" + to_string(left) + "," + to_string(right) + "]";
			}
			else
			success = true;
		}
		else {
			success = false;
			errorCode = 2;
			message = "Dinh dang so khong dung";
		}
	}

	auto result = make_tuple(success, errorCode, message, data);

	return result;
}