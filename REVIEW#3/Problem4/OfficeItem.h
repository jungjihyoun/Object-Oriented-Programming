#pragma once
#include "Item.h"

class OfficeItem : public Item
{
private:
	string company;

public:
	void displayItem() const override;
	int readItemFromFile(ifstream& _fin) override;
	int writeItemToFile(ofstream& _fout) override;
};

