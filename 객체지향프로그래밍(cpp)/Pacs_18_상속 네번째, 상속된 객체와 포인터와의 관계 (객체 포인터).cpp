/*
객체포인터 : 객체를 가르킬수 있는 포인터를 의미한다. (객체의 주소값을 저장할 수 있는 포인터)
예를 들어 A 클래스의 포인터는 A 객체 뿐만 아니라, A 클래스를 상속하는 파생클래스의 객체의 주소 값도
저장이 가능하다.

#include<iostream>
using namespace std;

class Person {
public:
	void Sleep() {
		cout << "Sleep" << endl;
	}
};

class Student : public Person {
public:
	void Study() {
		cout << "Study" << endl;
	}
};

class Scholar : public Student {
public:
	void Receive_Scholar() {
		cout << "Work" << endl;
	}
};

int main() {
	Person *p1 = new Person;
	Person *p2 = new Student;
	Person *p3 = new Scholar; //Person 클래스의 p3포인터가 가르키는 대상이 객체 Scholar

	p1->Sleep();
	p2->Sleep();
	p3->Sleep();

	return 0;
}

여기서 p1,p2,p3 포인터는 Person 클래스의 포인터니깐 Person클래스의 객체를 가리킬 수 있는 포인터가 되는 것이다.
(*p1는 Person 클래스의 객체를 가리킬 수 있는 포인터)
- p2라는 포인터는 Student 클래스의 객체를 가르키는 것도 문제가 없을 것이다.
- p3라는 포인터는 ScholarStd 클래스의 객체를 가르키는 것도 문제가 없을 것이다.

그럼 "Student *s"라고 선언할 경우를 생각해 보자. 이 선언은 ScholarStd 클래스의 객체를 가리키는 것은 문제없다
하지만 포인터 S는 Person 클래스의 객체를 가르키는 것은 문제가 된다. 왜냐하면 Person 객체들이 다 Student가 아니기 때문이다.

객체 포인터 권한
지금까지는 객체가 가르키는 것이 어떤 경우가 합당한지를 알아 봤는데, 이 객체를 가지고 그 안의 함수를 사용하는 경우는 어떨까?
객체 포인터 권한에 대해 알아보자
예를 들어 여기 A라는 클래스가 있다. A는 B에 의해 상속되어 지고 C는 B클래스에 의해 상속되어 진다고 가정하고 각각의 클래스에는
클래스 이름에 맞는 a,b,c() 함수가 존재한다고 해보자
그 후, C클래스의 객체를 생성한다고 하자. 그러면 C클래스의 객체 안에는 아마도, A클래스내에 선언되어 있는 a()함수도 있을 것이고, 
b()함수도 있을 것이고, 자신의 클래스의 함수인 c()함수도 있을 것이다. C클래스의 객체는 B객체이자 A객체가 되므로 A,B,C클래스의
포인터를 가지고 이 것을 가리킬수 있을 것이다. 
이렇게 포인트 변수들이 가르키는 대상이 비록 C객체 이지만, A클래스의 포인터를 가지고 호출 할 수 있는 함수는 A클래스 내에 선언되어
있는 멤버 변수나 멤버 함수로 제한적이다. 즉" A클래스 포인터(A *a)가 가르키는 대상이 C객체 일지라도, A클래스의 포인터로 접근 할
수 있는 영역은 A클래스내로 제한된다." 라는 이야기 이다.

위의 이야기를 염두에 두고 소스코드를 보자. C클래스의 포인터 c는 C클래스 객체를 가르키고 있다. 그러므로 C클래스의 포인터로 접근할
수 있는 영역은 C클래스내로 제한된다는 이야기 이다. is-a관계에 의해 C는 모든 함수에 접근 권한을 가지게 되므로 아래의 코드는 문제없다.

#include<iostream>
using namespace std;

class A {
public:
	void a() {
		cout << "call a function" << endl;
	}
};

class B : public A {
public:
	void b() {
		cout << "call b function" << endl;
	}
};

class C : public B {
public:
	void c() {
		cout << "call c function" << endl;
	}
};

int main() {
	C *c = new C;
	c->a();
	c->b();
	c->c();

	return 0;
}
*/
#include<iostream>
using namespace std;

class A {
public:
	void a() {
		cout << "call a function" << endl;
	}
};

class B : public A {
public:
	void b() {
		cout << "call b function" << endl;
	}
};

class C : public B {
public:
	void c() {
		cout << "call c function" << endl;
	}
};

int main() {
	C *c = new C;
	B *b = c;
	A *a = b;

	cout << c << endl;
	cout << b << endl;
	cout << a << endl;
	b->a();
	b->b();

	return 0;
}
/*
우선 124번째 줄에 있는 B *b = c;라는 문법을 보자 여기서 우리는 포인터 타입이 일치하지 않는데 어떻게 이런 문법이 가능한가
라는 의구심을 가지게 될 것이다. 하지만 앞서 배웠듯이, C 클래스의 포인터는 C클래스의 포인터이자, A, B클래스의 포인터도 되므로
이런 문법이 성립이 되는 것이다. 문제 이야기로 넘어와 보자. 위 예제는 객체 포인터 권한 도입부분에 설명한 부분을 코드로 풀어 
놓은 것이다. c,b,a 를 출력해보면 같은 주소값을 가지는 것을 알수 있다. 그리고 또 확인해야 할 것이 있다. B클래스의 포인터를 이용해
각각 함수를 호출해 보자. 메인 함수에 아래와 같은 코드를 넣어 컴파일해 보자
b->c()에서 컴파일 에러를 확인해 볼수 있다. 왜 그런 것일까 ? 우리는 b라는 포인터가 가르키는 객체가 C클래스의 객체라는 것을 알 고
있지만 컴파일러는 b라는 포인터가 가르키는 대상이 C클래스의 객체라는 것을 모른다. b라는 포인터가 어느 클래스의 객체를 가르키는지는
runtime에 의해 결정되기 때문에 컴파일러는 이 대상이 어느 객체를 가리키는지 결정을 못내리는 것이다.

이와 마찬가지로 A의 클래스 포인터 a가 가리키는 것이 우리는 C클래스의 객체라는 것을 알고 있지만, 컴파일러는 무엇을 가르키는지 알지
못한다. 그래서 컴파일러는 포인터 a가 가리키는 대상이 무엇이든지 a함수의 호출은 전혀 문제가 안될것이라는 판단에 a함수 호출만 보장하는 것이다.
*/



*/