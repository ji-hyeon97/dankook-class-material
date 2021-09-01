/* 
���� ���� ȣ�� : Call by Value��� �Ҹ����, ���ڷ� �ѱ�� ���� �����ؼ� ���ο� �Լ��� �Ѱ��ִ�
������� ���� ���翡 ���� �Լ� ȣ���� �ǹ��մϴ�.

#include<iostream>

using namespace std;

void swap(int a, int b);

int main() {
	int val1 = 10;
	int val2 = 20;
	swap(val1, val2);

	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;

	return 0;
}

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
}

���� ������ Call by Value ������ ������Դϴ�. Call by Value�� ���� �����ؼ� �����ϱ� ������ ������
���� ����� ���ɼ��� ���ٴ� Ư¡�� ������ ������, ���� �Ѱ� �ٶ����� ����, ����ս� ������ �߻��ϴ�
������ �ֽ��ϴ�.
Call by Value�� Pass by Value��� �Ҹ��⵵ �մϴ�.
*/


//������ ���� ȣ�� : Call by Reference��� �θ���, �ּ� ���� ���ڷ� �����ϴ� �Լ� ȣ���� ���մϴ�.

#include<iostream>
using namespace std;

void swap(int *a, int *b);

int main() {
	int val1 = 10;
	int val2 = 20;

	cout << "Before the swap function" << endl;
	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;

	swap(&val1, &val2);

	cout << endl << "After Swap function" << endl;
	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;

	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//���� �������� �� �� �ֵ��� Call by Reference�� ����սǰ� ���� ���������� �������, ������ ���� ������ �Ͼ�
//�� �� �ִ� �ߴ��� �������� �Ȱ� �ִ� �� �� �� �ֽ��ϴ�.
