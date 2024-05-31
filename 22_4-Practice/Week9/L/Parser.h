#include"Booth.h"
#include"FoodBooth.h"
#include"ClothesBooth.h"
#include"JewelryBooth.h"

class Parser {
public:
public:
	Booth* parse(string& line) {

		line.erase(remove(line.begin(), line.end(), ','), line.end());

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
			return new FoodBooth(id, area, extraFee);
		}
		else if (type == "Clothes") {
			return new ClothesBooth(id, area);
		}
		else if (type == "Jewelry") {
			ss.ignore(14, '='); // Skip to SecurityFee
			ss >> extraFee;
			return new JewelryBooth(id, area, extraFee);
		}

		return nullptr;
	}
};
