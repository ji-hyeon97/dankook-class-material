#include<iostream>

using namespace std;

int x = 1;

void useLocal(void) {
	int x = 25;
	cout << x << endl;
	x++;
	cout << x << endl;
}

void userStaticLocal(void) {
	static int x = 50;
	cout << x << endl;
	x++;
	cout << x << endl;
}

void userGrobal(void) {
	cout << x << endl;
	x *= 10;
	cout << x << endl;
}

int main() {
	int x = 5;
	cout << x << endl;
	
	{
		int x = 7;
		cout << x << endl;
	}
	useLocal();
	userStaticLocal();
	userGrobal();
	cout << x << endl;
	cout << x << endl;
	return 0;
}