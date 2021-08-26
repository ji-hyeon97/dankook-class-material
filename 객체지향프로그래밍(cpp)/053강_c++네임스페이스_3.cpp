#include<iostream>

int n;
void set() {
	n = 10;
}

namespace doodle {
	int n;
	void set() {
		n = 20;
	}
	namespace google {
		int n;
		void set() {
			n = 30;
		}
	}
}
int main() {
	using namespace std;
	using namespace doodle;

	::set();// 전역설정(오버로드)
	doodle::set();//namespace설정(오버로드)
	google::set();//doodle생략가능
	
	cout << ::n << endl;
	cout << doodle::n << endl;
	cout << doodle::google::n << endl;
}