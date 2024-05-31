#pragma once


class Line {
private:
	float _x1;
	float _y1;
	float _x2;
	float _y2;
public:
	float X1();
	float Y1();
	float X2();
	float Y2();
	void setX1(float value);
	void setY1(float value);
	void setX2(float value);
	void setY2(float value);
public:
	Line();
public:
	void input();
	void output();
};
