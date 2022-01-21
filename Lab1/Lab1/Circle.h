#pragma once
#include<iostream>
using namespace std;

class Circle
{
public:
	Circle();
	Circle(int x_coordinate, int y_coordinate, double r);
	int getX()const;
	int getY()const;
	double getRadius()const;
	void move(int horiz, int vert);
	void setRadius(double r);
	double computeArea();
	void displayCircle();
	bool intersect(Circle c);
private:
	int x;
	int y;
	double radius;
};