#pragma once
#include"Circle.h"
#include<math.h>
const int pai = 3.14;
Circle::Circle()
{
	x = 0;
	y = 0;
	radius = 10;
}
Circle::Circle(int x_coordinate, int y_coordinate, double r)
{
	x = x_coordinate;
	y = y_coordinate;
	radius = r;
}
int Circle::getX()const
{
	return x;
}
int Circle::getY()const
{
	return y;
}
double Circle::getRadius()const
{
	return radius;
}
void Circle::move(int horiz, int vert)
{
	x = horiz;
	y = vert;
}
void Circle::setRadius(double r)
{
	if (r > 0)
		radius = r;
	else
		radius = 10.0;
}
double Circle::computeArea()
{
	double area;
	area = pai * radius * radius;
	return area;
}
void Circle::displayCircle()
{
	cout << "Radius " << radius << " at point x = 12, y = 17" << endl;
}
bool Circle::intersect(Circle c)
{
	double distance;
	distance = sqrt((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y));
	if (distance < (c.getRadius() + radius))
		return true;
	else
		return false;
}