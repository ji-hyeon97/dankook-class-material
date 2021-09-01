/*
생성자(Constructor) : 클래스의 모든 멤버 변수가 모두 public 인 경우 초기화 목록 또는 
유니폼 초기화를 사용하여 직접 초기화 할 수 있다.

#include<iostream>

using namespace std;

class Foo {
public:
	int m_x;
	int m_y;
};

int main() {
	Foo foo1 = { 4,5 }; // initialization list
	Foo foo2 { 6,8 }; // uniform initialization (c++11)

	return 0;
}

그러나 멤버 변수가 private인 경우에는 변수에 직접 접근할 수 없는 비공개 상태이므로
더는 위와 같은 방법으로는 클래스를 초기화할 수 없다

생성자(Constructor)는 해당 클래스의 객체가 인스턴스화될 떄 자동으로 호출되는 특수한 종류의
멤버 함수다. 생성자는 일반적으로 클래스의 멤버변수를 적절한 기본값 또는 사용자 제공 값으로
초기화하거나 클래스를 사용하는 데 필요한 설정이 필요한 경우 사용된다.
일반적인 멤버 함수와 다르게 생성자 정의 방법에는 특정 규칙이 있다.

1. 기본생성자(Default constructor) : 매개 변수를 갖지 않거나 모두 기본값이 설정된 매개 변수를 
가지고 있는 생성자를 기본 생성자라고 한다. 클래스를 인스턴스화할 때 사용자가 초기값을 제공하지
않으면 기본 생성자가 호출된다.

#include<iostream>

class Fraction {
private:
	int m_numerator; //분자
	int m_denominator; //분모

public:
	Fraction() { //default constructor (기본생성자)
		m_numerator = 0; 
		m_denominator = 1; 
	}
	
	int getNumerator() {
		return m_numerator;
	}

	int getDenominator() {
		return m_denominator;
	}

	double getValue() {
		return static_cast<double>(m_numerator)/m_denominator;
	}
};

int main() {
	Fraction frac; //since no arguments, calls Fraction() default constructor
 	std::cout << frac.getNumerator() << "/" << frac.getDenominator() << std::endl;
	return 0;
}

위 예제는 분자(m_numerator)와 분모(m_denominator)값을 가진 Fraction 클래스가 있고, 클래스 이름
과 같은 Fraction() 기본 생성자를 정의했다. 
인수 없이 Fraction 타입의 객체를 인스턴스화 했으므로 객체에 메모리가 할당된 직후 기본 생성자가 
호출되고 객체가 초기화 된다

분자(m_numerator)와 분모(m_denominator)변수는 기본 생성자에서 지정된 값으로 초기화 되었다.
이처럼 기본 생성자는 대부분 클래스에서 매우 유용한 기능이다. 만약, 기본 생성자가 없었다면 위 변수
들은 값을 명시적으로 할당할 때까지 쓰레기값을 가지고 있었을 것이다. 

2. 매개 변수가 있는 생성자를 사용한 초기화
기본 생성자는 클래스 멤버 변수의 기본값을 설정하는 데 유용하지만, 클래스 인스턴스 별 멤버 변수의
값을 특정한 값으로 초기화하고 싶은 경우가 있다. 다행히 생성자에 매개 변수를 선언할 수 있다.

#include<iostream>
#include<cassert>

class Fraction {
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction() { //default constructor
		m_numerator = 0;
		m_denominator = 1;
	}

	//Constructor with two parameters, one parameter having a default value
	Fraction(int numerator, int denominator = 1) {
		assert(denominator != 0);
		m_numerator = numerator;
		m_denominator = denominator;
	}

	int getNumerator() {
		return m_numerator;
	}

	int getDenominator() {
		return m_denominator;
	}

	double getValue() {
		return static_cast<double>(m_numerator) / m_denominator;
	}
};

위 예제에는 한 클래스 안에 두 개의 생성자가 있다.
-> 기본 경우에 호출될 기본 생성자
-> 두 개의 매개 변수를 사용하는 생성자

이 두 생성자는 함수 오버로드로 인해 같은 클래스 안에서 공존할 수 있다.
실제로 각각 고유한 성명(매개 변수 개수 및 타입)으로 원하는 수 만큼 생성자를 정의할 수 있다.

그렇다면 이 생성자를 매개 변수와 함께 어떻게 사용할까 ? 간단하게 직접 초기화 형식의 초기화를 
사용하면 된다.

int x(5); // Direct initialize an integer
Fraction fiveThirds(5,3); // Direct initial a Fraction, calls Fraction(int, int) constructor

c++ 11에서는 유니폼 초기화 방식을 선호하기도 한다.
int x{5}; //Uniform initialization of an integer
Fraction fiveThird{5,3}; //Uniform initialization of a Fraction, calls Fraction(int, int)constructor

위 예제의 매개 변수가 있는 생성자에서 두 번째 매개 변수는 기본 값이 지정되어 있으므로 다음과
같은 방식도 유효하다.
Fraction six(6); //calls Fraction(int, int) constructor, second parameter uses default value

3. 클래스와 대입 연산자(=)를 이용한 복사 초기화
기본 자료형인 변수와 마찬가지로 대입 연산자(=)를 이용해서 클래스를 초기화할 수 있다.
int x=6; // Copy initialize as integer
Fraction six = Fraction(6); // Copy initialize a Fraction, will call Fraction(6,1)
Fraction seven =7; // Copy initialize a Fraction. The compiler will try to find a way to convert 7 to
a Fraction, which will invoke the Fraction(7,1) constructor.
그러나 이러한 방식의 초기화는 효율이 떨어지므로 사용하지 않는 것이 좋다. 
직접 초기화, 유니폼 초기화, 복사 초기화 모두 기본 자료형과는 같은 방식으로 작동하지만, 복사 초기화는
클래스와는 다르게 동작한다.

4. 생성자 줄이기
위 예제에 있는 두 생성자를 아래와 같이 하나로 단순화할 수 있다.

#include<cassert>

class Fraction {
private:
	int m_numerator;
	int m_denominator;
public:
	//Default constructor
	Fraction(int numerator = 0, int denominator = 1) {
		assert(denominator != 0);
		m_numerator = numerator;
		m_denominator = denominator;
	}

	int getNumerator() {
		return m_numerator;
	}

	int getDenominator() {
		return m_denominator;
	}

	double getValue() {
		return static_cast<double>(m_numerator) / m_denominator;
	}
};

이 생성자는 여전히 기본 생성자이지만 이제는 하나 또는 두 개의 사용자 제공 값을 허용할 수 있는
방식으로 정의되었다

Fraction zero; // will call Fraction(0,1)
Fraction six(6); // will call Fraction(6,1)
Fraction fiveThirds(5,3); // will call Fraction(5,3)

5. 암시적으로 생성되는 기본 생성자
클래스에 다른 생성자가 없으면 c++ 컴파일러는 자동으로 기본 생성자를 생성한다. 이를 암시적 생성자라고 한다.
아래 클래스를 보자

class Date {
private:
	int m_year = 1900;
	int m_month = 1;
	int m_day = 1;
};
위 클래스에는 생성자가 없다. 그러므로 컴파일러는 아래와 같게 동작하는 생성자를 생성한다

class Date {
private:
	int m_year = 1900;
	int m_month = 1;
	int m_day = 1;
public:
	Date() {} //implicitly generated constructor
};
이 암시적으로 생성되는 기본 생성자를 사용하면 매개 변수 없이 Date 객체를 만들 수 있지만 멤버를
초기화하지는 않는다. (모든 멤버 변수가 기본 자료형이고, 생성 시 초기화하지 않으므로)
일반적으로 클래스의 객체를 만드는 법을 명시적으로 나타내기 위해 항상 하나 이상의 생성자를
정의하는 게 좋다.

6. 클래스를 포함하는 클래스
클래스는 다른 클래스 멤버 변수로 포함할 수 있다. 기본적으로 외부 클래스가 생성될 때, 멤버 변수는
기본 생성자가 호출되는데, 이것은 생성자의 본문이 실행되기 전에 발생한다
*/
#include <iostream>

class A {
public:
	A() {
		std::cout << "A\n";
	}
};

class B {
private:
	A m_a;
public:
	B() {
		std::cout << "B\n";
	}
};

int main() {
	B b;
	return 0;
}
/*변수 b 가 생성되면서 B() 생성자가 호출된다. 생성자의 본문이 실행되기 전에 m_a가 초기화 되어 
클래스 A의 기본 생성자 A()가 호출된다. 그래서 "A"가 출력된 다음 제어가 B 생성자로 돌아가서
본문이 실행된다. B() 생성자가 변수 m_a를 사용하고 싶을 수도 있으므로 m_a를 먼저 초기화하는 것이
좋다

7. 생성자 노트
-> 컴파일러는 생성자 호출 전에 객체에 대한 메모리를 할당하지 않는다.
-> 생성자는 두 가지 목적으로 사용된다.
1. 누가 객체를 만들 수 있는지 결정한다
2. 객체를 초기화 할 수 있다.
*/
