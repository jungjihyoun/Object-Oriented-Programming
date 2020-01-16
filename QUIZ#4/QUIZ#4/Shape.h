#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Shape
{
protected:
	int numSides;
public:
	Shape(int _num) : numSides(_num) {}
	virtual double span() const = 0;
	virtual double area() const = 0;
	virtual void print() const = 0;
};

