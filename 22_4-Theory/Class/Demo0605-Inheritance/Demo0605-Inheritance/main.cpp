#include <iostream>
#include <vector>
class Object { // abstract class
public:
    virtual std::string toString();
};

std::string Object::toString() {
	return "SuperWork::Object";
}

// Wrapper - Boxing - Unboxing
class Integer : public Object {
private:
	int _value;
public:
	Integer(int value) { _value = value; }
	std::string toString() override;
};

std::string Integer::toString() {
	return "SuperWork::Integer";
}

class Float : public Object {
private:
	float _value;
public:
	Float(float value) { _value = value; }
	std::string toString() override;
};


class IShape { // I - interface
public:
	virtual float area() = 0;
	virtual float perimeter() = 0;
};

class Rectangle : public IShape {
private:
	float _width;
	float _height;
public:
	Rectangle() {
		_width = 0.0f;
		_height = 0.0f;
	}

	Rectangle(float width, float height) {
		_width = width;
		_height = height;
	}

	float area() override {
		return _width * _height;
	}

	float perimeter() override {
		return 2 * (_width + _height);
	}
};

class Square : public IShape {
private:
	float _side;
public:

	Square() {
		_side = 0.0f;
	}

	Square(float side) {
		_side = side;
	}

	float area() override {
		return _side * _side;
	}

	float perimeter() override {
		return 4 * _side;
	}

};

class Circle : public IShape {
public:
	inline static const float PI = 3.14;
public:
	float _radius;
	Circle() {
		_radius = 0.0f;
	}

	Circle(float radius) {
		_radius = radius;
	}

	float area() override {
		return PI * _radius * _radius;
	}

	float perimeter() override {
		return 2 * PI * _radius;
	}
};

class Car {
public:
	virtual void run() = 0;
	virtual ~Car() {
		std::cout << "Car is destroyed" << std::endl;
	}
};

class GasolineCar : virtual public Car {
public:
	void run() override {
		std::cout << "GasolineCar is running" << std::endl;
	}
	~GasolineCar() {
		std::cout << "GasolineCar is destroyed" << std::endl;
	}
};

class ElectricCar : virtual public Car {
public:
	void run() override {
		std::cout << "ElectricCar is running" << std::endl;
	}

	~ElectricCar() {
		std::cout << "ElectricCar is destroyed" << std::endl;
	}
};

class HybridCar : public GasolineCar, public ElectricCar {
public:
	void run() override {
		std::cout << "HybridCar is running" << std::endl;
	}
	~HybridCar() {
		std::cout << "HybridCar is destroyed" << std::endl;
	}
};

class DieselCar : public Car {
public:
	void run() override {
		std::cout << "DieselCar is running" << std::endl;
	}

	~DieselCar() {
		std::cout << "DieselCar is destroyed" << std::endl;
	}
};




int main()
{
	std::vector<IShape*> shapes = {
		new Rectangle(10, 20),
		new Square(10),
		new Circle(10),
		new Square(12),
		new Rectangle(1, 7),
	};

	for (auto item : shapes) {
		std::cout << item->area() << std::endl;
	}
}
