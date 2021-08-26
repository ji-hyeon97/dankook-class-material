#include<iostream>

using namespace std;

class myClass {
public:
	void PrintThis() {
		cout << "나의 주소는 " << this << endl;
	}
};

int main() {
	myClass a, b;

	cout << "a의 주소는 " << &a << endl;
	cout << "b의 주소는 " << &b << endl;

	a.PrintThis();
	b.PrintThis();
}
//this포인터라는 매개변수를 숨김
//this는 보이지 않는 매개변수이다
//PrintThis()함수는 객체 a,b에 속한 메모리영역은 아니지만
//this라는 포인터를 매개변수로 받아 PrintThis()함수가 어디 객체 소속인지 알 수 있다 