/*
상속: 기존의 클래스를 토대로 해서 새로운 클래스를 만드는 방법이라고 할 수 있다. 객체지향 프로그래밍을 사용해서
워드 프로세서를 만드는 경우를 생각해 보자. 고객으로부터 웹페이지 형식으로 문서를 저장할 수 있게 요구
받았다고 하면 이때는 문서 저장과 관련된 기준의 클래스를 조금 개조해서 웹 페이지 형식으로 저장하게 만들 수 있다
이렇게 기존의 클래스를 조금 개조해서 새로운 클래스를 만들고 싶을 때 상속도 이와 비슷하다. 클래스 A가 클래스 B
를 상속 받게 만들면, 클래스 B는 "부모 클래스"(or Base Class, Super Class)가 되고, 클래스 A는 "자식 클래스" 
(or Derived Class)가 된다. 부모 클래스는 자식 클래스에게 자신의 모든 멤버 변수와 함수를 물려준다. 물론
OOP에서는 물질적인 것 뿐만 아니라, 어떤 기본적인 사람의 특성들도 상속의 특성이 될 수 있다

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person {
	int age;
	char name[20];
public:

	int GetAge() {
		return age;
	}

	char* GetName() {
		return name;
	}

	Person(int _age = 1, char* _name = "noname") {
		age = _age;
		strcpy(name, _name);
	}
};

class Student : public Person {
	char major[20];
public:
	Student(char* _major) {
		strcpy(major, _major);
	}
	
	char* GetMajor() {
		return major;
	}

	void ShowData() {
		cout << "이름 : " << GetName() << endl;
		cout << "나이 : " << GetAge() << endl;
		cout << "전공 : " << GetMajor() << endl;
	}
};

int main() {
	Student Kim("computer");
	Kim.ShowData();

	return 0;
}

상속받는 클래스를 만들기 위해서 class Student : public[상속할 클래스 이름] 이런식으로 상속이라는
문법을 사용할 수 있다. 상속을 사용한 프로그램은 메모리 공간 할당 -> 부모 클래스의 생성자 실행 -> 
자식 클래스의 생성자 실행 이라는 순서를 가지게 된다.

다형성 : 객체지향프로그래밍의 개념을 설명할 때, 추상화와 더불어 가장 중요하게 등장하는 용어이다.
다형성을 이해하기 위해 간단한 예를 들어보도록 하자. 예를 들어 돈을 생각해보자 돈 만원은 만원짜리
한장, 천원짜리 10장, 백원짜리 동전 100개로도 구성 할 수 있다. 즉 만원을 구성하는 형태는 다 틀리지만,
모두 동일한 가치인 만원을 의미하게 된다. 이렇게 만원을 다양한 형태로 나타낼 수 있는 것이 다형성이다.

서로 다른 객체가 동일한 메시지에 대하여 서로 다른 방법으로 응답할 수 있는 기능
여기서 서로 다른 객체는 서로 다른 클래스를 의미한다. 물론 상속의 경우에도 해당이 된다. 다음의 "동일한 메시지"라는
의미는 서로 다른 객체에게 같은 메세지를 보낸다는 의미가 된다. 마지막으로 "서로 다른 방법"으로 응답한다는 의미는
무엇일까? 예를 들어 보자 우선 어떤 도형 모형의 클래스와 이 클래스를 상속 받는 삼각형, 사각형, 원형.. 등의 이런 형태를
갖는 클래스가 있다고 하자. "서로 다른 객체"는 삼각형, 사각형에서 각자 생성한 객체가 될 것이고, "동일한 메시지"는 
도형을 그려라 라는 의미를 가지는 메소드인 Draw함수가 될 것이다. 그렇다면 "서로 다른 방법" 은 draw라는 같은 형태의
메소드를 받아 삼각형, 사각형, 객체는 삼각형, 사각형을 그릴텐데 삼각형을 그리기 위한 방법과 사각형을 그리기 위한
방법은 서로 다를 것이다. 즉, 같은 메소드 호출에 대해 서르 다른 방법으로 응답을 하게 되는 것이다.

Figure 클래스는 하위 클래스에서 모형을 그리는데 사용될 수 있는 draw함수를 가지고 있다. 그러나 Figure 클래스에서는 실제
도형을 그리는 함수 구현 부분을 정의할 수가 없다. 그 이유는 하위 클래스인 Triangle, Square, Circle 클래스 마다 그리는
방법이 다르기 때문이다. 객체지향에서는 이러한 경우 Figure Class를 추상 클래스(Abstract class)로 정의 하고, draw함수 역시
추상 함수(메소드)로 정의한다. 추상 메소드(함수)란 함수의 선언부분만 있고 구현 부분이 없는 함수를 말한다. 이렇게 선언된
추상클래스는 하위 클래스에서 구현되어 사용된다. 즉, 각각의 하위 클래스에서 상속받은 추상 메소드를 서로 다른 방법으로 
구현하게 되는 것이다. 이를 코드로 정리 해보면 아래와 같은 코드가 나올 것이다.
*/

#include<iostream>
#include<string>
using namespace std;

class Figure {
public:
	virtual string draw() = 0;
};

class Triangle : public Figure {
public:
	virtual string draw() {
		return "Draw Traingle";
	}
};

class Square : public Figure {
public:
	virtual string draw() {
		return "Draw Square";
	}
};

class Circle : public Figure {
public:
	virtual string draw() {
		return "Draw Circle";
	}
};

int main() {
	Figure *F1 = new Triangle;
	Figure *F2 = new Square;
	Figure *F3 = new Circle;

	cout << F1->draw() << endl;
	cout << F2->draw() << endl;
	cout << F3->draw() << endl;

	delete F1;
	delete F2;
	delete F3;

	return 0;
}