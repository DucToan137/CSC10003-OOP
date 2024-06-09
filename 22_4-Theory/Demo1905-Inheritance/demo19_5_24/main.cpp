#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

// Forward declaration
class Car;

// Declaration (Car.h)
class Car {
protected: // lớp con có thể sử dụng được, bên ngoài không sử dụng được
	string _brand;
private:
	void _checkGasoline();
public:
	// 2 hàm tạo không được kế thừa
	Car();
	Car(string brand);
public:
	~Car();
public:
	virtual string classname() { return "Car"; }
	string brand();
	virtual void start();
};

// Declaration (Carbriolet.h)
class Carbriolet : public Car {
public:
	Carbriolet(string brand);
	~Carbriolet();
public:
	string classname() { return "Carbriolet"; }
	void start();
};

class ElectricCar : public Car {
private:
	void _checkPower() {
		cout << "Checking power level. All is fine\n";
	}
public:
	ElectricCar(string brand):Car(brand) {}

	void start() {
		cout << _brand << " car is starting\n";
		_checkPower();
	}

	string classname() { return "ElectricCar"; }


};

// Implementation (Car.cpp)
Car::Car() {
	cout << "Car's defaut constructor\n";
}

Car::Car(string brand) {
	_brand = brand;
	//cout <<"Car's parametered constructor\n";
}

void Car::start() {
	cout << "Car " << _brand << " is starting\n";
	_checkGasoline();
}

void Car::_checkGasoline() {
	cout << "Checking gasoline level. All is fine\n";
}

Car::~Car() {
	//cout << "Car's destructor\n";
}

// Implementation (Carbriolet.cpp)

//Carbriolet::Carbriolet(string brand) { // gọi hàm tạo k đối trước
//	_brand = brand;
//	//cout <<"Carbriolet's constructor\n";
//}

Carbriolet::Carbriolet(string brand) : Car(brand) {}

Carbriolet::~Carbriolet() {
	//cout << "Carbriolet's destructor\n";
}

void Carbriolet::start() { // overwrite - ghi đè
	cout <<"Removing the hood\n";
	Car::start();
}

/////////////////Game////////////////////

class Choice {
public:
	inline static int scissor = 1;
	inline static int rock = 2;
	inline static int paper = 3;
};

class RandomInteger {
private:
	inline static RandomInteger* _instance = nullptr;

	RandomInteger() {
		srand(time(NULL));
	}
public:
	static RandomInteger* instance() {
		if (_instance == nullptr) {
			_instance = new RandomInteger();
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

class AI {
public:
    int answer(int playerChoice) {
        
		int result = RandomInteger::instance()->next(3) + 1;
		return result;
    }
};

class Result {
public:
	inline static int win = 1;
	inline static int lose = -1;
	inline static int draw = 0;
};

class Game {
public:
	int check(int playerChoice, int computerChoice) {
		int result;
		if (playerChoice == Choice::scissor)
		{
			if (computerChoice == Choice::scissor) { // Keo
				result = Result::draw; // Hoa
			} else if (computerChoice == Choice::rock) {
				result = Result::lose; // Thua
			} else if (computerChoice == Choice::paper) {
				result = Result::win; // Thang
			}
		}
		else if (playerChoice == Choice::rock) // Bua
		{
			if (computerChoice == Choice::scissor) {
				result = Result::win; // Thang
			} else if (computerChoice == Choice::rock) {
				result = Result::draw; // Hoa
			} else if (computerChoice == Choice::paper) {
				result = Result::lose; // Thua
			}
		}
		else if (playerChoice == Choice::paper) // Bao
		{
			if (computerChoice == Choice::scissor) {
				result = Result::lose; // Thua
			} else if (computerChoice == Choice::rock) {
				result = Result::win; // Thang
			} else if (computerChoice == Choice::paper) {
				result = Result::draw; // Hoa
			}
		}
		return result;
	}
};

class ChoiceConveter {
public:
	string convert(int choice) {
		string result = "";
		if (choice == Choice::scissor)
		{
			result = "Keo";
		}
		else if (choice == Choice::rock)
		{
			result = "Bua";
		}
		else if (choice == Choice::paper)
		{
			result = "Bao";
		}
		return result;
	}
};

class ResultConveter {
public:
	string convert(int value) {
		string result = "";
		if (value == Result::win)
		{
			result = "Thang";
		}
		else if (value == Result::lose)
		{
			result = "Thua";
		}
		else if (value == Result::draw)
		{
			result = "Hoa";
		}
		return result;
	}
};

class AIAnGian :public AI{
private:
	int _count = 0;
public:
	int ansewer(int playerChoice) {
		_count++;
		int result;
		if (_count % 5 == 0)
		{
			if (playerChoice == Choice::scissor)
			{
				result = Choice::rock;
			}
			else if (playerChoice == Choice::rock)
			{
				result = Choice::paper;
			}
			else if (playerChoice == Choice::paper)
			{
				result = Choice::scissor;
			}
		}
		else
		{
			result = AI::answer(playerChoice);
		}
		
		return result;
	}
};

int main() {

	//Carbriolet car("Ford Everest");	
	//car.start(); // shadow - che bóng	

	
	/////////////Tro choi keo bua bao////////////////
	
	/*cout <<"Tro choi keo bua bao\n";
	Game game;
	AI ai;
	AIAnGian aiAnGian; // Luôn thắng người chơi vào lượt chia hết cho 5
	ChoiceConveter choiceConveter;
	ResultConveter resultConveter;

	bool shouldContinue = true;
	do {

		cout << "Ban ra gi vay?\n";
		cout << "1. Keo\n";
		cout << "2. Bua\n";
		cout << "3. Bao\n";
		cout <<"0. Thoat\n";

		string token;
		getline(cin, token);
		

		int playerChoice = stoi(token);

		if (playerChoice == Choice::rock ||
			playerChoice == Choice::scissor ||
			playerChoice == Choice::paper)
		{

			shouldContinue = true;


			int computerChoice = aiAnGian.ansewer(playerChoice);
			int result = game.check(playerChoice, computerChoice);

			cout << "Ban ra: " << choiceConveter.convert(playerChoice) << endl;
			cout << "May ra: " << choiceConveter.convert(computerChoice) << endl;
			cout << "==> Ban " << resultConveter.convert(result) << "\n\n";
		}
		else
		{
			shouldContinue = false;
		}
	} while (shouldContinue);*/

	// Đa xạ - Giữ địa chỉ đối tượng thuộc lớp con thông qua con trỏ lớp cha
	Car* car1 = new Car("Ford Everest");
	//car1->start();

	Carbriolet* car2 = new Carbriolet("Mercedes-Benz");
	//car2->start();

	Car* car3 = new ElectricCar("BMW"); // Con trỏ lớp cha giữ địa chỉ đối tượng thuộc lớp con => YES
	//car3->start();

	vector<Car*> cars = {
		car1, car2, car3
	};

	ElectricCar sample("Tesla");

	for (int i = 0; i < cars.size(); i++)
	{
		cars[i]->start();

		if (cars[i]->classname() == sample.classname())
		{
			ElectricCar *p = (ElectricCar*)cars[i];

			p->start(); // Hàm riêng của lớp ElectricCar
		}
	}



	return 0;
}