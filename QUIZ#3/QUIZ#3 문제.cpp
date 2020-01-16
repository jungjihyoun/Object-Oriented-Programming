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
	DynamicArray();					// 디폴트 생성자의 MAX_SIZE 1
	DynamicArray(int _max_size);	// _max_size를 MAX_SIZE로 갖는 list를 동적 배열로 설정
	~DynamicArray();				// list의 동적 할당을 해제
	void push_back(int elem);		// 정수 elem을 받아 list의 맨 뒤에 넣어줌
									// 단, 배열의 끝까지 원소가 이미 존재하면 에러 메세지를 출력
	int pop_back();					// 배열의 마지막 원소를 삭제하는 함수로, 원소의 개수(length)를 줄이고 원소를 return 함
									// 단, 삭제할 원소가 없으면 에러 메세지를 출력하고 INT_MIN을 return 함
	int at(int idx);				// 배열의 해당 인덱스의 원소를 return 해줌
									// 단, 입력받은 idx가 음수거나 배열의 사이즈보다 크면 에러 메세지를 출력하고 INT_MIN을 return 함
	int find(int elem) const;		// 입력받은 elem이 배열에 존재하는 지 찾아서 존재하면 해당 원소의 인덱스를 return (중복 생각 X)
									// 원소가 존재하지 않으면 -1을 return
	int size() const;				// length를 return

	friend ostream& operator<<(ostream& cout, const DynamicArray& dAry);	// Array의 모든 원소를 출력
	bool operator==(const DynamicArray& dAry);								// 두 배열이 size부터 각 원소 모두 동일하면 true를 return, 그렇지 않으면 false를 return
	DynamicArray& operator=(const DynamicArray& dAry);						// 기존 배열을 할당 해제하고 입력받은 배열과 동일한 배열로 재할당
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