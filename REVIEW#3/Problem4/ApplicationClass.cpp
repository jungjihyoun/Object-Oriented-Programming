#include "ApplicationClass.h"

ApplicationClass::ApplicationClass(string food_name, string office_name) : officeItemFileName(office_name), foodItemFileName(food_name)
{
	ifstream fin;
	fin.open(foodItemFileName);

	Item* pItem = new FoodItem;

	while (pItem->readItemFromFile(fin))
	{
		vItem.push_back(pItem);
		pItem = new FoodItem;
	}

	fin.close();

	fin.open(officeItemFileName);

	pItem = new OfficeItem;

	while (pItem->readItemFromFile(fin))
	{
		vItem.push_back(pItem);
		pItem = new OfficeItem;
	}

	delete pItem;

	fin.close();
}

void ApplicationClass::run()
{
	string sOption;
	while (1)
	{
		sOption = getCommand();
		if (sOption == "1")			displayAllItems();
		else if (sOption == "2")	displayFoodItems();
		else if (sOption == "3")	displayOfficeItems();
		else if (sOption == "4")	searchItemByCode();
		else if (sOption == "5")	break;
	}
	cout << "Exit the program..." << endl;
}

string ApplicationClass::getCommand()
{
	string command;
	cout << "1. Display all items." << endl;
	cout << "2. Display food items." << endl;
	cout << "3. DIsplay office items." << endl;
	cout << "4. Search item by code." << endl;
	cout << "5. Quit." << endl;
	cout << "Input>";
	cin >> command;

	return command;
}

void ApplicationClass::displayAllItems()
{
	for (auto elem : vItem)
		elem->displayItem();
}

void ApplicationClass::displayFoodItems()
{
	for (auto elem : vItem)
	{
		if (elem->getCode().find("F") != string::npos)
			elem->displayItem();
	}
}

void ApplicationClass::displayOfficeItems()
{
	for (auto elem : vItem)
	{
		if (elem->getCode().find("C") != string::npos)
			elem->displayItem();
	}
}

void ApplicationClass::searchItemByCode()
{
	string search_code;
	bool found = false;

	cout << "Enter the code: ";
	cin >> search_code;

	for (auto elem : vItem)
	{
		if (elem->getCode() == search_code)
		{
			elem->displayItem();
			found = true;
		}
	}

	if (!found)
		cout << "No items found" << endl;
}