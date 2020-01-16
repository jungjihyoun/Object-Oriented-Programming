#include<iostream>
#include<list>
#include<string>
#include<iomanip>
using namespace std;

list<int> get_elements(int num)
{
	list<int> result(num);

	for (auto iter = begin(result); iter != end(result); iter++)
		* iter = rand() % 101;

	return result;
}

void get_command(string& command)
{
	do
	{
		cout << "\n1. Print" << endl;
		cout << "2. Find Number" << endl;
		cout << "3. Sort" << endl;
		cout << "0. Exit" << endl;
		cout << "Input>> ";
		cin >> command;
	} while (command != "1" && command != "2" && command != "3" && command != "0");
}

template<class Iter>
void print(Iter iter_begin, Iter iter_end)
{
	int count = 0;
	for (auto iter = iter_begin; iter != iter_end; iter++)
	{
		cout << setw(4) << *iter;
		count++;
		if (count % 10 == 0)
			cout << endl;
	}
}

template<class Iter>
void count_val(Iter iter_begin, Iter iter_end)
{
	auto number = *iter_begin;
	int count = 0;
	cout << "Enter the Key: ";
	cin >> number;

	for (auto iter = iter_begin; iter != iter_end; iter++)
		if (*iter == number)
			count++;

	cout << "Number of matching elements: " << count << endl;
}

template<class Iter>
void sort(Iter iter_begin, Iter iter_end)
{
	for (auto iter1 = iter_begin; iter1 != iter_end; iter1++)
	{
		Iter min_iter = iter1;
		auto min = *iter1;

		for (auto iter2 = iter1; iter2 != iter_end; iter2++)
		{
			if (*iter2 <= min)
			{
				min_iter = iter2;
				min = *iter2;
			}
		}

		auto TEMP = *iter1;
		*iter1 = *min_iter;
		*min_iter = TEMP;
	}
}

int main()
{
	list<int> myList = get_elements(100);
	string command;
	while (1)
	{
		get_command(command);
		if (command == "1")			print(begin(myList), end(myList));
		else if (command == "2")	count_val(begin(myList), end(myList));
		else if (command == "3")	sort(begin(myList), end(myList));
		else if (command == "0")	break;
	}
	cout << "Exit program.." << endl;
	return 0;
}