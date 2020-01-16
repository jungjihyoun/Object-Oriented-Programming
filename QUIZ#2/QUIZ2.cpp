#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

double** get_matrix(int& row, int& col);
void free_matrix(double** mat, int row, int col);
double** mult_matrix(double** mat1, double** mat2, int row1, int col1, int row2, int col2);
void save_matrix(string filename, string name_matrix, double** mat, int row, int col);

int main()
{
	int nRow1, nCol1, nRow2, nCol2;
	string filename = "mat_mult_result.txt";
	double** mat1 = get_matrix(nRow1, nCol1);
	double** mat2 = get_matrix(nRow2, nCol2);
	double** mat3 = mult_matrix(mat1, mat2, nRow1, nCol1, nRow2, nCol2);

	save_matrix(filename, "(input01)", mat1, nRow1, nCol1);
	save_matrix(filename, "(input02)", mat2, nRow2, nCol2);
	save_matrix(filename, "(output01)", mat3, nRow1, nCol2);

	free_matrix(mat1, nRow1, nCol1);
	free_matrix(mat2, nRow2, nCol2);
	free_matrix(mat3, nRow1, nCol2);

	return 0;
}

double** get_matrix(int& row, int& col)
{
	row = 0, col = 0;

	while (row < 1 || col < 1)
	{
		cout << "Enter nRow and nCol in (nRow x nCol)" << endl << ">>";
		cin >> row >> col;
	}

	double** matrix = new double* [row];
	for (int i = 0; i < row; i++)
		matrix[i] = new double[col];

	cout << "Enter elements" << endl << ">>";

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> matrix[i][j];

	cout << endl;

	return matrix;
}

void free_matrix(double** mat, int row, int col)
{
	for (int i = 0; i < row; i++)
		delete[] mat[i];
	delete[] mat;
}

double** mult_matrix(double** mat1, double** mat2, int row1, int col1, int row2, int col2)
{
	if (col1 != row2)
	{
		cout << "Error: dimension mismatch" << endl;
		exit(100);
	}

	double** mat3 = new double* [row1];
	for (int i = 0; i < row1; i++)
		mat3[i] = new double [col2];

	for (int i = 0; i < row1; i++)
		for (int j = 0; j < col2; j++)
			mat3[i][j] = 0;

	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			for (int k = 0; k < col1; k++)
			{
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

	return mat3;
}

void save_matrix(string filename, string name_matrix, double** mat, int row, int col)
{
	ofstream fout;
	fout.open(filename, ios::app);

	fout << name_matrix << endl;
	fout << setw(8) << row << setw(8) << col << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			fout.precision(4);
			fout << setw(8) << mat[i][j];
		}
		fout << endl;
	}

	fout.close();

	cout << name_matrix << " is save in " << filename << endl;
}