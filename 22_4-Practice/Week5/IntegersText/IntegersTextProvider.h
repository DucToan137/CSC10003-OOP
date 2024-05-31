#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Integer.h"


class IntegersTextProvider {
private:
	Integer num;
public:
	
	static std::vector <int> read(std::string filename);
	void DinhDangXuat(std::vector<int> a,std::string config);
	void Xuat(std::vector<int> a);
};