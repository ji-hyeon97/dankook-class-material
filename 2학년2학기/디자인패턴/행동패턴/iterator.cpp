#include<iostream>
#include <list> 
#include<string>
#include<vector>
using namespace std;

class Data{
public:
	Data(int a = 0) : m_data_(a) {}
	void setData(int a) {
		m_data_ =a;
	}
	int getData() {
		return m_data_;
	}
private:
	int m_data_;
};

typedef typename std::vector<Data>::iterator iter_type;

class Iterator {
public:
	Iterator(vector<Data>* p_data) : m_p_data_(p_data) {
		First();
	}
	void First() { 
		m_it_ = m_p_data_->begin(); 
	}
	void Next() { 
		m_it_++; 
	}
	bool IsDone() {
		return (m_it_ == m_p_data_->end()); 
	}
	iter_type Current() { 
		return m_it_; 
	}
private:
	vector<Data>* m_p_data_;
	iter_type m_it_;
};

int main() {
	vector<Data> cont;
	Data a(100), b(1000), c(10000);
	cont.push_back(a);
	cont.push_back(b);
	cont.push_back(c);
	Iterator* it = new Iterator(&cont);
	for (it->First(); !it->IsDone(); it->Next()) {
		std::cout << it->Current()->getData() << std::endl;
	}
	return 0;
}