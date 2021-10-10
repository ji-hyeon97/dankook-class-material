#include<iostream>

using namespace std;

class A {
public:
	virtual void display() { //virtual:없는 것으로 -> 동적바인딩, 만일 virtual 키워드가 없는 경우 정적바인딩
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