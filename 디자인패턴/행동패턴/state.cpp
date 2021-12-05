#include<iostream>
#include <list> 
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

class Context;
class State {
protected:
	Context* context_;
public:
	void set_context(Context* context) {
		this->context_ = context;
	}
	virtual void Handle1() = 0;
};

class Context {
private:
	State* state_;
public:
	Context(State* state) : state_(nullptr) {
		this->TransitionTo(state);
	}
	~Context() { delete state_; }
	void TransitionTo(State* state) {
		if (this->state_ != nullptr)
			delete this->state_;
		this->state_ = state;
		this->state_->set_context(this);
	}
	void Request1() {
		this->state_->Handle1();
	}
};

class ReadyState : public State {
public: void Handle1();
};
class RunState : public State {
public: void Handle1();
};
class OffState : public State {
public: void Handle1();
};

void ReadyState::Handle1() {
	cout << "[Ready State] --> [Run State]" << endl;
	this->context_->TransitionTo(new RunState);
};
void RunState::Handle1() {
	cout << "[Run State] --> [Off State]" << endl;
	this->context_->TransitionTo(new OffState);
};
void OffState::Handle1() {
	cout << "[Off State] --> [Ready State]" << endl;
	this->context_->TransitionTo(new ReadyState);
};

int main() {
	Context* context = new Context(new OffState);
	context->Request1();
	context->Request1();
	context->Request1();
	return 0;
}