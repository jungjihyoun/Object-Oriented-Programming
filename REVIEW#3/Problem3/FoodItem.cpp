#include "FoodItem.h"

void FoodItem::displayItem() const
{
	cout << code << setw(10) << name << setw(10) << price << setw(10) << dueDate << endl;
}


int FoodItem::readItemFromFile(ifstream& _fin)
{
	_fin >> code >> name >> price >> dueDate;

	if (!_fin)
		return 0;

	return 1;
}


int FoodItem::writeItemToFile(ofstream& _fout)
{
	_fout << code << setw(10) << name << setw(10) << price << setw(10) << dueDate << endl;

	return 0;
}