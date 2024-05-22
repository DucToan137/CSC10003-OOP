#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>



class Object;
class NumberFormat;
class String;
class Integer;
class IntegerToStringConverter;


class Object {
public:
	virtual std::string toString() { return "Object"; };
};

class IShape : public Object
{
public:
	virtual double area() const = 0;
	virtual double perimeter() const = 0;

	std::string toString() override { return "IShape"; };
};

class IParsable: public Object {
public:
	virtual IShape* parse(const std::string& line) = 0;
	virtual std::string parsedObjectName() = 0;
	std::string toString() override { return "IParsable"; };
};

class Square : public IShape
{
private:
	double _a;
public:
	Square(double a) : _a(a) {}

	double area() const override
	{
		return _a * _a;
	}

	double perimeter() const override
	{
		return 4 * _a;
	}

	std::string toString() override { return "Square"; };
};

class Rectangle : public IShape
{
private:
	double _width; // width
	double _height;
public:
	Rectangle(double w, double h) : _width(w), _height(h) {}

	double area() const override
	{
		return _width * _height;
	}

	double perimeter() const override
	{
		return 2 * (_width + _height);
	}
	std::string toString() override { return "Rectangle"; };
};

class Circle : public IShape
{
private:
	double _radius;
public:
	Circle(double r) : _radius(r) {}

	double area() const override
	{
		return 3.14 * _radius * _radius;
	}

	double perimeter() const override
	{
		return 2 * 3.14 * _radius;
	}

	std::string toString() override { return "Circle"; };
};

class Triangle : public IShape
{
private:
	double _a;
	double _b;
	double _c;
public:
	Triangle(double a, double b, double c) : _a(a), _b(b), _c(c) {}

	double area() const override
	{
		double s = (_a + _b + _c) / 2;
		return sqrt(s * (s - _a) * (s - _b) * (s - _c));
	}

	double perimeter() const override
	{
		return _a + _b + _c;
	}

	std::string toString() override { return "Triangle"; };
};

class SquareParser : public IParsable
{
public:
	IShape* parse(const std::string& line) override
	{
		std::istringstream iss(line);
		std::string value;
		getline(iss, value, '='); // skip the first part
		getline(iss, value); // get the second part
		double a = stof(value);
		
		IShape* shape = new Square(a);
		return shape;
	}

	std::string parsedObjectName() override { return "Square"; };
	std::string toString() override { return "SquareParser"; };
};

class RectangleParser : public IParsable
{
public:
	IShape* parse(const std::string& line) override
	{
		std::istringstream iss(line);
		double width = _extractWidth(iss);
		double height = _extractHeight(iss);

		IShape* shape = new Rectangle(width, height);
		return shape;
	}
	std::string parsedObjectName() override { return "Rectangle"; };
	std::string toString() override { return "RectangleParser"; };
private:
	double _extractHeight(std::istringstream& iss)
	{
		std::string value2;
		getline(iss, value2, '='); // skip the height part
		getline(iss, value2);
		double height = stof(value2);
		return height;
	}

	double _extractWidth(std::istringstream& iss)
	{		
		std::string value1;
		getline(iss, value1, '='); // skip the first part
		getline(iss, value1, ','); // get width
		double width = stof(value1);
		return width;
	}
};

class CircleParser : public IParsable
{
public:
	IShape* parse(const std::string& line) override
	{
		std::istringstream iss(line);
		std::string value;
		getline(iss, value, '='); // skip the first part
		getline(iss, value);
		double r = stof(value);
		IShape* shape = new Circle(r);
		return shape;
	}
	std::string parsedObjectName() override { return "Circle"; };
	std::string toString() override { return "CircleParser"; };
};

class TriangleParser : public IParsable
{
public:
	//Triangle: a=8, b=6, c=10
	IShape* parse(const std::string& line) override
	{
		IShape* shape = nullptr;

		std::istringstream iss(line);
		std::string value1;
		getline(iss, value1, '='); // skip the first part
		getline(iss, value1, ','); // Get first side value
		double a = stof(value1);

		std::string value2;
		getline(iss, value2, '=');
		getline(iss, value2, ','); // Get the second side value
		double b = stof(value2);

		std::string value3;
		getline(iss, value3, '=');
		getline(iss, value3); // Get the second side value
		double c = stof(value3);

		shape = new Triangle(a, b, c);
		return shape;
	}
	std::string parsedObjectName() override { return "Triangle"; };
	std::string toString() override { return "TriangleParser"; };
};

