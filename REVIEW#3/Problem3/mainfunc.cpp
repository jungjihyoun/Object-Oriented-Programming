#include "FoodItem.h"
#include "OfficeItem.h"

int main()
{
	vector<Item*> vItem;
	Item* pItem = new FoodItem;

	ifstream fin;
	fin.open("foodItem.txt");

	while (pItem->readItemFromFile(fin))
	{
		vItem.push_back(pItem);
		pItem = new FoodItem;
	}
	fin.close();

	pItem = new OfficeItem;

	fin.open("officeItem.txt");

	while(pItem->readItemFromFile(fin))
	{
		vItem.push_back(pItem);
		pItem = new OfficeItem;
	}
	fin.close();

	for (auto elem : vItem)
		elem->displayItem();

	delete pItem;

	return 0;
}