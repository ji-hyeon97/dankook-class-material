/*
#include <iostream>
#include<string>
using namespace std;

class Person{
	int age;
	string name;
public:
	int GetAge() const {
		return age;
		}
	string GetName()const{
		return name;
		}

Person(int _age=1, string _name= "noname"){
	age=_age;
	name = _name;
	}
};

class Student : public Person{

	string major; //전공
public:
	Student(string _major) {
		major = _major;
	}
	string GetMajor() const {
		return major;
	}

	void ShowData() {
		cout<<"이름: "<<GetName()<<endl;
		cout<<"나이: "<<GetAge()<<endl;
		cout<<"전공: "<<GetMajor()<<endl;
		}
};

int main(void){
	Student Kim("computer");
	Kim.ShowData();

	return 0;
};
위의 소스 코드 문제점을 보자면 main에서 객체 생성을 하는 Student Kim 객체선언 하는 것을 보아
이름이 Kim으로 예상할 수 있다. 허나 여기서 나이와 전공은 우리가 원하는 형태로 초기화 하지 못한다는
점이 바로 문제점이다, 즉, Student 클래스 객체가 생성될때, 자신의 멤버는 생성자내에서 초기화 하고
있지만, Person 클래스의 멤버는 default값으로 초기화 되고 있는게 문제라고 할 수있다.
잠깐 코드를 살펴 보면, showdata 함수 내에서 GetName이라는 함수를 호출 하고 있는데, Student
클래스내에서는 GetName이라는 함수가 없지만, 이것을 호출 할 수있는 이유는 Student 클래스가 Person
클래스를 상속하고 있기 때문에 Person에 GetName이라는 함수가 있어서 이런 호출이 가능한 것이다.

문제로 돌아와서, Student 클래스에 Person의 멤버 변수들도 Student 클래스의 멤버로 상속되어 지니깐
아예 Student 클래스를 정의할 때, 인자값으로 나이와 이름을 초기화해서 Default로 초기화 되는 것을 개선
해보자는 것이다.

Student(int _age, string _name, string _major) {
	age = _age;
	name = _name;
	major = _major;
}
위와 같이 Student 생성자에서 age와 name을 초기화 해주면 될 것이다. 하지만 Person 멤버들이 private으로
선언되어 있으니 위와 같이 코딩을 하면 컴파일 에러가 날 것이다. 왜 이런 에러가 나는 것일까? 비록
Person 클래스 멤버는 Student 클래스에 의해 상속되어 지지만, Person 클래스의 멤버들이 private이기
때문에 Person클래스 내에서만 접근 가능 하기 때문이다. 그렇다고 이 문제를 해결하기 위해 public으로 
멤버 변수들을 선언하면 문제는 해결되겠지만 객체지향의 정보은닉이 무너지는 결과를 낳을 것이다. 그래서 
필요한 게 바로 멤버 이니셜라이저(member initializer)이다. (또는 초기화 리스트)

멤버 이니셜라이저
Student(int _age, string _name, string _major) : Person(_age, _name) {
	major = _major;
}
보통 멤버 이니셜라이저에서는 멤버 변수의 초기화를 이루기 위해 멤버변수 이름이 오지만, 여기에서는
클래스 이름이 나왔다. 이 의미는 _age와 _name이 두 개의 인자값을 받을 수 있는 생성자를 호출하라는 의미로
바뀐다. 이제 완성된 코드로 실행해보자. 이제는 원하는 대로 출력을 이룰 수 있다.
*/
#include<iostream>
#include<string>
using namespace std;

class Person {
	int age;
	string name;

public:
	int GetAge() const {
		return age;
	}

	const string GetName() const {
		return name;
	}

	Person(int _age = 1, string _name = "seo") {
		age = _age;
		name = _name;
	}
};

class Student : public Person {
	string major;

public:
	Student(int _age, string _name, string _major) : Person(_age, _name) {
		major = _major;
	}

	const string GetMajor() const {
		return major;
	}

	void ShowData() const{
		cout << "이름 : " << GetName() << endl;
		cout << "나이 : " << GetAge() << endl;
		cout << "전공 : " << GetMajor() << endl;
	}
};

int main() {
	Student Pac(19, "Pacs.tistory.com", "computer");
	Pac.ShowData();

	return 0;
}
/* 
protected는 접근제어 키워드 중 하나로, 정보은닉 포스팅에서 이미 언급한 바가 있는데, protected는
private과 기능이 완전히 동일하지만, 이것이 상속관계에서 쓰일 때는 파생 클래스가 기본 클래스로의 접근이
가능해진다.
class Person {
protected:
	int age;
	string name;

public:
};

사용할 때는 위와 같이 private 대신에 protected를 써주면 되겠다. 하지만 protected를 쓴다고 해도 멤버 
이니셜라이저를 쓰는 것이 좋은 구조이다. 만약, 멤버 변수의 이름이 변경되어 지는 경우가 생겼다고 한다면,
이 바뀐 이름들을 자신 클래스는 물론이고, 상속을 하고 있는 클래스에서도 이름을 바꿔야 하는 문제가 생긴다
단순히 이름을 바꾸면 된다고 생각하기 쉽지만, 한 클래스의 변경은 다른 클래스의 변경을 유발 시켰기 때문에
심각한 문제라고 볼 수 있다.
*/

