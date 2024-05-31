#include<iostream>
#include"Booth.h"
#include"FoodBooth.h"
#include"ClothesBooth.h"
#include"JewelryBooth.h"
#include"Parser.h"

using namespace std;


int main() {
	vector<Booth*> booths;
	ifstream inputFile("RentMay24.txt");
	Parser parser;
	string line;
	while (getline(inputFile, line)) {
		Booth* booth = parser.parse(line);
		if (booth) {
			booths.push_back(booth);
		}
	}
	inputFile.close();

	// Sort booths by total rent in ascending order
	sort(booths.begin(), booths.end(), [](Booth* a, Booth* b) {
		return a->calculateTotalRent() < b->calculateTotalRent();
		});

	
	// Print report
	cout << "Bao cao thu tien thue mat bang cho Ben Thanh Thang: 05/2024" << endl << endl;
	cout << setw(3) << "STT" << " | "
		<< setw(6) << "Ma sap" << " | "
		<< setw(10) << "Loai" << " | "
		<< setw(10) << "Dien tich" << " | "
		<< setw(9) << "Tien / m2" << " | "
		<< setw(15) << "Tien mat bang" << " | "
		<< setw(11) << "Phi khac" << " | "
		<< setw(14) << "Tong cong" << endl;
	cout << string(101, '-') << endl;

	int totalRent = 0;
	int index = 1;
	for (const auto& booth : booths) {
		cout << setw(3) << index++ << " | ";
		booth->printInfo(cout);
		totalRent += booth->calculateTotalRent();
	}
	cout << endl << "Tong tien thue mat bang thu trong thang: " << totalRent << " d" << endl;

	for (auto& booth : booths) {// Clean up
		delete booth;
	}
	return 0;
}

