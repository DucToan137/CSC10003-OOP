#include <iostream>
#include <vector>
#include <memory>
#include <format>

class Point {
private: 
    int _x;
    int _y;
public:
    Point() {}
    Point(int x, int y) : _x(x), _y(y) {}
};

class Line {
private:
    Point _start;
    Point _end;
private:
    Line() {}
public:
    Line(Point start, Point end) : _start(start), _end(end) {
        /*if (_start == _end) {
			throw std::invalid_argument("Start and end points cannot be the same");
		}*/
    }
};

class Fraction {
private:
    int _numerator;
	int _denominator;
public:
    typedef std::shared_ptr<Fraction> Pointer;

    Fraction() {
    	_numerator = 0;
    	_denominator = 1;
    }

    Fraction(int numerator, int denominator) {
        if (denominator == 0) {
			throw std::invalid_argument("Denominator cannot be zero");
		}
        _numerator = numerator;
        _denominator = denominator;
    }

    std::string toString() {
        return std::format("{}/{}", _numerator, _denominator);
    }
    ~Fraction() {
        std::cout << "Destructor";
    }
};

class Vehicle {
protected:
    std::string _brand;
public:
    Vehicle() { }//std::cout << "Vehicle's constructor\n"; }
public:
    Vehicle(std::string brand) : _brand(brand) {
        //std::cout << "Vehicle's parameterized constructor\n";
    }
    virtual void start() { std::cout << "A vehicle is starting...\n"; }
    void run() { std::cout << "A vehicle is rolling...\n"; }
    
    virtual ~Vehicle() {
        std::cout << "Vehicle's destructor\n"; 
    }
};

class Car : public Vehicle {
public:
    Car() {
		//std::cout << "Car's constructor\n";
	}
    Car(std::string brandName):Vehicle(brandName) {    
        //std::cout << "Car's parameterized constructor\n";
    }
    std::string toString() {
        return  std::format("I am a {} car\n",
            _brand);
    }
    ~Car() {
        std::cout << "Car's destructor\n";
    }
public:
    void start() override {
        /*std::cout << "From the old way:";
        Vehicle::start();*/
        
        std::cout << "\nTo the new way:";
        std::cout << std::format(
        "A {} has its own way to start\n",
        _brand);
    }
};

class Shape {
public:
    virtual float area() { return 0; } // abstract function
};

// shadow & override
// overload & override

class Circle : public Shape {
private:
    float _radius;
public:
    Circle() {}
    Circle(float radius) { _radius = radius; }
    float area() override  {
		return 3.14 * _radius * _radius;
	}
};

int main()
{
    /*Shape* shape = new Circle(5);
    std::cout << shape->area() << "\n";*/

    /*Car* merc = new Car("Mercedes");
    merc->start();*/

    Vehicle* ford = new Car("Ford");
    //ford->start(); // override - runtime resolution
    delete ford;


    /*Car merc("Mercedes");
    merc.start();*/

    ////auto [success, f, code, message] = Fraction::create(1, 0);
    //std::vector<Fraction::Pointer> a = {
    //    std::make_shared<Fraction>(1, 2),
    //    std::make_shared<Fraction>(3, 7),
    //    std::make_shared<Fraction>(5, 9),
    //    std::make_shared<Fraction>(6, 11),
    //};

    // TODO: Tai sao weak pointer bi anh huong use count
    //for (int i = 0; i < a.size(); i++) {
    //    std::weak_ptr<Fraction> f = a[i];
    //    std::cout << f.lock()->toString() << " " << f.use_count() << "\n";
    //}
}