//다중 상속이란?
#include<iostream>
using namespace std;

class AAA {
public:
	void String1() {
		cout << "AAA::String1" << endl;
	}
};

class BBB {
public:
	void String2() {
		cout << "BBB::String2" << endl;
	}
};

class CCC : public AAA, public BBB {
public:
	void ShowString() {
		String1();
		String2();
	}
};

int main() {
	CCC ccc;
	ccc.ShowString();

	return 0;
}

//위의 소스 코드만 보면 감이 올 것이다. 다중 상속이란 19번째 줄처럼 둘 이상의 클래스를 동시에 상속하는 것이다.
//다중 상속의 모호성
/*
#include<iostream>
using namespace std;

class AAA {
public:
	void String() {
		cout << "AAA::String" << endl;
	}
};

class BBB {
public:
	void String() {
		cout << "BBB::String" << endl;
	}
};

class CCC : public AAA, public BBB {
public:
	void ShowString() {
		String(); //AAA::String();
		String(); //BBB::String();
	}
};

int main() {
	CCC ccc;
	ccc.ShowString();

	return 0;
}
위의 소스 코드와 같이 다중 상속의 관계에서 AAA, BBB클래스에 같은 이름을 가진 멤버 함수가 있다고 하면, 이때 모호성이
발생한다. 과연 이 String 함수는 어느 객체의 함수를 호출해 주는 것이냐 알 수 없기 때문이다. 주석친 부분처럼 범위 지정 연산자를
이용한 문제 해결 방법도 있지만, 아주 코드가 복잡해 지는 걸 알 수 있는 것이다.
*/