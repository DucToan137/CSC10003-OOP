#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<memory>

using namespace std;

// Forward declaration
class Fraction;
template<class MyClass>
class DynamicArray;
class IntegerRandomizer;

class Fraction {
private:
	int _num;
	int _den;
public:
	int Numerator() { return _num; }
	void setNumerator(int num) { _num = num; }
	int Denominator() { return _den; }
	void setDenominator(int den) { _den = den; }
public:
	Fraction();
	Fraction(int num, int den);

	string toString();

	// Copy constructor
	Fraction(const Fraction& other);

	const Fraction& operator=(const Fraction& other);

	// Copy assignment operator
};

template<class MyClass>
class DynamicArray {
private:
	//int* _a = nullptr;
	MyClass *_a = nullptr;
	int _maxSize;
	int _currentSize;
	const int _length = 10;
public:
	DynamicArray() {
		_a = new MyClass[_length];
		_maxSize = _length;
		_currentSize = 0;
	}

	DynamicArray(const DynamicArray& other) {
		_maxSize = other._maxSize;
		_currentSize = other._currentSize;
		//_a = new int[_maxSize];
		_a = new MyClass[_maxSize];
		
		for (int i = 0; i < _currentSize; i++) {
			_a[i] = other._a[i];
		}
	}

	const DynamicArray& operator=(const DynamicArray& other) {
		_maxSize = other._maxSize;
		_currentSize = other._currentSize;
		//_a = new int[_maxSize];
		_a = new MyClass[_maxSize];

		for (int i = 0; i < _currentSize; i++) {
			_a[i] = other._a[i];
		}

		return other;
	}

	~DynamicArray() {
		if (_a != nullptr)
		{
			delete[] _a;
		}
	}

	MyClass getAt(int index) {
		if (index < _currentSize && index >= 0)
		{
			return _a[index];
		}
		else
		{
			throw new exception("Index out of bound");
		}
	}

	MyClass operator[] (int index) {
		return getAt(index);
	}

	int size() {
		return _currentSize;
	}

	void push_back(MyClass value) {
		if (_currentSize >= _maxSize)
		{
			// Cấp phát vùng nhớ mới 
			_maxSize = _maxSize + _length;
			//int * temp = new int[_maxSize];
			MyClass* temp = new MyClass[_maxSize];

			// Di chuyển dữ liệu cũ qua
			for (int i = 0; i < _currentSize; i++) {
				temp[i] = _a[i];
			}

			// Giải phóng vùng nhớ cũ
			delete[] _a;

			// Giao quyền quản lí lại cho _a
			_a = temp;
		}
		_a[_currentSize] = value;
		_currentSize++;
	}

	void removeAt(int index) {
		if (index < _currentSize && index >= 0)
		{
			for (int i = index + 1; i < _currentSize; i++)
			{
				_a[i - 1] = _a[i];
			}
			_currentSize--;
		}
		else
		{
			throw new exception("Index out of bound");
		}
	}
};

// Thiết kế lớp kiểu Singleton
class IntegerRandomizer {
private:
	inline static shared_ptr<IntegerRandomizer> _instance = nullptr; 
	// Nếu không inline thì cần IntegerRandomizer* IntegerRandomizer::_instance = nullptr;
	// Dùng inline để gộp thành 1 dòng. Vừa khai báo vừa khởi tạo
	
	IntegerRandomizer() {
		cout << "Ham tao bo sinh so ngau nhien\n"; // Chứng minh khởi tạo 1 lần
		srand(time(NULL));
	}

	
public:

	~IntegerRandomizer() {
		cout << "Destructor of Integer\n";
	}

	static shared_ptr<IntegerRandomizer> instance() {
		if (_instance == nullptr)
		{
			_instance = shared_ptr<IntegerRandomizer>(new IntegerRandomizer());
		}
		return _instance;
	}

	int next() {
		return rand();
	}

	int next(int ceiling) {
		return rand() % ceiling;
	}	
};

class FractionRandomizer {
public:

	Fraction next() {
		int num = IntegerRandomizer::instance()->next(100);
		int den = IntegerRandomizer::instance()->next(100) + 1;

		Fraction result(num, den);

		return result;
	}
};

class Dice {
private:
	int _faces = 6;
public:
	Dice() {};
	
	Dice(int faces) { _faces = faces; }
	
	int faces() { return _faces; }

	int roll() {
		return IntegerRandomizer::instance()->next(_faces) + 1;
	}
};

Fraction::Fraction() {
	_num = 0;
	_den = 1;
}

Fraction::Fraction(int num, int den) {
	_num = num;
	_den = den;
}

string Fraction::toString() {
	stringstream builder;
	builder << _num << "/" << _den;
	string result = builder.str();

	return result;
}

Fraction::Fraction(const Fraction& other) {
	//cout << "Copy constructor\n";
	this->_num = other._num;
	this->_den = other._den;
}

const Fraction& Fraction::operator=(const Fraction& other) {
	//cout <<"Operator= \n";
	this->_num = other._num;
	this->_den = other._den;

	return other;
	//return *this;

}	// this -> Fraction* || *this -> Fraction

int main() {

	//Fraction start(1, 2);
	////Fraction clone(start);

	////Fraction end = start = clone; // a = b = c = d

	//Fraction x = start; // Constructor Fraction, operator= ===> Copy constructor

	//cout << start.toString() << endl;
	//cout << x.toString() << endl;

	//DynamicArray a;
	//IntegerRandomizer rng;

	//for (int i = 0; i < 20; i++) {
	//	a.push_back(rng.next());
	//}

	//for (int i = 0; i < a.size(); i++) {
	//	cout << a[i] << " ";
	//}

	//cout << "\n";


	////DynamicArray b(a); // Cần hàm tạo sao chép nếu không => lỗi

	//DynamicArray b;
	//b = a;
	//

	//for (int i = b.size() - 1; i >= 0; i--) {
	//	if (b[i] % 2 == 0)
	//	{
	//		b.removeAt(i);
	//	}
	//}

	//cout <<"Mang sau khi loc so chan: ";
	//for (int i = 0; i < b.size(); i++) {
	//	cout << b[i] << " ";
	//}

	// Phát sinh ngấu nhiên 20 phân số và in ra màn hình
	/*DynamicArray<Fraction> a;
	FractionRandomizer rng;

	for (int i = 0; i < 20; i++) {
		a.push_back(rng.next());
	}

	for (int i = 0; i < a.size(); i++) {
		cout << a[i].toString() << "\n";
	}	*/
	Dice d1;
	Dice d2;
	vector<int> a1;
	vector<int> a2;

	for (int i = 0; i < 10; i++) {
		a1.push_back(d1.roll());
		a2.push_back(d2.roll());
	}

	for (int i = 0; i < a1.size(); i++)
	{
		cout << a1[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < a2.size(); i++)
	{
		cout << a2[i] << " ";
	}
	cout << "\n";

	return 0;
}