#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class VectorList
{
	vector<double*> vItem;
	vector<int> vLength;

public:
	~VectorList()
	{
		for (double* elem : vItem)
			delete[] elem;
	}
	void append(double* _pArray, int _length)
	{
		vItem.push_back(_pArray);
		vLength.push_back(_length);
	}
	int findVector(double* _pArray, int _length)
	{
		int index = 0;
		for (double* elem : vItem)
		{
			int count = 0;
			for (int i = 0; i < _length; i++)
			{
				if (_pArray[i] == elem[i])
					count++;
			}
			if (count == _length)
				return index;
			index++;
		}

		return -1;
	}
	void print_single_vector(int idx)
	{
		if (idx < 0 || idx > vItem.size())
			cout << "[Wrong index]" << endl;
		else
		{
			cout << idx << "-th vector:";
			int length = vLength[idx];
			for (int i = 0; i < length; i++)
				cout << setw(10) << vItem[idx][i];
			cout << endl;
		}
	}
	void print_all_vectors()
	{
		int count = 0;
		for (double* elem : vItem)
		{
			print_single_vector(count);
			count++;
		}
	}	
};

int main()
{
	VectorList vectorList;
	double* pTemp = new double[3]{ 1.1, 2.2, 3.3 };
	vectorList.append(pTemp, 3);

	pTemp = new double[5]{ 10.1, 10.2, 10.3, 10.4, 10.5 };
	vectorList.append(pTemp, 5);

	pTemp = new double[2]{ 4.5, 5.5 };
	vectorList.append(pTemp, 2);

	vectorList.print_single_vector(-1);
	vectorList.print_single_vector(0);
	cout << endl;

	vectorList.print_all_vectors();
	cout << endl;

	double* pTemp1 = new double[2]{ 4.5, 5.5 };
	double* pTemp2 = new double[4]{ 1.1, 2.2, 5.5, 4.4 };

	cout << "Index of vector{4.5, 5.5} :" << vectorList.findVector(pTemp1, 2) << endl;
	cout << "Index of vector{1.1, 2.2, 5.5, 4.4} :" << vectorList.findVector(pTemp2, 4) << endl;

	delete[] pTemp1;
	delete[] pTemp2;

	return 0;
}