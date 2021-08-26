#include<iostream>

using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a(10); //int a=10; 초기화
	int b(a+5);

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;

	//범위기반 for문
	int arr[10] = { 3,1,4,1,5,9,2,6,5,3 };
	for (int i = 0; i < 10; i++) {
		cout << arr[i]<<" ";
	}
	cout << endl;

	//reference 변수
	for (int &n : arr) {
		cout << n << " ";
		n++;//메모리상 n, arr에 값이 따로 할당되어 있기 떄문에 작동X
	}
	cout << endl;

	for (int n : arr) {
		cout << n << " ";
		n++;		
	}
	cout << endl;

	//reference 변수
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

	// r-value 수정할수 없는 값
	int f(5);
	int &r1 = f;
	int &&r2 = 3;//메모리에 저장된 값X. 상수는 수정할 수 없는 값
	int &&r3 = f * f;//메모리에 저장된 값X. 함수값도 수정할 수 없는 값
	cout << f << r1 << r2 << r3 << endl;
}