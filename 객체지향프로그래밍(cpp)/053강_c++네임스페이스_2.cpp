#include<iostream>

using namespace std;
//식별자 검색
int n;
void set() {
	n = 10;
}

namespace doodle {
	int n;
	void set();
	namespace google {
		void set();
		int n;
	}
}

int main() {
	::set();
	doodle::set();
	doodle::google::set();

	cout << ::n << endl;
	cout << doodle::n << endl;
	cout << doodle::google::n << endl;
}

void doodle::set() {
	n = 20;
}

void doodle::google::set() {
	n = 30;
}