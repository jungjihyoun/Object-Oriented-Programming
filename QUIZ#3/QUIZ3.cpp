#include<iostream>
#include<iomanip>
using namespace std;

class DynamicArray
{
private:
	int MAX_SIZE;
	int length;
	int* list;

public:
	DynamicArray() : MAX_SIZE(1), length(0), list(new int[1]) {}
	DynamicArray(int _max_size) : MAX_SIZE(_max_size), length(0), list(new int[_max_size]) {}
	~DynamicArray() { delete[] list; }
	void push_back(int elem)
	{
		if (length == MAX_SIZE)
			cout << "Error: size overflow" << endl;
		else
		{
			list[length] = elem;
			length++;
		}
	}
	int pop_back()
	{
		if (length == 0)
		{
			cout << "Error: empty list" << endl;
			return INT_MIN;
		}
		else
		{
			length--;
			return list[length];
		}
	}
	int at(int idx)
	{
		if (idx < 0 || idx >= length)
		{
			cout << "Error: invalid index" << endl;
			return INT_MIN;
		}
		else
			return list[idx];
	}
	int find(int elem) const
	{
		for (int i = 0; i < length; i++)
		{
			if (list[i] == elem)
				return i;
		}

		return -1;
	}
	int size() const
	{
		return length;
	}
	friend ostream& operator<<(ostream& cout, const DynamicArray& dAry);
	bool operator==(const DynamicArray& dAry)
	{
		if (this->size() != dAry.size())
			return false;
		else
		{
			for (int i = 0; i < this->size(); i++)
			{
				if (this->list[i] != dAry.list[i])
					return false;
			}
		}

		return true;
	}
	DynamicArray& operator=(const DynamicArray& dAry)
	{
		this->~DynamicArray();
		this->MAX_SIZE = dAry.MAX_SIZE;
		this->list = new int[MAX_SIZE];

		while (this->size() != 0)
		{
			this->pop_back();
		}

		for (int i = 0; i < dAry.size(); i++)
		{
			this->push_back(dAry.list[i]);
		}

		return *this;
	}
};

ostream& operator<<(ostream& cout, const DynamicArray& dAry)
{
	for (int i = 0; i < dAry.size(); i++)
	{
		cout << setw(4) << dAry.list[i];
	}

	return cout;
}

int main()
{
	DynamicArray dAry1;
	dAry1.push_back(10);
	dAry1.push_back(20);
	cout << "1: [" << dAry1 << "]" << endl;
	cout << "2: " << dAry1.pop_back() << endl;
	cout << "3: " << dAry1.pop_back() << endl << endl;
	dAry1.push_back(10);

	DynamicArray dAry2(100);
	dAry2.push_back(10);
	dAry2.push_back(20);
	dAry2.push_back(30);
	dAry2.push_back(40);

	cout << "4: " << dAry2.at(2) << endl;
	cout << "5: " << dAry2.find(2) << endl;
	cout << "6: " << dAry2.size() << endl;

	cout << "7: [" << dAry2 << "]" << endl;
	cout << "8: (dAry1 == dAry2): " << (dAry1 == dAry2) << endl;
	dAry1 = dAry2;
	cout << "9: (dAry1 == dAry2): " << (dAry1 == dAry2) << endl;

	return 0;
}