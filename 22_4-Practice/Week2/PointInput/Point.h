#pragma once

class Point {
private:
	float _x;
	float _y;
public:
	float X();
	float Y();
	void setX(float value);
	void setY(float value);
public:
	Point();
public:
	void input();
	void output();
};
