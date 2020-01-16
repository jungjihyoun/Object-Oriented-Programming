#pragma once
#include "Shape.h"

class Triangle : public Shape
{
private:
	double side1;
	double side2;
	double side3;
public:
	Triangle();
	Triangle(int _num, double _side1, double _side2, double _side3);
	double span() const override;
	double area() const override;
	void print() const override;
};

