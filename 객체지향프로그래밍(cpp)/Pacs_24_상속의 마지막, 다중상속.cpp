//���� ����̶�?
#include<iostream>
using namespace std;

class AAA {
public:
	void String1() {
		cout << "AAA::String1" << endl;
	}
};

class BBB {
public:
	void String2() {
		cout << "BBB::String2" << endl;
	}
};

class CCC : public AAA, public BBB {
public:
	void ShowString() {
		String1();
		String2();
	}
};

int main() {
	CCC ccc;
	ccc.ShowString();

	return 0;
}

//���� �ҽ� �ڵ常 ���� ���� �� ���̴�. ���� ����̶� 19��° ��ó�� �� �̻��� Ŭ������ ���ÿ� ����ϴ� ���̴�.
//���� ����� ��ȣ��
/*
#include<iostream>
using namespace std;

class AAA {
public:
	void String() {
		cout << "AAA::String" << endl;
	}
};

class BBB {
public:
	void String() {
		cout << "BBB::String" << endl;
	}
};

class CCC : public AAA, public BBB {
public:
	void ShowString() {
		String(); //AAA::String();
		String(); //BBB::String();
	}
};

int main() {
	CCC ccc;
	ccc.ShowString();

	return 0;
}
���� �ҽ� �ڵ�� ���� ���� ����� ���迡�� AAA, BBBŬ������ ���� �̸��� ���� ��� �Լ��� �ִٰ� �ϸ�, �̶� ��ȣ����
�߻��Ѵ�. ���� �� String �Լ��� ��� ��ü�� �Լ��� ȣ���� �ִ� ���̳� �� �� ���� �����̴�. �ּ�ģ �κ�ó�� ���� ���� �����ڸ�
�̿��� ���� �ذ� ����� ������, ���� �ڵ尡 ������ ���� �� �� �� �ִ� ���̴�.
*/