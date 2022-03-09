#include<iostream>
#include <list> 
#include<string>
#include<unordered_map>
using namespace std;

struct SharedState
{
	string type_, color_;
	SharedState(const string& type, const string& color)
		: type_(type), color_(color) { }
	friend ostream& operator<<(ostream& os, const SharedState& ss)
	{
		return os << "[ " << ss.type_ << " , " << ss.color_ << " ]";
	}
};
struct UniqueState
{
	string price_;
	UniqueState(const string& price) : price_(price) { }
	friend ostream& operator<<(std::ostream& os, const UniqueState& us)
	{
		return os << "[ " << us.price_ << " ]";
	}
};

class Flyweight
{
private:
	SharedState* shared_state_;
public:
	Flyweight(const SharedState* shared_state) : shared_state_(new SharedState(*shared_state)) { }
	Flyweight(const Flyweight& other) : shared_state_(new SharedState(*other.shared_state_)) { }
	SharedState* shared_state() const { return shared_state_; }
	void Operation(const UniqueState& unique_state) const
	{
		cout << "Flyweight: Displaying shared (" << *shared_state_
			<< ") and unique (" << unique_state << ") state." << endl;
	}
};

class FlyweightFactory
{
private:
	unordered_map<string, Flyweight> flyweights_;
	string GetKey(const SharedState& ss) const { return ss.type_ + "_" + ss.color_; }
public:
	FlyweightFactory(std::initializer_list<SharedState> share_states)
	{
		for (const SharedState& ss : share_states)
			this->flyweights_.insert(make_pair<string, Flyweight>(this->GetKey(ss), Flyweight(&ss)));
	}
	Flyweight GetFlyweight(const SharedState& shared_state)
	{
		string key = this->GetKey(shared_state);
		if (this->flyweights_.find(key) == this->flyweights_.end())
			this->flyweights_.insert(make_pair(key, Flyweight(&shared_state)));
		return this->flyweights_.at(key);
	}
	void ListFlyweights() const
	{
		size_t count = this->flyweights_.size();
		for (pair<string, Flyweight> pair : this->flyweights_) cout << pair.first << "\n";
	}
};

void AddItem(
	FlyweightFactory& ff, const string& price,
	const string& type, const string& color)
{
	cout << "Adding an item to DB." << endl;;
	const Flyweight& flyweight = ff.GetFlyweight({ type, color });
	flyweight.Operation({ price });
}

int main()
{
	FlyweightFactory* factory = new FlyweightFactory({ {"Americano", "black" }, { "Mocha", "white" } });
	factory->ListFlyweights();
	AddItem(*factory, "5000", "Americano", "black");
	AddItem(*factory, "6000", "Mocha", "white");
	AddItem(*factory, "4000", "Espresso", "black");
	factory->ListFlyweights();
	return 0;
}