#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	double length;
	double width;
public:
	Rectangle(int _num, double _length, double _width);
	double span() const override;
	double area() const override;
	void print() const override;
};

