#pragma once
#include<iostream>
#include<math.h>

class Point3D {
private:
	double _x;
	double _y;
	double _z;
public:
	Point3D();
	Point3D(double x, double y, double z);
public:
	double distance(Point3D other);
	void move(double dx, double dy, double dz);
	void rotate();
public:
	double getX() { return _x; }
	double getY() { return _y; }
	double getZ() { return _z; }
	void setX(double val) { _x = val; }
	void setY(double val) { _y = val; }
	void setZ(double val) { _z = val; }
};

Point3D::Point3D() {
	_x = 0;
	_y = 0;
	_z = 0;
}

Point3D::Point3D(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

double Point3D::distance(Point3D other)
{
	return sqrt((_x - other._x) * (_x - other._x) +
		(_y - other._y) * (_y - other._y) +
		(_z - other._z) * (_z - other._z));
}


void Point3D::move(double dx, double dy, double dz)
{
	_x += dx;
	_y += dy;
	_z += dz;
}

void Point3D::rotate() {
	
	double tmp = _x;
	_x = -_y;
	_y = tmp;
}

//void Point3D::rotate()
//{
//	if (_x == 0.0 && _y == 0.0)
//	{
//		return;
//	}
//
//	if (_x > 0)
//	{
//		if (_y == 0)
//		{
//			_y = -_x;
//			_x = 0;
//		}
//		else
//		{
//
//			double tmp = _x;
//			_x = _y;
//			_y = -tmp;
//			return;
//			
//		}
//	}
//	else
//	{
//		if (_y == 0)
//		{
//			_y = -_x;
//			_x = 0;
//			return;
//		}
//		else
//		{
//			double tmp = _x;
//			_x = _y;
//			_y = -tmp;
//			return;
//			
//		}
//
//	}
//}