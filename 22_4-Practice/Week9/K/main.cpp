#include <algorithm>
#include <iomanip>
#include<vector>
#include<string>
#include <sstream>
#include<fstream>
#include"Booth.h"
#include"FoodBooth.h"
#include"ClothesBooth.h"
#include"JewelryBooth.h"

using namespace std;








int main() {

    vector<Booth*> booths;
    ifstream inputFile("RentMay24.txt");
    string line;
    while (getline(inputFile, line)) {
        line.erase(remove(line.begin(), line.end(), ','), line.end());// removeCommas;

        istringstream ss(line);
        string type, id;
        int area, extraFee;

        ss >> type;
        ss.ignore(4, '=');
        ss >> id >> ws;
        ss.ignore(6, '='); // Skip to Area
        ss >> area;

        if (type == "Food") {
            ss.ignore(13, '='); // Skip to ColdStorage
            ss >> extraFee;
            booths.push_back(new FoodBooth(id, area, extraFee));
        }
        else if (type == "Clothes") {
            booths.push_back(new ClothesBooth(id, area));
        }
        else if (type == "Jewelry") {
            ss.ignore(14, '='); // Skip to SecurityFee
            ss >> extraFee;
            booths.push_back(new JewelryBooth(id, area, extraFee));
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

    // Clean up
    for (auto& booth : booths) {
        delete booth;
    }

    return 0;
}