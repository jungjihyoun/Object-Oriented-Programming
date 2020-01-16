#pragma once
#include "FoodItem.h"
#include "OfficeItem.h"

class ApplicationClass
{
private:
	vector<Item*> vItem;
	string officeItemFileName;
	string foodItemFileName;

public:
	ApplicationClass(string food_name, string office_name);
	void run();

	string getCommand();
	void displayAllItems();
	void displayFoodItems();
	void displayOfficeItems();
	void searchItemByCode();
};

