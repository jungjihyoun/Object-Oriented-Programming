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
		cout << "파일 열기 에러" << endl;
		exit(EXIT_FAILURE);
	}

	while (temp.readItemFromFile(fin))
		vItem.push_back(temp);

	fin.close();

	temp.setItem("E1002", "박카스", 1000);
	vItem.push_back(temp);

	ofstream fout;
	fout.open(outFleName);

	for (auto elem : vItem)
		elem.writeItemToFIle(fout);

	fout.close();

	return 0;
}