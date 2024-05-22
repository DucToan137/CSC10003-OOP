#include<iostream>
#include<vector>
#include<tuple>
#include<string>
#include<map>
#include"IShape.h"
#include"RandomIntergerGenerator.h"
#include"RandomRectangleGenerator.h"
#include"RandomCircleGenerator.h"
#include"RandomTriangleGenerator.h"


using namespace std;


//====================================YÊU CẦU======================================================
// 1. Generate a random integer n in the range [6,12]
// 2. Generate randomly n shapes which belong to three types: Circle, Rectangle, Triangle
//		For rectangle, width and height should be in the range [1,10]
//		For triangle, three edges should be in the range [1,10]
//		For circle, the radius should be in the range [1,10]
// 3. Print out all the shapes generated, together with their areas and perimeter(chưa xong)
// 4. Save all generated graphics shape into the file "objects.txt"(chưa xong)
//=================================================================================================



// Cái nào xứng đáng vào trạng thải?
// Khi trạng thái thay đổi => Giao diện thay đổi
struct {
	vector<IShape*> shapes;
} state; // React / Vue , Kotlin/Jetpack Compose, SwiftUI, Flutter


// 1. May man: Happy path: co duoc n trong khoang left, right
// 2. Nhap chuoi rong ==> loi
// 3. Nhap sai dinh dang (jsven)
// 4. 20 ==> loi
tuple<bool,int,string,int> getInteger(int left, int right); // API Web: trả ra chuẩn


class ShapeFactory { // Mẫu Singleton
private:
	inline static ShapeFactory* _instance = nullptr;
	vector<IShape*> _prototypes;

	ShapeFactory() { // Cấu hình 1 lần duy nhất
		_prototypes.push_back(new Rectangle());
		_prototypes.push_back(new Triangle());
		_prototypes.push_back(new Circle());
	}
public:
	int supportedTypesCount() {
		const int TotalShapes = 3;

		return TotalShapes;
	}

	IShape* create(int type) {
		const int left = 6;
		const int right = 12;
		
		IShape* shape = _prototypes[type]->generate(left, right); // IShape* =



		return shape;
	}

	static ShapeFactory* instance() {
		if (_instance == nullptr) {
			_instance = new ShapeFactory();
		}
		return _instance;
	}
};

class IConverter {
public:
	virtual string convert(void* shape) = 0;

};

class RectangleUIConverter:public IConverter {
public:
	string convert(void* shape) {
		Rectangle* rectangle = (Rectangle*)shape;

		stringstream builder;
		builder << rectangle->className() <<": ";
		builder << "Width=" << rectangle->a() << ", Height=" << rectangle->b();


		string result =builder.str();
		return result;
	}
};

class CircleUIConverter:public IConverter {
public:
	string convert(void* shape) {
		Circle* circle = (Circle*)shape;

		stringstream builder;
		builder << circle->className() << ": ";
		builder << "Radius= " << circle->r();


		string result = builder.str();
		return result;
	}
};

class TriangleUIConverter: public IConverter {
public:
	string convert(void* shape) {
		Triangle* triangle = (Triangle*)shape;

		stringstream builder;
		builder << triangle->className() << ": ";
		builder << "a=" << triangle->a() << ", b=" << triangle->b() << ", c=" << triangle->c();

		string result = builder.str();
		return result;
	}
};




int main() {

	// 1. Sinh ngẫu nhiên số nguyên n trong khoảng [6,12]

	const int left = 6;
	const int right = 12;

	int n= RandomIntegerGenerator::instance()->next(left, right);
	// 2. Sinh ra n hình
	for (int i = 0; i < n; i++)
	{
		int count = ShapeFactory::instance()->supportedTypesCount();
		int type = RandomIntegerGenerator::instance()->next(count);
		IShape* shape = ShapeFactory::instance()->create(type);
		state.shapes.push_back(shape);
	}

	// Cấu hình
	map<string, IConverter*> ui{
		{(new Rectangle())->className(), new RectangleUIConverter()},
		{(new Circle())->className(), new CircleUIConverter()},
		{(new Triangle())->className(), new TriangleUIConverter()}
	};

	for (int i = 0; i < n; i++)
	{
		auto converter = ui[state.shapes[i]->className()];
		string data = converter->convert((void*)state.shapes[i]);

		cout << data << "\n";
	}

	cout << n;

	/*bool shouldRepeat = false;
	int n;
	bool success = false;
	int errorCode = 0;
	string message = "";

	do {
		cout << "Nhap so nguyen n trong doan [" << left << "," << right << "]: ";
		tie(success, errorCode, message, n) = getInteger(left, right);

		if (success) {
			shouldRepeat = false;
		}
		else {
			cout << "Loi khi nhap lieu: " << message << endl;
			shouldRepeat = true;
		}
	} while(shouldRepeat);*/

	return 0;
}