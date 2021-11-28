#include<iostream>
#include<string>
using namespace std;

class Singleton {
public:
	static Singleton* getInstance();
	void print() {
		cout << val << endl;
	}
	void inc() {  val++;  }
private:
	static Singleton* _instance;
	Singleton() { val = 3; }
	int val;
};

Singleton* Singleton::_instance = 0;
Singleton* Singleton::getInstance() {
	if (_instance == 0)
		_instance = new Singleton;
	return _instance;
}

int main() {
	Singleton *s = Singleton :: getInstance();
	s->print();

	Singleton* y = Singleton::getInstance();
	y->print();
	y->inc();
	s->print();

	return 0;
}