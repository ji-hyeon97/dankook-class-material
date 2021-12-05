#include<iostream>
#include <list> 
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

class Memento {
public:
	virtual int getState() const = 0;
};

class ConcreteMemento : public Memento {
private:
	int state_;
public:
	ConcreteMemento(int state) : state_(state) {
		this->state_ = state;
	}
	int getState() const {
		return this->state_;
	}
};

class Originator {
private:
	int state_;
public:
	Originator(int state) : state_(state) {
		cout << "Current State: " << this->state_ << endl;
	}
	void DoSomething() {
		this->state_ += rand() % 10;
		cout << "State has been changed to: " << this->state_ << endl;
	}
	Memento* Save() {
		return new ConcreteMemento(this->state_);
	}
	void Restore(Memento* memento) {
		this->state_ = memento->getState();
		cout << "State has been changed to: " << this->state_ << endl;
	}
};

class Caretaker {
private:
	std::vector	<Memento*> mementos_;
	Originator* originator_;
public:
	Caretaker(Originator* originator) : originator_(originator) {
		this->originator_ = originator;
	}
	void Backup() {
		cout << "Saving state...\n";
		this->mementos_.push_back(this->originator_->Save());
	}
	void Undo() {
		if (!this->mementos_.size()) {
			return;
		}
		Memento* memento = this->mementos_.back();
		this->mementos_.pop_back();
		std::cout << "Restoring state to: " << memento->getState() << endl;
		try {
			this->originator_->Restore(memento);
		}
		catch (...) {
			this->Undo();
		}
	}
};

int main() {
	srand(static_cast<unsigned int>(std::time(NULL)));
	Originator* originator = new Originator(0);
	Caretaker* caretaker = new Caretaker(originator);
	caretaker->Backup();
	originator->DoSomething();
	caretaker->Backup();
	originator->DoSomething();
	caretaker->Undo();
	caretaker->Undo();
	return 0;
}