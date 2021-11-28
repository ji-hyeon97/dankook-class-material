#include<iostream>
#include<string>
using namespace std;

class Prototype {
protected:
	string _size = "";
	string _color = "";
public:
	virtual Prototype* clone() = 0;
	void print() { cout << _size << "\t" << _color << endl; }
};

class ConcretePrototype1 : public Prototype {
public:
	ConcretePrototype1(string size, string color) {
		_size = size;
		_color = color;
	}
	Prototype* clone() {
		return new ConcretePrototype1(*this);
	}
};

class ConcretePrototype2 : public Prototype {
public:
	ConcretePrototype2(string size) {
		_size = size;
	}
	Prototype* clone() {
		return new ConcretePrototype2(*this);
	}
};

int main() {
	Prototype* prototype1 = new ConcretePrototype1("tall", "black");
	Prototype* copy1 = prototype1->clone();
	prototype1->print();
	copy1->print();
	Prototype* prototype2 = new ConcretePrototype2("venti");
	Prototype* copy2 = prototype2->clone();
	prototype2->print();
	copy2->print();
	return 0;
}