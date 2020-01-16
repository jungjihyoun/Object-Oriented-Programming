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
	DynamicArray();					// ����Ʈ �������� MAX_SIZE 1
	DynamicArray(int _max_size);	// _max_size�� MAX_SIZE�� ���� list�� ���� �迭�� ����
	~DynamicArray();				// list�� ���� �Ҵ��� ����
	void push_back(int elem);		// ���� elem�� �޾� list�� �� �ڿ� �־���
									// ��, �迭�� ������ ���Ұ� �̹� �����ϸ� ���� �޼����� ���
	int pop_back();					// �迭�� ������ ���Ҹ� �����ϴ� �Լ���, ������ ����(length)�� ���̰� ���Ҹ� return ��
									// ��, ������ ���Ұ� ������ ���� �޼����� ����ϰ� INT_MIN�� return ��
	int at(int idx);				// �迭�� �ش� �ε����� ���Ҹ� return ����
									// ��, �Է¹��� idx�� �����ų� �迭�� ������� ũ�� ���� �޼����� ����ϰ� INT_MIN�� return ��
	int find(int elem) const;		// �Է¹��� elem�� �迭�� �����ϴ� �� ã�Ƽ� �����ϸ� �ش� ������ �ε����� return (�ߺ� ���� X)
									// ���Ұ� �������� ������ -1�� return
	int size() const;				// length�� return

	friend ostream& operator<<(ostream& cout, const DynamicArray& dAry);	// Array�� ��� ���Ҹ� ���
	bool operator==(const DynamicArray& dAry);								// �� �迭�� size���� �� ���� ��� �����ϸ� true�� return, �׷��� ������ false�� return
	DynamicArray& operator=(const DynamicArray& dAry);						// ���� �迭�� �Ҵ� �����ϰ� �Է¹��� �迭�� ������ �迭�� ���Ҵ�
};

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