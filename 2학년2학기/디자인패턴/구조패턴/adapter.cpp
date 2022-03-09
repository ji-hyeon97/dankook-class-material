#include<iostream>
#include<string>
using namespace std;

class Target {
public:
	virtual void Request() {
		cout << "Existing Service" << endl;
	}
};

class Adaptee {
public:
	void SpecificRequest() {
		cout << "Added Service" << endl;
	}
};

class Adapter : public Target {
private:
	Adaptee* adaptee_;
public:
	Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}
	void Request() {
		this->adaptee_->SpecificRequest();
	}
};

int main() {
	Target* target = new Target;
	target->Request();
	Adaptee* adaptee = new Adaptee;
	Adapter* adapter = new Adapter(adaptee);
	adapter->Request();
	return 0;
}