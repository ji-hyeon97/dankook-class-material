#include<iostream>

using namespace std;

class Account {
private:
	int money;
public:
	Account() : money(0) {}
	Account(int money) : money(money) {}

	void Deposit(const int d) {
		//d = money;방지
		money += d;
		cout << d << " 원을 예금했다!!" << endl;
	}
	void Draw(const int d) {
		if (money >= d) {
			money -= d;
			cout << d << " 원을 인출했다!!" << endl;
		}
	}
	int viewMoney() const{
		//money++; 방지
		return money;
	}
};
	
int main() {
	Account doodle(200);

	doodle.Deposit(100);
	doodle.Draw(20);

	cout << doodle.viewMoney() << endl;

}
// 매개변수의 상수화(모든 함수)
// 메서드의 상수화(멤버 메서드)