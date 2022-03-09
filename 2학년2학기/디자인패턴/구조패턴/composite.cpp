#include<iostream>
#include <list> 
using namespace std;

class Component {
protected:
	Component* parent_;
public:
	void SetParent(Component* parent) {
		this->parent_ = parent;
	}
	Component* GetParent() const {
		return this->parent_;
	}
	virtual void Add(Component* component) {}
	virtual bool IsComposite() {
		return false;
	}
	virtual string Operation() = 0;
};

class Leaf : public Component {
public:
	string Operation() {
		return "Leaf";
	}
};

class Composite : public Component {
protected:
	list<Component*> children_;
public:
	void Add(Component* component) {
		this->children_.push_back(component);
		component->SetParent(this);
	}
	bool IsComposite() {
		return true;
	}
	string Operation() {
		std::string result;
		for (Component* c : children_) {
			if (c == children_.back()) result += c->Operation();
			else result += c->Operation() + "+";
		}
		return "Branch(" + result + ")";
	}
};

int main() {
	Component* c0 = new Composite;
	Component* l1 = new Leaf;
	Component* c1 = new Composite;

	c0->Add(l1);
	c0->Add(c1);

	cout << c0->Operation() << endl;

	return 0;
}