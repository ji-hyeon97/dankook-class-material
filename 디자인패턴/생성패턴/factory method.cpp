#include<iostream>
#include<string>
using namespace std;

class Coffee{
public:
	virtual string Operation() = 0;
};

class Americano : public Coffee{
public:
	string Operation() {
		return "Americano";
	}
};
class Mocha : public Coffee{
public:
	string Operation() {
		return "Mocha";
	}
};

class Creator {
public:
	virtual Coffee* FactoryMethod() = 0;
	string create() {
		Coffee* product = this->FactoryMethod();
		string result = product->Operation();
		delete product;
		cout << result << endl;
		return result;
	}
};

class AmericanoCreator : public Creator {
public:
	Coffee* FactoryMethod() {
		return new Americano();
	}
};

int main() {
	Creator* creator = new AmericanoCreator();
	creator->create();
	delete creator;
	return 0;
}
