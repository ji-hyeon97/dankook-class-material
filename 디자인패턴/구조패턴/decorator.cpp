#include<iostream>
#include <list> 
using namespace std;

class Component {
public:
	virtual string Operation() = 0;
};
class ConcreteComponent : public Component {
public:
	string Operation() {
		return "Coffee";
	}
};

class Decorator : public Component {
protected:
	Component* component_;
public:
	Decorator(Component* component) : component_(component) { }
	string Operation() {
		return this
			->component_
			->Operation();
	}
};

class ConcreteDecoratorA : public Decorator {
public:
	ConcreteDecoratorA
	(Component* component) : Decorator
	(component) { }
	string Operation() {
		return "syrup1 + ("
			+ Decorator::Operation()
			+ ")";
	}
};

class ConcreteDecoratorB : public Decorator {
public:
	ConcreteDecoratorB
	(Component* component) : Decorator
	(component) {
	}
	string Operation() {
		return "syrup2 + ("
			+ Decorator::Operation()
			+ ")";
	}
};

int main() {
	Component* coffee = new ConcreteComponent;
	coffee = new ConcreteDecoratorA(coffee); //syrup1 added
	coffee = new ConcreteDecoratorA(coffee); //syrup1 added
	coffee = new ConcreteDecoratorB(coffee); //syrup2 added
	coffee = new ConcreteDecoratorB(coffee); //syrup2 added
	coffee = new ConcreteDecoratorB(coffee); //syrup2 added
	cout << "RESULT: " << coffee->Operation();
	return 0;
}