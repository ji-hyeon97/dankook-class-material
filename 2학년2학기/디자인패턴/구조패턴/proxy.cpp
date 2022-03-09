#include<iostream>
#include <list> 
#include<string>
using namespace std;

class Subject {
public:
	virtual void Request() const = 0;
};
class RealSubject : public Subject {
public:
	void Request() const {
		cout << "Handling Request." << endl;
	}
};

class Proxy : public Subject {
private:
	RealSubject* real_subject_;
	bool CheckAccess() const {
		cout << "Proxy: Checking Access" << endl;
		return true;
	}
public:
	Proxy(RealSubject* real_subject) : real_subject_(new RealSubject(*real_subject)) { }
	void Request() const override {
		if (this->CheckAccess()) {
			cout << "Proxy: Access Granted" << endl;
			this->real_subject_->Request();
		}
	}
};

int main() {
	RealSubject* real_subject = new RealSubject;
	Proxy* proxy = new Proxy(real_subject);
	proxy->Request();
	return 0;
}