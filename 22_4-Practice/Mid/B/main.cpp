#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>

class Point {
private:
	float _x;
	float _y;
public:
	Point();
	Point(float x, float y);
	void displayCoordinates();
	float distanceTo(const Point& other);
};

Point::Point() {
	_x = 0;
	_y = 0;
}

Point::Point(float x, float y)
{
	_x = x;
	_y = y;
}

void Point::displayCoordinates()
{
	std::cout << "(" << std::fixed << std::setprecision(1) <<  _x << ", " << std::fixed << std::setprecision(1) << _y << ")";
}

float Point::distanceTo(const Point& other)
{
	float result;

	result = sqrt((other._x - _x) * (other._x - _x) + (other._y - _y) * (other._y - _y));


	return result;
}

class PointManager {
private:
	std::vector<Point> points;
public:
	void addPoint(const Point& point);
	void removePoint(int index);
	void displayAllPoints();
	float totalDistance();
};

void PointManager::addPoint(const Point& point)
{
	points.push_back(point);
}

void PointManager::removePoint(int index)
{
	points.erase(points.begin() + index);
}

void PointManager::displayAllPoints()
{
	std::cout << "All points: \n";
	for (int i = 0; i < points.size(); i++)
	{
		if (i == 0)
		{
			std::cout << "Point " << i <<": ";
			points[i].displayCoordinates();
			std::cout << "\n";
		}
		else if(i==points.size()-1)
		{
			std::cout << "==========\n";
			std::cout << "Point " << i <<": ";
			points[i].displayCoordinates();
		}
		else
		{
			std::cout << "==========\n";
			std::cout << "Point " << i << ": ";
			points[i].displayCoordinates();
			std::cout << "\n";
		}
	}
}


float PointManager::totalDistance()
{
	float result = 0;
	Point a;
	for (int i = 0; i < points.size(); i++)
	{
		for (int j = 0; j < points.size(); j++)
		{
			result += points[i].distanceTo(points[j]);
		}
	}

	return result;
}


int main() {

	/*PointManager e;
	Point a(1.5, 2.5);
	Point b(-3.5, 4.2);
	Point c(0, 0);
	Point d(-2.8, -1.3);

	e.addPoint(a);
	e.addPoint(b);
	e.addPoint(c);
	e.addPoint(d);

	e.displayAllPoints();*/

	return 0;
}

