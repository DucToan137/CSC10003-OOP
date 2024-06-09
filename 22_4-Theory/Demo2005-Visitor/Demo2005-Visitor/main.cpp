#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class IVisitor;
class InsuranceSale;

class IHouse;
class Resident;
class Store;
class Bank;
class Enterprise;


class IVisitor { // single source of truth - config
public:
	virtual void visit(Resident* resident) = 0;
	virtual void visit(Store* store) = 0;
	virtual void visit(Bank* bank) = 0;
	//virtual void visit(Enterprise* ent) = 0;
};

class IHouse {
public:
	virtual void accept(IVisitor* visitor) = 0;
};

class Resident : public IHouse {
public:
	void accept(IVisitor* visitor) override;
};

class Store : public IHouse {
public:
	void accept(IVisitor* visitor) override;
};

class Bank : public IHouse {
public:
	void accept(IVisitor* visitor) override;
};

class InsuranceSale: public IVisitor {
public:
	void visit(Resident* resident) override;
	void visit(Store* store) override;
	void visit(Bank* bank) override;
};

//---------------------------

void Resident::accept(IVisitor* visitor) {
	visitor->visit(this);
}

void Store::accept(IVisitor* visitor) {
	visitor->visit(this);
}

void Bank::accept(IVisitor* visitor) {
	visitor->visit(this);
}

// Version 3
void InsuranceSale::visit(Resident* resident) {
	std::cout << "Sell life insurance\n";
}

void InsuranceSale::visit(Store* store) {
	std::cout << "Sell theft insurance\n";
}

void InsuranceSale::visit(Bank* bank) {
	std::cout << "Sell fire insurance\n";
}


//void InsuranceSale::visit(IHouse* house) {
//	//// Prototype - Tight - Single source of truth - config
//	//IHouse* resident = new Resident();
//	//IHouse* store = new Store();
//	//IHouse* bank = new Bank();
//
//	//if (house->toString() == resident->toString()) {
//	//	std::cout << "Sell life insurance\n";
//	//}
//	//else if (house->toString() == store->toString()) {
//	//	std::cout << "Sell theft insurance\n";
//	//}
//	//else if (house->toString() == bank->toString()) {
//	//	std::cout << "Sell fire insurance\n";
//	//}
//	//else {
//	//	std::cout << "No insurance available\n";
//	//}
//
//	// Version 2 - Thiet ke toi
//	if (typeid(*house) == typeid(Resident)) {
//		std::cout << "Sell life insurance\n";
//	}
//	else if (typeid(*house) == typeid(Store)) {
//		std::cout << "Sell theft insurance\n";
//	}
//	else if (typeid(*house) == typeid(Bank)) {
//		std::cout << "Sell fire insurance\n";
//	}
//	else {
//		std::cout << "No insurance available\n";
//	}
//}

class IDao;
class ISaveable;
class TextDataProvider;
class XmlDataProvider;

class IShape;
class Rectangle;
class Square;
class Triangle;

class IValueConverter;
class SquareToStringConverter;
class RectangleToStringConverter;
class TriangleToStringConverter;

class SquareToXmlConverter;
class RectangleToXmlConverter;
class TriangleToXmlConverter;

class IValueConverter {
public:
	virtual std::string convert(IShape* shape) = 0;
};
class SquareToStringConverter : public IValueConverter {
public:
	std::string convert(IShape* shape) override;
};
class RectangleToStringConverter : public IValueConverter {
public:
	std::string convert(IShape* shape) override;
};
class TriangleToStringConverter : public IValueConverter {
public:
	std::string convert(IShape* shape) override;
};

class SquareToXmlConverter : public IValueConverter {
public:
	std::string convert(IShape* shape) override;
};
class RectangleToXmlConverter : public IValueConverter {
public:
	std::string convert(IShape* shape) override;
};
class TriangleToXmlConverter : public IValueConverter {
public:
	std::string convert(IShape* shape) override;
};

class IDao {
public:
	virtual void insert(Square*) = 0;
	virtual void insert(Rectangle*) = 0;
	virtual void insert(Triangle*) = 0;
public:
	virtual ~IDao();
};


class XmlDataProvider : public IDao {
private:
	std::string _filename;
	std::fstream _fs;
public:
	XmlDataProvider();
	XmlDataProvider(std::string);
	~XmlDataProvider();
public:
	void insert(Square*);
	void insert(Rectangle*);
	void insert(Triangle*);
};

class TextDataProvider : public IDao {
private:
	std::string _filename = "data.txt";
	std::fstream _fs;
public:
	TextDataProvider();
	TextDataProvider(std::string);
	~TextDataProvider();
	// TODO: Theem manual close
public:
	void insert(Square*);
	void insert(Rectangle*);
	void insert(Triangle*);
};

