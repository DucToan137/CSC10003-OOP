#include<iostream>
#include<string>
#include<sstream>

using namespace std;


class Soldier;
class Swordsman;
class Knight;
class Pikeman;
class IAttackable;


// Chỗ cấu hình. Nếu sau này thêm 1 class mới thì chỉ cần cấu hình tại đây
class IAttackable {
public:
	virtual void hitBy(Swordsman*) = 0;
	virtual void hitBy(Knight*) = 0;
	virtual void hitBy(Pikeman*) = 0;
};

class Soldier {
protected:
	int _hp;
	int _atk;
public:
	virtual string toString() = 0;

	virtual void attack(Soldier*) = 0; // visit
	//virtual void hitBy(Soldier*) = 0; // visited by
public:
	int hp() {
		return _hp;
	}

	int atk() {
		return _atk;
	}

	void setHp(int hp) {
		_hp = hp;
	}

	bool isAlive() {
		return _hp > 0;
	}
};

class Swordsman : public Soldier, IAttackable {
public:
	void attack(Soldier* opponent);
	//void hitBy(Soldier* opponent);

	//void attack(Swordsman*);
	void hitBy(Swordsman*);
	//void attack(Knight*);
	void hitBy(Knight*);
	//void attack(Pikeman*);
	void hitBy(Pikeman*);


	Swordsman() {
		_hp = 1000;
		_atk = 12;
	}

	string toString() {
		stringstream builder;

		builder << "Swordsman: HP=" << _hp;
		builder << ", ATK=" << _atk;

		string result = builder.str();
		return result;
	}
};

class Knight :public Soldier, IAttackable {
public:
	void attack(Soldier* opponent);
	//void hitBy(Soldier*);

	//void attack(Swordsman*);
	void hitBy(Swordsman*);
	//void attack(Knight*);
	void hitBy(Knight*);
	//void attack(Pikeman*);
	void hitBy(Pikeman*);


	Knight() {
		_hp = 1500;
		_atk = 18;
	}

	string toString() {
		stringstream builder;

		builder << "Knight: HP=" << _hp;
		builder << ", ATK=" << _atk;

		string result = builder.str();
		return result;
	}
};

class Pikeman :public Soldier, IAttackable {
public:
	Pikeman() {
		_hp = 800;
		_atk = 8;
	}

	//void attack(Swordsman*);
	void hitBy(Swordsman*);
	//void attack(Knight*);
	void hitBy(Knight*);
	//void attack(Pikeman*);
	void hitBy(Pikeman*);


	string toString() {
		stringstream builder;

		builder << "Pikeman: HP=" << _hp;
		builder << ", ATK=" << _atk;

		string result = builder.str();
		return result;
	}

	void attack(Soldier* opponent);
	//void hitBy(Soldier* opponent);
};

/////////////Swordman//////////////////////



void Swordsman::attack(Soldier* opponent) {

	// Bên bị tấn công sẽ mất máu
	// Sau đó bị đánh lại

	// typeid
	// không nên làm cách này // TellDon'tAsk
	//if (typeid(Swordsman) == typeid(*opponent)) {
	//	// Đối thủ mất máu trước
	//	int oldHp = opponent->hp();
	//	int newHp = oldHp - this->_atk;
	//	opponent->setHp(newHp);
	//	

	//	// Đối thủ cay cú, bem lại mình
	//	if (opponent->isAlive()) {
	//		newHp = this->_hp - opponent->atk();
	//		this->_hp = newHp;
	//	}
	//}
	//else if (typeid(Knight) == typeid(*opponent)) {
	//	// Đối thủ mất máu trước
	//	int oldHp = opponent->hp();
	//	int newHp = oldHp - this->_atk;
	//	opponent->setHp(newHp);

	//	// Đối thủ cay cú, bem lại mình
	//	if (opponent->isAlive()) {
	//		newHp = this->_hp - (opponent->atk() + 10);
	//		this->_hp = newHp;
	//	}
	//}

	// dynamic_cast
	//Swordsman* temp = dynamic_cast<Swordsman*>(opponent);
	//if (temp != nullptr) {
	//	// do something
	//}
	//else {
	//	Knight * temp2 = dynamic_cast<Knight*>(opponent);
	//}

	// typeid / dynamic_cast 
	if (typeid(Swordsman) == typeid(*opponent)) {
		((Swordsman*)opponent)->hitBy((Swordsman*)this);

		if (opponent->isAlive()) {
			this->hitBy((Swordsman*)opponent);
		}
	}
	else if (typeid(Knight)== typeid(*opponent)){
		((Knight*)opponent)->hitBy((Swordsman*)this);

		if(opponent->isAlive()) {
			this->hitBy((Knight*)opponent);
		}
	}
	else if (typeid(Pikeman) == typeid(*opponent)) {
		((Pikeman*)opponent)->hitBy((Swordsman*)this);

		if (opponent->isAlive()) {
			this->hitBy((Pikeman*)opponent);
		}
	}

}

