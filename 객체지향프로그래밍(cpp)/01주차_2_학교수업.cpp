#include<iostream>

using namespace std;

class A {
public:
	virtual void display() { //virtual:���� ������ -> �������ε�, ���� virtual Ű���尡 ���� ��� �������ε�
		cout << "A" << endl;
	}
};

class B : public A {
public:
	void display() {
		cout << "B" << endl;
	}
};

int main() {
	B b;
	A* ptr = &b;
	ptr->display();
	return 0;
}