#include<iostream>

using namespace std;

class Account {
private:
	int money;
public:
	Account() : money(0) {}
	Account(int money) : money(money) {}

	void Deposit(const int d) {
		//d = money;����
		money += d;
		cout << d << " ���� �����ߴ�!!" << endl;
	}
	void Draw(const int d) {
		if (money >= d) {
			money -= d;
			cout << d << " ���� �����ߴ�!!" << endl;
		}
	}
	int viewMoney() const{
		//money++; ����
		return money;
	}
};
	
int main() {
	Account doodle(200);

	doodle.Deposit(100);
	doodle.Draw(20);

	cout << doodle.viewMoney() << endl;

}
// �Ű������� ���ȭ(��� �Լ�)
// �޼����� ���ȭ(��� �޼���)