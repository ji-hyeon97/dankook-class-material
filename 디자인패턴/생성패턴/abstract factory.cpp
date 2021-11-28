#include<iostream>
#include<string>

using namespace std;

class AbstractProductA {
public:
	string coffee;
	virtual void make() = 0;
};
class CoffeeProduct1 : public AbstractProductA {
public:
	void make() {
		cout << "Americano created" << endl;
	}
};

class CoffeeProduct2 : public AbstractProductA {
public:
	void make() {
		cout << "latte created" << endl;
	}
};

class AbstractProductB {
public:
	string food;
	virtual void make() = 0;
};

class FoodProduct1 : public AbstractProductB {
public:
	void make() {
		cout << "Sandwich created" << endl;
	}
};

class FoodProduct2 : public AbstractProductB {
public:
	void make() {
		cout << "macaron created" << endl;
	}
};

class AbstractFactory {
public:
	virtual AbstractProductA* CreateProductA() = 0;
	virtual AbstractProductB* CreateProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
	AbstractProductA* CreateProductA() {
		return new CoffeeProduct1();
	}
	AbstractProductB* CreateProductB() {
		return new FoodProduct1();
	}
};


class ConcreteFactory2 : public AbstractFactory {
public:
	AbstractProductA* CreateProductA() {
		return new CoffeeProduct2();
	}
	AbstractProductB* CreateProductB() {
		return new FoodProduct2();
	}
};

int main() {
	ConcreteFactory1* f1 = new ConcreteFactory1();
	AbstractProductA* product_a = NULL;
	AbstractProductB* product_b = NULL;
	product_a = f1-> CreateProductA();
	product_b = f1-> CreateProductB();
	product_a->make();
	product_b->make();

	ConcreteFactory2* f2 = new ConcreteFactory2();
	product_a = f2-> CreateProductA();
	product_b = f2-> CreateProductB();
	product_a->make();
	product_b->make();
	return 0;
}