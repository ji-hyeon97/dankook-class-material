#include<iostream>

using namespace std;

class myClass {
public:
	void PrintThis() {
		cout << "���� �ּҴ� " << this << endl;
	}
};

int main() {
	myClass a, b;

	cout << "a�� �ּҴ� " << &a << endl;
	cout << "b�� �ּҴ� " << &b << endl;

	a.PrintThis();
	b.PrintThis();
}
//this�����Ͷ�� �Ű������� ����
//this�� ������ �ʴ� �Ű������̴�
//PrintThis()�Լ��� ��ü a,b�� ���� �޸𸮿����� �ƴ�����
//this��� �����͸� �Ű������� �޾� PrintThis()�Լ��� ��� ��ü �Ҽ����� �� �� �ִ� 