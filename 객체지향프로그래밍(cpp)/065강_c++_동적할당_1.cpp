// 정적 할당 -> int a
// 동적 할당 -> 프로그램 실행중 변수를 메모리에 할당하는 것

#include<iostream>

using namespace std;

int main() {
	int *a = new int(5); // 주소값 반환

	cout << *a << endl;
	cout << a << endl;

	*a = 10;
	cout << *a << endl;
	cout << a << endl;

	delete a;//메모리 해제
}