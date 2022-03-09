#include<iostream>
#include <list> 
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

class Strategy {
public:
	virtual void doAlgorithm() const = 0;
};
class ConcreteStrategyA : public Strategy {
public:
	void doAlgorithm() const {
		cout << "Algorithm A is applied" << endl;
	}
};
class ConcreteStrategyB : public Strategy {
	void doAlgorithm() const {
		cout << "Algorithm B is applied" << endl;
	}
};

class Context
{
private:
	Strategy* strategy_;
public:
	Context(Strategy* strategy = nullptr) : strategy_(strategy) { }
	void set_strategy(Strategy* strategy)
	{
		delete this->strategy_;
		this->strategy_ = strategy;
	}
	void makeCoffee() const
	{
		this->strategy_->doAlgorithm();
	}
};

int main()
{
	Context* context = new Context(new ConcreteStrategyA);
	context->makeCoffee();
	context->set_strategy(new ConcreteStrategyB);
	context->makeCoffee();
	return 0;
}