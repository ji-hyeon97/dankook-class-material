/*
연산자 오버로딩 : C++ 문법과 우리와의 약속이라고 할 수 있는데, 우리가 함수를 정의하는데 이어서
operator라는 키워드와 연산자를 붙여서 함수의 이름을 만들 경우에(operator + 이렇게) 우리가 일반적인
함수를 호출 하는 방법 말고도 연산자만을 이용해서도 함수가 호출 되도록 해주겠다는 이야기이다.

#include<iostream>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0) {
		x = _x;
		y = _y;
	}

	void ShowPosition();

	Point operator+(const Point &p);
};

void Point::ShowPosition() {
	cout << x << " " << y << endl;
}

Point Point ::operator+(const Point &p) {
	Point temp(x + p.x, y + p.y);
	return temp;
}

int main() {
	Point p1(1, 2);
	Point p2(2, 1);
	Point p3 = p1 + p2;
	p3.ShowPosition();

	return 0;
}
그럼 위의 소스 코드 35번째 줄의 p1+p2는 어떤 의미를 갖는지 알아 보자 여기서 p1, p2는 객체 이므로 기본적으로 '+'덧셈 연산이
불가능하다. 그래서 c++에서는 어떤 약속을 하였느냐 하면, '+'라는 사칙연산을 할려고 하는게 아니라, 앞에 operator라는 키워드를
붙여서 p1과 p2를 이용해서 operator +라는 함수를 호출해주게 되는 것이다. 그래서 이제 c++에서는 'operator +'라는 함수를 호출 해야 하는데, 
C++에서는 함수를 만드는 방법, 멤버 함수, 전역 함수 2가지가 있다. 그러므로 'operator+'라는 이 둘로 정의 될 수 있는 것이다. 우리가 멤버로
만들건, 전역으로 만들건 C++은 'operator +'에 대해 알아서 처리해줄 수 있다. 그럼 멤버 함수에 의한 오버로딩은 어떻게 일어 나는지 알아보자
35번째 라인의 p1+p2; 이것은 "이항 연산자 왼쪽에 오는 객체의 operator + 함수를 호출하면서, 이항연산자의 오른쪽의 피연산자를 인자로 전달한다"
라는 의미가 된다. 즉 p1.operator +(p2); 이렇게 바뀐다는 말이다. 덧셈 연산이 끝나면 p1+p2자리에 temp라는 이름의 객체의 복사본이 반환되면서
들어 오게 된다. 그리고 반환된값은 p3에 초기화해준다 여기서 temp라는 객체는 포인터 클래스의 객체이므로, 이 경우 복사 생성자가 호출 되는 것도 
알 수 있다. temp함수의 연산에 의해서 아래와 같은 결과가 나오는 것을 알 수 있다.
*/
//전역함수에 의한 오버로딩
#include<iostream>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0) {
		x = _x;
		y = _y;
	}
	
	void ShowPosition();

	friend Point operator+(const Point& p1, const Point& p2);
};

void Point::ShowPosition() {
	cout << x << " " << y << endl;
}

Point operator+(const Point &p1, const Point &p2) { //전역함수
	Point temp(p1.x + p2.x, p1.y + p2.y);
	return temp;
}

int main() {
	Point p1(1, 2);
	Point p2(2, 1);
	Point p3 = p1 + p2;
	p3.ShowPosition();

	return 0;
}
/*
위의 소스코드는 전역함수를 friend 선언해주고 있다. friend 선언을 해줌으로서, operator+ 함수를 포인터 클래스
객체의 private멤버에 직접 접근이 가능하다.(friend는 연산자 오버로딩에 주로 사용된다.) 그럼 전역함수에는
p1+p2; 가 C++의 약속에 의해 어떤 식으로 해석이 되는 것일까? 바로 아래와 같이 해석된다. operator+(p1,p2);
전역함수는 함수 이름만 있어도 호출이 가능하므로, 위와 같은 식으로 해석되는 것을 알 수 있다. 여기까지 멤버함수,
전역함수에 의한 오버로딩을 알아 봤다.
*/