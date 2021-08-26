#include<iostream>

using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a(10); //int a=10; �ʱ�ȭ
	int b(a+5);

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;

	//������� for��
	int arr[10] = { 3,1,4,1,5,9,2,6,5,3 };
	for (int i = 0; i < 10; i++) {
		cout << arr[i]<<" ";
	}
	cout << endl;

	//reference ����
	for (int &n : arr) {
		cout << n << " ";
		n++;//�޸𸮻� n, arr�� ���� ���� �Ҵ�Ǿ� �ֱ� ������ �۵�X
	}
	cout << endl;

	for (int n : arr) {
		cout << n << " ";
		n++;		
	}
	cout << endl;

	//reference ����
	int c(5);
	int &p = c;
	p = 10;
	cout << c << endl;
	cout << p << endl;

	//swap
	int d(5);
	int e(7);
	swap(d, e);
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;

	// r-value �����Ҽ� ���� ��
	int f(5);
	int &r1 = f;
	int &&r2 = 3;//�޸𸮿� ����� ��X. ����� ������ �� ���� ��
	int &&r3 = f * f;//�޸𸮿� ����� ��X. �Լ����� ������ �� ���� ��
	cout << f << r1 << r2 << r3 << endl;
}