class ISaveable {
public:
	virtual void accept(IDao* dao) = 0;
};

class IShape: public ISaveable {
public:
};

class Rectangle : public IShape {
private:
	float _width;
	float _height;
public:
	Rectangle();
	Rectangle(float, float);

public://ISaveable
	void accept(IDao* dao);
public:
	friend class RectangleToStringConverter;
	friend class RectangleToXmlConverter;
};

class Square : public IShape {
private:
	float _side;
public:
	Square();
	Square(float);

public://ISaveable
	void accept(IDao* dao);

public:
	friend class SquareToStringConverter;
	friend class SquareToXmlConverter;
};

class Triangle: public IShape {
private:
	float _a;
	float _b;
	float _c;
public:
	Triangle();
	Triangle(float, float, float);
public://ISaveable
	void accept(IDao* dao);

public:
	friend class TriangleToStringConverter;
	friend class TriangleToXmlConverter;
};

// ==============================

IDao::~IDao() {}

Rectangle::Rectangle() {}
Rectangle::Rectangle(float w, float h) {
	_width = w;
	_height = h;
}

Square::Square() {}
Square::Square(float side) {
	_side = side;
}

Triangle::Triangle() {}
Triangle::Triangle(float a, float b, float c) {
	_a = a;
	_b = b;
	_c = c;
}

void Rectangle::accept(IDao* dao) {
	dao->insert(this);
}
void Square::accept(IDao* dao) {
	dao->insert(this);
}
void Triangle::accept(IDao* dao) {
	dao->insert(this);
}

TextDataProvider::TextDataProvider() {
	// TODO: Kiểm tra file tồn tại
	_fs.open(_filename, std::ios::out);
}
TextDataProvider::TextDataProvider(std::string input) {
	_filename = input;
	// TODO: Kiểm tra file tồn tại
	_fs.open(_filename, std::ios::out);
}
TextDataProvider::~TextDataProvider() {
	_fs.close();
}

void TextDataProvider::insert(Square* shape) {
	IValueConverter* converter = new SquareToStringConverter();
	std::string line = converter->convert(shape);
	_fs << line << "\n"; // std::endl / \n
}
void TextDataProvider::insert(Rectangle* shape) {
	IValueConverter* converter = new RectangleToStringConverter();
	std::string line = converter->convert(shape);
	_fs << line << "\n"; // std::endl / \n
}
void TextDataProvider::insert(Triangle* shape) {
	IValueConverter* converter = new TriangleToStringConverter();
	std::string line = converter->convert(shape);
	_fs << line << "\n"; // std::endl / \n
}

std::string SquareToStringConverter::convert(IShape* shape) {
	auto square = dynamic_cast<Square*>(shape);
	
	std::stringstream builder;
	builder << "Square: side=" << square->_side;

	std::string result = builder.str();
	return result;
}
std::string RectangleToStringConverter::convert(IShape* shape) {
	auto rect = dynamic_cast<Rectangle*>(shape);

	std::stringstream builder;
	builder << "Rectangle: width=" << rect->_width 
		<< ", height=" << rect->_height;

	std::string result = builder.str();
	return result;
}
std::string TriangleToStringConverter::convert(IShape* shape) {
	auto tri = dynamic_cast<Triangle*>(shape);

	std::stringstream builder;
	builder << "Triangle: a=" << tri->_a
		<< ", b=" << tri->_b
		<< ", c=" << tri->_c;

	std::string result = builder.str();
	return result;
}

XmlDataProvider::XmlDataProvider() {
	_filename = "data.xml";
	_fs.open(_filename, std::ios::out);
	_fs << "<Shapes>\n";
}
XmlDataProvider::XmlDataProvider(std::string input) {
	_filename = input;
	_fs.open(_filename, std::ios::out);
	_fs << "<Shapes>\n";
}
XmlDataProvider::~XmlDataProvider() {
	_fs << "</Shapes>\n";
	_fs.close();
}

void XmlDataProvider::insert(Square* shape) {
	IValueConverter* converter = new SquareToXmlConverter();
	std::string line = converter->convert(shape);
	_fs << line << "\n"; // std::endl / \n
}
void XmlDataProvider::insert(Rectangle* shape) {
	IValueConverter* converter = new RectangleToXmlConverter();
	std::string line = converter->convert(shape);
	_fs << line << "\n"; // std::endl / \n
}
void XmlDataProvider::insert(Triangle* shape) {
	IValueConverter* converter = new TriangleToXmlConverter();
	std::string line = converter->convert(shape);
	_fs << line << "\n"; // std::endl / \n
}

