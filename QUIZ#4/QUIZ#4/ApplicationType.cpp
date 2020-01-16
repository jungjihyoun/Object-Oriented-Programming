#include "ApplicationType.h"

void ApplicationType::run()
{
	string sOption;
	while (1)
	{
		sOption = getCommand();
		if (sOption == "1")			input_item();
		else if (sOption == "2")	displayAllShapes();
		else if (sOption == "3")	break;
	}
	cout << "Exit the program..." << endl;

	for (auto elem : shapes)
		delete elem;
}

string ApplicationType::getCommand()
{
	string com;

	cout << "1. Input Item" << endl;
	cout << "2. Display Items" << endl;
	cout << "3. Quit" << endl;
	cout << "Input>";
	cin >> com;
	
	return com;
}

void ApplicationType::input_item()
{
	Shape* pShape;

	int num;

	cout << "Enter the number of sides( 3: triangle or 4:rectangle ): ";
	cin >> num;

	if (num == 3)
	{
		double side1, side2, side3;
		cout << "Enter three sides: ";
		cin >> side1 >> side2 >> side3;
		pShape = new Triangle(num, side1, side2, side3);
		shapes.push_back(pShape);
		cout << endl;
	}
	else if (num == 4)
	{
		double length, width;
		cout << "Enter width and height: ";
		cin >> width >> length;
		pShape = new Rectangle(num, length, width);
		shapes.push_back(pShape);
		cout << endl;
	}
	else
		cout << "Error : please enter 3 or 4" << endl << endl;
}

void ApplicationType::displayAllShapes()
{
	for (auto elem : shapes)
	{
		elem->print();
		cout << endl;
	}
}