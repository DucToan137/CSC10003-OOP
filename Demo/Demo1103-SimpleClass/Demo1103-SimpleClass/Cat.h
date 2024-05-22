#pragma once


class Cat {
private: // Attributes / Backup field
	float _weight; // primitive
	float _height;
public:
	float weight();
	void setWeight(float value);	

	float height();
	void setHeight(float value);
public:
	Cat(); // No parameters constructor
	Cat(float weight, float height);
	~Cat();
public: // Behaviors / Methods
	void eat();
	void sleep();
	void run();

	void input();
	void output();
};