void Swordsman::hitBy(Swordsman* opponent) {
	
	_hp = _hp - opponent->atk();

}

void Swordsman::hitBy(Knight* opponent) {
	
	_hp = _hp - (opponent->atk() + 10);

}

void Swordsman::hitBy(Pikeman* opponent) {
	
	_hp = _hp - opponent->atk();

}

//void Swordsman::hitBy(Soldier* opponent) {
//	int oldHp = _hp;
//	int newHp = _hp;
//
//	if (typeid(Swordsman) == typeid(*opponent)) {
//		newHp = oldHp - opponent->atk();
//	}
//	else if (typeid(Knight) == typeid(*opponent)) {
//		newHp = oldHp - (opponent->atk() + 10);
//	}
//
//	_hp = newHp;
//
//	// Swordsman* temp = dynamic_cast<Swordsman*>(opponent);
//
//}


/////////////Knight//////////////////////


void Knight::attack(Soldier* opponent) {

	if (typeid(Swordsman) == typeid(*opponent)) {
		((Swordsman*)opponent)->hitBy((Knight*)this);

		if (opponent->isAlive()) {
			this->hitBy((Swordsman*)opponent);
		}
	}
	else if (typeid(Knight) == typeid(*opponent)) {
		((Knight*)opponent)->hitBy((Knight*)this);

		if (opponent->isAlive()) {
			this->hitBy((Knight*)opponent);
		}
	}
	else if (typeid(Pikeman) == typeid(*opponent)) {
		((Pikeman*)opponent)->hitBy((Knight*)this);

		if (opponent->isAlive()) {
			this->hitBy((Pikeman*)opponent);
		}
	}

}

void Knight::hitBy(Swordsman* opponent) {
	_hp = _hp - opponent->atk();
}

void Knight::hitBy(Knight* opponent) {
	_hp = _hp - opponent->atk();
}

void Knight::hitBy(Pikeman* opponent) {
	_hp = _hp - (opponent->atk() + 25);
}

//void Knight::hitBy(Soldier* opponent) {
//	int oldHp = _hp;
//	int newHp = _hp;
//
//	if (typeid(Swordsman) == typeid(*opponent)) {
//		newHp = oldHp - opponent->atk();
//	}
//	else if (typeid(Knight) == typeid(*opponent)) {
//		newHp = oldHp - opponent->atk();
//	}
//
//	_hp = newHp;
//}



/////////////Pikeman//////////////////////


void Pikeman::attack(Soldier* opponent) {

	if (typeid(Swordsman) == typeid(*opponent)) {
		((Swordsman*)opponent)->hitBy((Pikeman*)this);

		if (opponent->isAlive()) {
			this->hitBy((Swordsman*)opponent);
		}
	}
	else if (typeid(Knight) == typeid(*opponent)) {
		((Knight*)opponent)->hitBy((Pikeman*)this);

		if (opponent->isAlive()) {
			this->hitBy((Knight*)opponent);
		}
	}
	else if (typeid(Pikeman) == typeid(*opponent)) {
		((Pikeman*)opponent)->hitBy((Pikeman*)this);

		if (opponent->isAlive()) {
			this->hitBy((Pikeman*)opponent);
		}
	}

}

void Pikeman::hitBy(Swordsman* opponent) {
	_hp = _hp - (opponent->atk() + 12);
}

void Pikeman::hitBy(Knight* opponent) {
	_hp = _hp - opponent->atk();
}

void Pikeman::hitBy(Pikeman* opponent) {
	_hp = _hp - opponent->atk();
}


//void Pikeman::hitBy(Soldier* opponent) {
//	int oldHp = _hp;
//	int newHp = _hp;
//
//	if (typeid(Swordsman) == typeid(*opponent)) {
//		newHp = oldHp - (opponent->atk() + 12);
//	}
//	else if (typeid(Knight) == typeid(*opponent)) {
//		newHp = oldHp - (opponent->atk() + 5);
//	}
//	else if(typeid(Pikeman) == typeid(*opponent)) {
//		newHp = oldHp - opponent->atk();
//	}
//
//	_hp = newHp;
//}




int main() {

	Soldier * sword1 = new Swordsman();
	Soldier * sword2 = new Swordsman();
	Soldier * knight = new Knight();
	Soldier * pike = new Pikeman();



	knight->attack(sword1);
	knight->attack(sword2);
	knight->attack(pike);

	cout << sword1->toString() << endl;
	cout << sword2->toString() << endl;
	cout << knight->toString() << endl;
	cout << pike->toString() << endl;

	return 0;
}