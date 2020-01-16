#include "Item.h"

int main()
{
	Item temp;
	vector<Item> vItem;
	string inFleName = "item.txt";
	string outFleName = "item_output.txt";

	ifstream fin;
	fin.open(inFleName);
	if (!fin)
	{
		cout << "���� ���� ����" << endl;
		exit(EXIT_FAILURE);
	}

	while (temp.readItemFromFile(fin))
		vItem.push_back(temp);

	fin.close();

	temp.setItem("E1002", "��ī��", 1000);
	vItem.push_back(temp);

	ofstream fout;
	fout.open(outFleName);

	for (auto elem : vItem)
		elem.writeItemToFIle(fout);

	fout.close();

	return 0;
}