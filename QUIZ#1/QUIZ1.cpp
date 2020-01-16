#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*
����(num)�� ���ϸ�(filename)�� �Է� �޾�
�ش� ���Ͽ��� �Է� ������ ������ ������ ����(count)�� ����ϴ� ���α׷�
*/

void get_num(int& num); //"Enter a number: "�� ȭ�鿡 ����ϰ� ����(num)�� Ű����κ��� �Է¹���
void get_filename(string& filename); //"Enter a file name: "�� ȭ�鿡 ����ϰ� ���ڿ�(filename)�� Ű����κ��� �Է¹���
void open_file(ifstream& fin, string filename); //filename�� �ش��ϴ� ������ ����, ����� ������ ���� ���
												//"Error: file open failed"�� ȭ�鿡 ����ϰ� ���α׷� ��������
void countSameNum(ifstream& fin, int num, int& count); //get_num()���κ��� �Է¹��� ���ڰ� ���� ���ο� �� �� �����ϴ��� count
													   //�� ���� �� ���� pass by reference�� main()�� ����

int main()
{
	int num, count;
	string filename;
	ifstream fin;
	ofstream fout;

	get_filename(filename);
	get_num(num);
	open_file(fin, filename);
	countSameNum(fin, num, count);

	cout << "Output: " << count << endl;

	fin.close();
	return 0;
}

void get_num(int& num)
{
	cout << "Enter a number: ";
	cin >> num;
}

void get_filename(string& filename)
{
	cout << "Enter a file name: ";
	cin >> filename;
}

void open_file(ifstream& fin, string filename)
{
	fin.open(filename);
	if (!fin)
	{
		cout << "Error: file open failed" << endl;
		exit(100);
	}
}

void countSameNum(ifstream& fin, int num, int& count)
{
	int x;
	count = 0;

	while (fin >> x)
	{
		if (x == num)
			count++;
	}
}