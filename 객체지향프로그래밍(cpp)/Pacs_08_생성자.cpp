/*
������(Constructor) : Ŭ������ ��� ��� ������ ��� public �� ��� �ʱ�ȭ ��� �Ǵ� 
������ �ʱ�ȭ�� ����Ͽ� ���� �ʱ�ȭ �� �� �ִ�.

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

�׷��� ��� ������ private�� ��쿡�� ������ ���� ������ �� ���� ����� �����̹Ƿ�
���� ���� ���� ������δ� Ŭ������ �ʱ�ȭ�� �� ����

������(Constructor)�� �ش� Ŭ������ ��ü�� �ν��Ͻ�ȭ�� �� �ڵ����� ȣ��Ǵ� Ư���� ������
��� �Լ���. �����ڴ� �Ϲ������� Ŭ������ ��������� ������ �⺻�� �Ǵ� ����� ���� ������
�ʱ�ȭ�ϰų� Ŭ������ ����ϴ� �� �ʿ��� ������ �ʿ��� ��� ���ȴ�.
�Ϲ����� ��� �Լ��� �ٸ��� ������ ���� ������� Ư�� ��Ģ�� �ִ�.

1. �⺻������(Default constructor) : �Ű� ������ ���� �ʰų� ��� �⺻���� ������ �Ű� ������ 
������ �ִ� �����ڸ� �⺻ �����ڶ�� �Ѵ�. Ŭ������ �ν��Ͻ�ȭ�� �� ����ڰ� �ʱⰪ�� ��������
������ �⺻ �����ڰ� ȣ��ȴ�.

#include<iostream>

class Fraction {
private:
	int m_numerator; //����
	int m_denominator; //�и�

public:
	Fraction() { //default constructor (�⺻������)
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

�� ������ ����(m_numerator)�� �и�(m_denominator)���� ���� Fraction Ŭ������ �ְ�, Ŭ���� �̸�
�� ���� Fraction() �⺻ �����ڸ� �����ߴ�. 
�μ� ���� Fraction Ÿ���� ��ü�� �ν��Ͻ�ȭ �����Ƿ� ��ü�� �޸𸮰� �Ҵ�� ���� �⺻ �����ڰ� 
ȣ��ǰ� ��ü�� �ʱ�ȭ �ȴ�

����(m_numerator)�� �и�(m_denominator)������ �⺻ �����ڿ��� ������ ������ �ʱ�ȭ �Ǿ���.
��ó�� �⺻ �����ڴ� ��κ� Ŭ�������� �ſ� ������ ����̴�. ����, �⺻ �����ڰ� �����ٸ� �� ����
���� ���� ��������� �Ҵ��� ������ �����Ⱚ�� ������ �־��� ���̴�. 

2. �Ű� ������ �ִ� �����ڸ� ����� �ʱ�ȭ
�⺻ �����ڴ� Ŭ���� ��� ������ �⺻���� �����ϴ� �� ����������, Ŭ���� �ν��Ͻ� �� ��� ������
���� Ư���� ������ �ʱ�ȭ�ϰ� ���� ��찡 �ִ�. ������ �����ڿ� �Ű� ������ ������ �� �ִ�.

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

�� �������� �� Ŭ���� �ȿ� �� ���� �����ڰ� �ִ�.
-> �⺻ ��쿡 ȣ��� �⺻ ������
-> �� ���� �Ű� ������ ����ϴ� ������

�� �� �����ڴ� �Լ� �����ε�� ���� ���� Ŭ���� �ȿ��� ������ �� �ִ�.
������ ���� ������ ����(�Ű� ���� ���� �� Ÿ��)���� ���ϴ� �� ��ŭ �����ڸ� ������ �� �ִ�.

�׷��ٸ� �� �����ڸ� �Ű� ������ �Բ� ��� ����ұ� ? �����ϰ� ���� �ʱ�ȭ ������ �ʱ�ȭ�� 
����ϸ� �ȴ�.

int x(5); // Direct initialize an integer
Fraction fiveThirds(5,3); // Direct initial a Fraction, calls Fraction(int, int) constructor

c++ 11������ ������ �ʱ�ȭ ����� ��ȣ�ϱ⵵ �Ѵ�.
int x{5}; //Uniform initialization of an integer
Fraction fiveThird{5,3}; //Uniform initialization of a Fraction, calls Fraction(int, int)constructor

�� ������ �Ű� ������ �ִ� �����ڿ��� �� ��° �Ű� ������ �⺻ ���� �����Ǿ� �����Ƿ� ������
���� ��ĵ� ��ȿ�ϴ�.
Fraction six(6); //calls Fraction(int, int) constructor, second parameter uses default value

3. Ŭ������ ���� ������(=)�� �̿��� ���� �ʱ�ȭ
�⺻ �ڷ����� ������ ���������� ���� ������(=)�� �̿��ؼ� Ŭ������ �ʱ�ȭ�� �� �ִ�.
int x=6; // Copy initialize as integer
Fraction six = Fraction(6); // Copy initialize a Fraction, will call Fraction(6,1)
Fraction seven =7; // Copy initialize a Fraction. The compiler will try to find a way to convert 7 to
a Fraction, which will invoke the Fraction(7,1) constructor.
�׷��� �̷��� ����� �ʱ�ȭ�� ȿ���� �������Ƿ� ������� �ʴ� ���� ����. 
���� �ʱ�ȭ, ������ �ʱ�ȭ, ���� �ʱ�ȭ ��� �⺻ �ڷ������� ���� ������� �۵�������, ���� �ʱ�ȭ��
Ŭ�����ʹ� �ٸ��� �����Ѵ�.

4. ������ ���̱�
�� ������ �ִ� �� �����ڸ� �Ʒ��� ���� �ϳ��� �ܼ�ȭ�� �� �ִ�.

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

�� �����ڴ� ������ �⺻ ������������ ������ �ϳ� �Ǵ� �� ���� ����� ���� ���� ����� �� �ִ�
������� ���ǵǾ���

Fraction zero; // will call Fraction(0,1)
Fraction six(6); // will call Fraction(6,1)
Fraction fiveThirds(5,3); // will call Fraction(5,3)

5. �Ͻ������� �����Ǵ� �⺻ ������
Ŭ������ �ٸ� �����ڰ� ������ c++ �����Ϸ��� �ڵ����� �⺻ �����ڸ� �����Ѵ�. �̸� �Ͻ��� �����ڶ�� �Ѵ�.
�Ʒ� Ŭ������ ����

class Date {
private:
	int m_year = 1900;
	int m_month = 1;
	int m_day = 1;
};
�� Ŭ�������� �����ڰ� ����. �׷��Ƿ� �����Ϸ��� �Ʒ��� ���� �����ϴ� �����ڸ� �����Ѵ�

class Date {
private:
	int m_year = 1900;
	int m_month = 1;
	int m_day = 1;
public:
	Date() {} //implicitly generated constructor
};
�� �Ͻ������� �����Ǵ� �⺻ �����ڸ� ����ϸ� �Ű� ���� ���� Date ��ü�� ���� �� ������ �����
�ʱ�ȭ������ �ʴ´�. (��� ��� ������ �⺻ �ڷ����̰�, ���� �� �ʱ�ȭ���� �����Ƿ�)
�Ϲ������� Ŭ������ ��ü�� ����� ���� ��������� ��Ÿ���� ���� �׻� �ϳ� �̻��� �����ڸ�
�����ϴ� �� ����.

6. Ŭ������ �����ϴ� Ŭ����
Ŭ������ �ٸ� Ŭ���� ��� ������ ������ �� �ִ�. �⺻������ �ܺ� Ŭ������ ������ ��, ��� ������
�⺻ �����ڰ� ȣ��Ǵµ�, �̰��� �������� ������ ����Ǳ� ���� �߻��Ѵ�
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
/*���� b �� �����Ǹ鼭 B() �����ڰ� ȣ��ȴ�. �������� ������ ����Ǳ� ���� m_a�� �ʱ�ȭ �Ǿ� 
Ŭ���� A�� �⺻ ������ A()�� ȣ��ȴ�. �׷��� "A"�� ��µ� ���� ��� B �����ڷ� ���ư���
������ ����ȴ�. B() �����ڰ� ���� m_a�� ����ϰ� ���� ���� �����Ƿ� m_a�� ���� �ʱ�ȭ�ϴ� ����
����

7. ������ ��Ʈ
-> �����Ϸ��� ������ ȣ�� ���� ��ü�� ���� �޸𸮸� �Ҵ����� �ʴ´�.
-> �����ڴ� �� ���� �������� ���ȴ�.
1. ���� ��ü�� ���� �� �ִ��� �����Ѵ�
2. ��ü�� �ʱ�ȭ �� �� �ִ�.
*/
