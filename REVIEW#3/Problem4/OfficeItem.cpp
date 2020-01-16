#include "OfficeItem.h"

void OfficeItem::displayItem() const
{
	cout << code << setw(10) << name << setw(10) << price << setw(10) << company << endl;
}


int OfficeItem::readItemFromFile(ifstream& _fin)
{
	_fin >> code >> name >> price >> company;

	if (!_fin)
		return 0;

	return 1;
}


int OfficeItem::writeItemToFile(ofstream& _fout)
{
	_fout << code << setw(10) << name << setw(10) << price << setw(10) << company << endl;

	return 0;
}