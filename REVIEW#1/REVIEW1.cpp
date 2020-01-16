#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

void get_command(string& command)
{
	cout << "1. Generate matrix" << endl;
	cout << "2. Print matrix" << endl;
	cout << "3. Sort matrix" << endl;
	cout << "4. Save matrix" << endl;
	cout << "0. Exit program" << endl;
	cout << ">>";
	cin >> command;
}

void get_size(int& size)
{
	cout << "Enter the size in (size x size): ";
	cin >> size;
	cout << endl;
}

int** gen_matrix(int size)
{
	int** matrix = new int* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = rand() % 101;

	return matrix;
}

void swap(int* a, int* b)
{
	int* TEMP = a;
	a = b;
	b = TEMP;
}

void sort_array(int* ary, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (ary[j] < ary[j - 1])
			{
				swap(ary[j], ary[j - 1]);
			}
		}
	}
}

void sort_matrix_row(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		sort_array(matrix[i], size);
	}

	cout << "Completed" << endl << endl;
}

void print_matrix(int** matrix, int size)
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
			cout << setw(4) << matrix[row][col];
		cout << endl;
	}
	cout << endl;
}

void save_matrix(int** matrix, int size)
{
	ofstream fout;
	fout.open("matrix.txt");
	fout << size << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			fout << setw(4) << matrix[i][j];
		fout << endl;
	}
	cout << "Saved" << endl << endl;
	fout.close();
}

void free_matrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
		delete[] matrix[i];

	delete[] matrix;
}

int main()
{
	string command;
	int** matrix = NULL;
	int size = 0;
	while (1)
	{
		get_command(command);
		if (command == "1")
		{
			get_size(size);
			matrix = gen_matrix(size);
		}
		else if (command == "2")
		{
			print_matrix(matrix, size);
		}
		else if (command == "3")
		{
			sort_matrix_row(matrix, size);
		}
		else if (command == "4")
		{
			save_matrix(matrix, size);
		}
		else if (command == "0")
		{
			free_matrix(matrix, size);
			cout << "Exit the program.." << endl;
			exit(104);
		}
		else
		{
			cout << "Wrong command" << endl << endl;
		}
	}

	return 0;
}