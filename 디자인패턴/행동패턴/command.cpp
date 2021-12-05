#include<iostream>
#include <list> 
#include<string>
#include<vector>
using namespace std;

class Receiver {
public:
	void execute(const string& a) {
		cout << a << " done" << endl;
	}
};

class Command {
public:
	virtual void Execute() const = 0;
};

class Command1 : public Command {
private:
	Receiver* receiver_;
	string a_;
public:
	Command1(Receiver* receiver, string a) : receiver_(receiver), a_(a) { }
	void Execute() const override { this->receiver_->execute(this->a_); }
};

class Command2 : public Command {
private:
	Receiver* receiver_;
	string a_;
	string b_;
public:
	Command2(Receiver* receiver, string a, string b) : receiver_(receiver), a_(a), b_(b) { }
	void Execute() const override {
		this->receiver_->execute(this->a_);
		this->receiver_->execute(this->b_);
	}
};

class Invoker {
private:
	Command* c_;
public:
	void setCommand(Command* command) {
		this->c_ = command;
	}
	void Do() {
		this->c_->Execute();
	}
};

int main() {
	Invoker* invoker = new Invoker;
	Receiver* receiver = new Receiver;
	invoker->setCommand(new Command1(receiver, "Americano"));
	invoker->Do();
	invoker->setCommand(new Command2(receiver, "Americano", "Mocha"));
	invoker->Do();
	return 0;
}