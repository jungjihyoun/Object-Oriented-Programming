#pragma once
#include "Rectangle.h"
#include "Triangle.h"

class ApplicationType
{
private:
	vector<Shape*> shapes;
public:
	void run();
	string getCommand();
	void input_item();
	void displayAllShapes();
};

