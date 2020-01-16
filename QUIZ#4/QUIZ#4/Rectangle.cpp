#include "Rectangle.h"

Rectangle::Rectangle(int _num, double _length, double _width)
	: Shape(_num), length(_length), width(_width) {}

double Rectangle::span() const
{
	if (length >= width)
		return length;
	else
		return width;
}

double Rectangle::area() const
{
	return length * width;
}

void Rectangle::print() const
{
	cout << "[Rectangle]" << endl;
	cout << "Span=" << span() << endl;
	cout << "Area=" << area() << endl;
}
