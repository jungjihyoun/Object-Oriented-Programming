#include "Triangle.h"

Triangle::Triangle(int _num, double _side1, double _side2, double _side3)
	: Shape(_num), side1(_side1), side2(_side2), side3(_side3) {}

double Triangle::span() const
{
	if (side1 >= side2 && side1 >= side3)
		return side1;
	else if (side2 >= side3)
		return side2;
	else
		return side3;
}

double Triangle::area() const
{
	double s = (side1 + side2 + side3) / 2;

	return s * (s - side1) * (s - side2) * (s - side3);
}

void Triangle::print() const
{
	cout << "[Triangle]" << endl;
	cout << "Span=" << span() << endl;
	cout << "Area=" << area() << endl;
}