template <class T>
class Factory {
private:
	// TODO: smart pointer
	inline static Factory* _instance = nullptr;
	std::map<std::string, T> _parsers;
public:
	void registerWith(T parser) {
		_parsers.insert({ parser->parsedObjectName(), parser });
	}	
	static Factory* instance() {
		if (_instance == nullptr) {
			_instance = new Factory<T>();
		}

		return _instance;
	}
private:
	Factory() {
	}
public:
	T create(std::string type) {
		T parser = _parsers[type];
		return parser;
	}
};

class NumberFormat {
private:
	std::string _thousandsSeparator; // , . " "
	std::string _decimalSeparator;   // . ,
	int _precision;
	int _positiveCurrency;               // 0, 1, 2, 3
	std::string _positiveCurrencyFormat; // n$, $n, n $, $ n 
public:
	NumberFormat( std::string thousandsSeparator, std::string decimalSeparator, int precision) :
		_decimalSeparator(decimalSeparator), _thousandsSeparator(thousandsSeparator), _precision(precision) {}
};

class IValueConverter : public Object {
public:
	virtual Object* convert(Object* source) = 0;
};

class String : public Object {
private:
	std::string _value;
public:
	String(std::string value);
	std::string value();
	// TODO: tóString
};


class FloatToStringConverter: IValueConverter {
private:
	NumberFormat _format;
public:
	FloatToStringConverter(NumberFormat format);

	Object* convert(Object* source) override;
};

FloatToStringConverter::FloatToStringConverter(NumberFormat format) : _format(format) {}
Object* FloatToStringConverter::convert(Object* source) {
	String* result = new String("1.000,78");
	return result;
}

class Integer : public Object {
private:
	int _value;
public:
	Integer(int value);
	int value();
	// TODO: tóString
};

class IntegerToStringConverter : public IValueConverter {
private:
	NumberFormat _format;
public:
	IntegerToStringConverter(NumberFormat format);
	Object* convert(Object* source) override;
};

IntegerToStringConverter::IntegerToStringConverter(NumberFormat format) : _format(format) {
}

Object* IntegerToStringConverter::convert(Object* source) {
	Integer* info = dynamic_cast<Integer*>(source);
	int value = info->value();

	String* result = new String("2.456.872");
	return result;
}

// Wrapper class => primitive / value type => object type

// string convert(int);



String::String(std::string value) : _value(value) {
}

std::string String::value() { return _value; }





class Float : public Object {
private:
	float _value;
public:
	Float(int value) : _value(value) {}
	float value() { return _value; }
	// TODO: tóString
};

template <typename T>
class Wrapper {
private:
	T _value;
public:
	Wrapper(T value) : _value(value) {}
	T value() { return _value; }
};


int Integer::value() {
	return _value;
}

Integer::Integer(int value) : _value(value) {

}

void config() {
	Factory<IParsable*>::instance()->registerWith(new SquareParser());
	Factory<IParsable*>::instance()->registerWith(new RectangleParser());
	Factory<IParsable*>::instance()->registerWith(new CircleParser());
	Factory<IParsable*>::instance()->registerWith(new TriangleParser());
}

 


int main()
{
	config();

    std::vector<std::string> lines = {
        "Square: a=12",
        "Circle: r=12",
        "Square: a=7",
        "Rectangle: w=3, h=4",
        "Rectangle: w=6, h=8",
        "Circle: r=5",
        "Square: a=8",
		"Triangle: a=8, b=6, c=10",
    };

	std::vector<IShape*> shapes;

	for (std::string line : lines)
	{
		std::istringstream iss(line);
		std::string type;
		getline(iss, type, ':');

		IParsable* parser = Factory<IParsable*>::instance()->create(type);
		IShape* shape = parser->parse(line);
		shapes.push_back(shape);
	}

	NumberFormat format(".", ",", 0);
	FloatToStringConverter stringConverter(format);
	IntegerToStringConverter integerConverter(format);

	int count = 10000000;
	Integer* integer = new Integer(count); // boxing
	Object* item = integerConverter.convert(integer);
	String* info = dynamic_cast<String*>(item); // casting
	std::cout << info->value() << std::endl; // unboxing

	for (auto shape : shapes) {
		std::cout << shape->toString() << ": " << shape->area() << " ";
		String* info = dynamic_cast<String*>(
			stringConverter.convert(new Float(shape->perimeter())));
		//std::cout << "\n";
		std::cout << info->value() << std::endl;
	}
}
