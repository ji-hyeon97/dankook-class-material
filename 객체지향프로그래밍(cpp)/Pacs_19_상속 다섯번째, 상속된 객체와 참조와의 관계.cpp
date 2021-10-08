/*
객체 레퍼런스 : 객체를 참조 할 수 있는 레퍼런스로 클래스 포인터(객체 포인터)의 특성과 일치 한다.

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

class ScholarStd : public Student {
public:
	void Receive_Scholar() {
		cout << "Work" << endl;
	}
};

int main() {
	ScholarStd p;
	Student &ref1 = p;
	Person &ref2 = p;
	p.Sleep();
	ref1.Sleep();
	ref2.Sleep();

	return 0;
}

앞서 배웠듯이 is-a 관계에서 어떤 클래스의 포인터는 자신 객체 뿐만 아니라, 자신을 상속하고 있는 클래스의 객체도 
가르킬수가 있다. Person 클래스의 포인터를 가지고, 위의 코드에서의 세개 클래스 객체를 다 카리킬 수 있다. Person
클래스의 참조도 마찬가지로, 여기 세개의 클래스를 다 참조할 수 있다.
저번에 포스팅 했던 객체 포인터의 특성과 일치하는 것을 알 수있다.

객체 레퍼런스 권한
*/
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

class PartTimeStd : public Student {
public:
	void Work() {
		cout << "Work" << endl;
	}
};

int main() {
	PartTimeStd p;
	p.Sleep();
	p.Study();
	p.Work();

	Person &ref = p;
	ref.Sleep();
	//ref.Study();  에러
	//ref.Work();  에러

	return 0;
}
/*
객체의 레퍼런스 권한도 객체 포인터 권한과 마찬가지이다. 객체 포인터때도 지겹도록 반복해서 언급을 했지만, A 클래스의 
참조는 B객체도, C객체도 참조 할 수 있는데, 접근할 수 있는 영역은 A클래스내에 선언되어 있거나, A클래스를 상속하고
있는 멤버로써 제한되어 진다.
*/