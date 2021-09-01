/*
this Pointer란 객체가 멤버함수를 호출할 때 자동으로 멤버함수에게 전달되는 포인터이며, 호출한 객체를
가르키는 포인터를 말한다. 흔히 자기 참조 포인터(자기 자신을 가리킬 수 있는 포인터)라고 불리우며,
멤버 함수에게만 this pointer가 전달된다.
(Friend 함수는 멤버 함수가 아니므로 this pointer가 전달되지 않는다) 아래의 예제를 보면 금방 감이
올것이다.

#include<iostream>

using namespace std;

class Person {
public:
	Person * GetThis() {
		return this;
	}
};

int main() {
	Person *p1 = new Person();
	cout << "포인터 p1 : " << p1 << endl;
	cout << "p1의 this : " << p1->GetThis() << endl << endl;

	Person *p2 = new Person();
	cout << "포인터 p2 : " << p2 << endl;
	cout << "p2의 this : " << p2->GetThis() << endl;

	return 0;
}

Friend : 일반적으로 클래스의 비공개멤버(private)는 외부함수에서 접근할 수 없다. private 변수, 함수는
멤버 함수에서만 접근이 가능하기 때문이다. 그런데 멤버함수가 아닌 외부함수에서 접근해야 할 경우가
발생될 수 있다. 그래서 나타난게 friend라는 문법이다. 그런 경우 클래스에서 friend함수로 선언해 주면 
외부함수이면서 클래스의 비공개 멤버에 접근할수 있는 권한을 갖게 된다

#include<iostream>

using namespace std;

class Counter {
private:
	int val;

public:
	Counter() {
		val = 0;
	}

	void Print() const {
		cout << val << endl;
	}

	friend void SetX(Counter& c, int val); //friend 선언
};

void SetX(Counter &c, int val) { //전역함수
	c.val = val;
}

int main() {
	Counter cnt;
	cnt.Print();

	SetX(cnt, 2002);
	cnt.Print();

	return 0;
}
*/
#include<iostream>
using std::cout;
using std::endl;

class AAA {
private:
	int data;
	friend class BBB; //class BBB를 friend로 선언함 !
};

class BBB {
public:
	void SetData(AAA& aaa, int val) {
		aaa.data = val; //클래스 AAA의 private 영역 접근 !
	}
};

int main() {
	AAA aaa;
	BBB bbb;

	bbb.SetData(aaa, 10);
	return 0;
}
/*
위 두 예제를 보면 쓰는 용법에 대해서는 간단히 한 눈에 알아 볼 수 있다. friend는 함수, 클래스에
적용해서 쓸 수 있다. friend가 가지는 특징을 살펴 보면 아래 4가지 정도로 요약할 수 있다.

1. 클래스에 friend 키워드와 함께 원형을 명시 해야 한다
2. 상속 되지 않는다.
3. friend 함수는 클래스의 멤버가 아니라 일반함수이다. (멤버 접근 연산자로 접근하지 않는다.)
4. 보통 사용되는 곳은 연산자 중복 사용시, 하나의 함수에서 다른 클래스들의 비공개 멤버로 접근시 사용된다.(전방참조)

전방참조 : 두 개 이상의 클래스를 동시에 선언하는 것은 논리적으로 불가능하므로 컴파일러에게 미리 이 클래스가 있음을 알림

보통 friend가 oop의 캡슐화와 정보은닉을 해친다는 이야기가 있지만, 대다수의 경우 friend는
멤버의 개수를 줄여줌으로서 캡슐화에 더 이로운 영향을 끼진다.(public 멤버가 적을수록 캡슐화가 좋아진다)
friend를 피하기 위해 인위적으로 public 멤버를 추가한다면 그것이 오히려 oop에 악영향을 끼진다.
*/