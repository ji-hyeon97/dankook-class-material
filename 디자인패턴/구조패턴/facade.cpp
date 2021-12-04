#include<iostream>
#include <list> 
#include<string>
using namespace std;

class Subsystem1 {
public:
	string init() { return "Subsystem1: Init!\n"; }
	string run() { return "Subsystem1: On!\n"; }
};
class Subsystem2 {
public:
	string init() { return "Subsystem2: Init!\n"; }
	string run() { return "Subsystem2: On!\n"; }
};

class Facade {
protected:
	Subsystem1* subsystem1_;
	Subsystem2* subsystem2_;
public:
	Facade(Subsystem1* subsystem1, Subsystem2* subsystem2) {
		this->subsystem1_ = new Subsystem1();
		this->subsystem2_ = new Subsystem2();
	}
	string Operation() {
		string result = "Initializing subsystems:\n";
		result += this->subsystem1_->init();
		result += this->subsystem2_->init();
		result += "Ready to use: \n";
		result += this->subsystem1_->run();
		result += this->subsystem2_->run();
		return result;
	}
};

int main() {
	Subsystem1* subsystem1 = new Subsystem1;
	Subsystem2* subsystem2 = new Subsystem2;
	Facade* facade = new Facade(subsystem1, subsystem2);
	cout << facade->Operation();
	return 0;
}