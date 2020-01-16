#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*
정수(num)와 파일명(filename)을 입력 받아
해당 파일에서 입력 정수와 동일한 숫자의 개수(count)를 출력하는 프로그램
*/

void get_num(int& num); //"Enter a number: "를 화면에 출력하고 숫자(num)을 키보드로부터 입력받음
void get_filename(string& filename); //"Enter a file name: "을 화면에 출력하고 문자열(filename)을 키보드로부터 입력받음
void open_file(ifstream& fin, string filename); //filename에 해당하는 파일을 열고, 제대로 열리지 않은 경우
												//"Error: file open failed"를 화면에 출력하고 프로그램 강제종료
void countSameNum(ifstream& fin, int num, int& count); //get_num()으로부터 입력받은 숫자가 파일 내부에 몇 개 존재하는지 count
													   //한 다음 그 값을 pass by reference로 main()에 전달

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