std::string SquareToXmlConverter::convert(IShape* shape) {
	auto square = dynamic_cast<Square*>(shape);

	std::stringstream builder;
	builder << "<Square Side=\"" << square->_side 
		<< "\" /> ";

	std::string result = builder.str();
	return result;
}
std::string RectangleToXmlConverter::convert(IShape* shape) {
	auto rect = dynamic_cast<Rectangle*>(shape);

	std::stringstream builder;
	builder << "<Rectangle Width=\"" << rect->_width
		<< "\" Height=\"" << rect->_height
		<<"\" />";

	std::string result = builder.str();
	return result;
}
std::string TriangleToXmlConverter::convert(IShape* shape) {
	auto tri = dynamic_cast<Triangle*>(shape);

	std::stringstream builder;
	builder << "<Triangle A=\"" << tri->_a
		<< "\" B=\"" << tri->_b
		<< "\" C=\"" << tri->_c
		<< "\" />";

	std::string result = builder.str();
	return result;
}

//=============================================

class ICharacter;
class Swordman;
class Knight;

class ICharacter {
protected:
	int _hp;
	int _atk;
public:
	int hp();
	void setHp(int value);
	int atk();
	void setAtk(int value);
	bool isAlive();
public:
	virtual void attack(ICharacter* other) = 0;
	virtual void attackedBy(Knight* other) = 0;
	virtual void attackedBy(Swordman* other) = 0;
	virtual void attackedBy(Pikeman* other) = 0;
	virtual void attackedBy(Archer* other) = 0;

	virtual std::string toString() = 0;
};

class Knight : public ICharacter {
public:
	Knight();
	void attack(ICharacter* other) override;
	void attackedBy(Knight* other) override;
	void attackedBy(Swordman* other) override;

	std::string toString() override;
};

class Swordman : public ICharacter {
public:
	Swordman();
	void attack(ICharacter* other) override;
	void attackedBy(Knight* other) override;
	void attackedBy(Swordman* other) override;

	std::string toString() override;
};
 // ================================

int ICharacter::hp() { return _hp; }
void ICharacter::setHp(int value) { _hp = value; }
int ICharacter::atk() { return _atk; }
void ICharacter::setAtk(int value) { _atk = value; }
bool ICharacter::isAlive() { return _hp > 0; }

Knight::Knight() {
	_hp = 200;
	_atk = 15;
}

Swordman::Swordman() {
	_hp = 200;
	_atk = 10;
}

std::string Knight::toString() {
	std::stringstream builder;
	builder << "Knight HP=" << _hp << ", ATK=" << _atk;

	std::string result = builder.str();
	return result;
}

std::string Swordman::toString() {
	std::stringstream builder;
	builder << "Swordman HP=" << _hp << ", ATK=" << _atk;

	std::string result = builder.str();
	return result;
}

void Knight::attack(ICharacter* other) {
	other->attackedBy(this);
}

void Knight::attackedBy(Knight* other) {
	int oldHp = _hp;
	int damage = other->_atk;
	int newHp = oldHp - damage;

	_hp = newHp;
}

void Knight::attackedBy(Swordman* other) {
	int oldHp = _hp;
	int damage = other->atk();
	int newHp = oldHp - damage;

	_hp = newHp;
}

// ------------------------------------------

void Swordman::attack(ICharacter* other) {
	other->attackedBy(this);
}

void Swordman::attackedBy(Knight* other) {
	int BONUS_KNIGHT_VS_SWORD = 10;
	int oldHp = _hp;
	int damage = other->atk() + BONUS_KNIGHT_VS_SWORD;
	int newHp = oldHp - damage;

	_hp = newHp;
}

void Swordman::attackedBy(Swordman* other) {
	int oldHp = _hp;
	int damage = other->_atk;
	int newHp = oldHp - damage;

	_hp = newHp;
}
// ============================
int main()
{
	/*std::vector<IHouse*> houses{
		new Resident(),
		new Store(),
		new Resident(),
		new Bank(),
		new Bank(),
	};

	IVisitor* sale = new InsuranceSale();

	for (auto house : houses) {		
		house->accept(sale);
	}*/

	//==================================
	//std::vector<IShape*> shapes = {
	//	new Rectangle(7, 8),
	//	new Rectangle(1, 2),
	//	new Square(3),
	//	new Rectangle(7, 9),
	//	new Triangle(5, 6, 7),
	//	new Triangle(7, 9, 11),
	//};
	//std::string input = "shapes.txt";
	//IDao* writer = new XmlDataProvider();

	//for (auto shape : shapes) {
	//	shape->accept(writer);
	//}
	//std::cout << "Finish writing data to " << input;

	//// TODO: Su dung smart pointer
	//delete writer;
	//============================================

	ICharacter* knight = new Knight();
	ICharacter* sword = new Swordman();

	knight->attack(sword);

	std::cout << knight->toString() << "\n";
	std::cout << sword->toString() << "\n";
}
