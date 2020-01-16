#pragma once
#include "Item.h"

class FoodItem : public Item
{
private:
	int dueDate;

public:
	void displayItem() const override;
	int readItemFromFile(ifstream& _fin) override;
	int writeItemToFile(ofstream& _fout) override;
};

