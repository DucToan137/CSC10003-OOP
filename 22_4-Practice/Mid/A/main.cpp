#include<iostream>

class Integer {
private:
	int value;
public:
	Integer();
	Integer(int val);
public:
	int getValue();
	void setValue(int val);
};

Integer::Integer() {
}

Integer::Integer(int val)
{
	value = val;
}

int Integer::getValue()
{
	return value;
}

void Integer::setValue(int val)
{
	value = val;
}


int main() {

	return 0;
}