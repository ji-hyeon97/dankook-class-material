#include<iostream>
#include<vector>
using namespace std;

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
};class Product {
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
};class Director {
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
};int main() {
	Director* director = new Director();
	Builder1* builder = new Builder1();
	Product* coffee = NULL;
	director-> set_builder(builder);

	cout << "Making Americano" << endl;
	director-> BuildAmericano();
	coffee = builder-> GetProduct();
	coffee->print();
	cout << endl;

	cout << "Making Espresso" << endl;
	director-> BuildEspresso();
	coffee = builder-> GetProduct();
	coffee->print();

	return 0;
}

/*
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Product
class Pizza
{
private:
    std::string dough;
    std::string sauce;
    std::string topping;

public:
    Pizza() { }
    ~Pizza() { }

    void SetDough(const std::string& d) { dough = d; };
    void SetSauce(const std::string& s) { sauce = s; };
    void SetTopping(const std::string& t) { topping = t; }

    void ShowPizza()
    {
        std::cout << " Yummy !!!" << std::endl
            << "Pizza with Dough as " << dough
            << ", Sauce as " << sauce
            << " and Topping as " << topping
            << " !!! " << std::endl;
    }
};

// Abstract Builder
class PizzaBuilder
{
protected:
    std::auto_ptr<Pizza> pizza;
public:
    PizzaBuilder() {}
    virtual ~PizzaBuilder() {}
    std::auto_ptr<Pizza> GetPizza() { return pizza; }

    void createNewPizzaProduct() { pizza.reset(new Pizza); }

    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
};

// ConcreteBuilder
class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
    HawaiianPizzaBuilder() : PizzaBuilder() {}
    ~HawaiianPizzaBuilder() {}

    void buildDough() { pizza->SetDough("cross"); }
    void buildSauce() { pizza->SetSauce("mild"); }
    void buildTopping() { pizza->SetTopping("ham and pineapple"); }
};

// ConcreteBuilder
class SpicyPizzaBuilder : public PizzaBuilder
{
public:
    SpicyPizzaBuilder() : PizzaBuilder() {}
    ~SpicyPizzaBuilder() {}

    void buildDough() { pizza->SetDough("pan baked"); }
    void buildSauce() { pizza->SetSauce("hot"); }
    void buildTopping() { pizza->SetTopping("pepperoni and salami"); }
};

// Director
class Waiter
{
private:
    PizzaBuilder* pizzaBuilder;
public:
    Waiter() : pizzaBuilder(NULL) {}
    ~Waiter() { }

    void SetPizzaBuilder(PizzaBuilder* b) { pizzaBuilder = b; }
    std::auto_ptr<Pizza> GetPizza() { return pizzaBuilder->GetPizza(); }
    void ConstructPizza()
    {
        pizzaBuilder->createNewPizzaProduct();
        pizzaBuilder->buildDough();
        pizzaBuilder->buildSauce();
        pizzaBuilder->buildTopping();
    }
};

// A customer ordering a pizza.
int main()
{
    Waiter waiter;

    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    waiter.SetPizzaBuilder(&hawaiianPizzaBuilder);
    waiter.ConstructPizza();
    std::auto_ptr<Pizza> pizza = waiter.GetPizza();
    pizza->ShowPizza();

    SpicyPizzaBuilder spicyPizzaBuilder;
    waiter.SetPizzaBuilder(&spicyPizzaBuilder);
    waiter.ConstructPizza();
    pizza = waiter.GetPizza();
    pizza->ShowPizza();

    return EXIT_SUCCESS;
}
*/