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

	::set();// ��������(�����ε�)
	doodle::set();//namespace����(�����ε�)
	google::set();//doodle��������
	
	cout << ::n << endl;
	cout << doodle::n << endl;
	cout << doodle::google::n << endl;
}