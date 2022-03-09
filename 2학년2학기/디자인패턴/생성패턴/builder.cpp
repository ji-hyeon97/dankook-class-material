#include<iostream>
#include<vector>
using namespace std;

class Product {
	vector<string> parts;
public:
	void put(string s) { parts.push_back(s); }
	void print() {
		for (int i = 0; i < parts.size(); i++) {
			if (parts[i] == parts.back())
				cout << parts[i];
			else
				cout << parts[i] << ", ";
		}
		cout << endl;
	}
};

class Builder {
public:
	virtual void Espresso() = 0;
	virtual void Water() = 0;
};

class Builder1 : public Builder {
private:
	Product* product;
public:
	Builder1() { product = new Product(); }
	void Espresso() { product->put("Espresso"); }
	void Water() { product->put("Water"); }

	Product* GetProduct() {
		Product* result = this->product;
		this->product = new Product();
		return result;
	}
};

class Director {
private:
	Builder* builder;
public:
	void set_builder(Builder* builder) {
		this->builder = builder;
	}
	void BuildEspresso() {
		this->builder->Espresso();
	}
	void BuildAmericano() {
		this->builder->Espresso();
		this->builder->Water();
	}
};

int main() {
	Director* director = new Director();
	Builder1* builder = new Builder1();
	Product* coffee = NULL;
	director->set_builder(builder);

	cout << "Making Americano" << endl;
	director->BuildAmericano();
	coffee = builder->GetProduct();
	coffee->print();
	cout << endl;

	cout << "Making Espresso" << endl;
	director->BuildEspresso();
	coffee = builder->GetProduct();
	coffee->print();

	return 0;
}
