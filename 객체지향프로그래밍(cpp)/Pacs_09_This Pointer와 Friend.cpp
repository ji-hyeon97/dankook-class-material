/*
this Pointer�� ��ü�� ����Լ��� ȣ���� �� �ڵ����� ����Լ����� ���޵Ǵ� �������̸�, ȣ���� ��ü��
����Ű�� �����͸� ���Ѵ�. ���� �ڱ� ���� ������(�ڱ� �ڽ��� ����ų �� �ִ� ������)��� �Ҹ����,
��� �Լ����Ը� this pointer�� ���޵ȴ�.
(Friend �Լ��� ��� �Լ��� �ƴϹǷ� this pointer�� ���޵��� �ʴ´�) �Ʒ��� ������ ���� �ݹ� ����
�ð��̴�.

#include<iostream>

using namespace std;

class Person {
public:
	Person * GetThis() {
		return this;
	}
};

int main() {
	Person *p1 = new Person();
	cout << "������ p1 : " << p1 << endl;
	cout << "p1�� this : " << p1->GetThis() << endl << endl;

	Person *p2 = new Person();
	cout << "������ p2 : " << p2 << endl;
	cout << "p2�� this : " << p2->GetThis() << endl;

	return 0;
}

Friend : �Ϲ������� Ŭ������ ��������(private)�� �ܺ��Լ����� ������ �� ����. private ����, �Լ���
��� �Լ������� ������ �����ϱ� �����̴�. �׷��� ����Լ��� �ƴ� �ܺ��Լ����� �����ؾ� �� ��찡
�߻��� �� �ִ�. �׷��� ��Ÿ���� friend��� �����̴�. �׷� ��� Ŭ�������� friend�Լ��� ������ �ָ� 
�ܺ��Լ��̸鼭 Ŭ������ ����� ����� �����Ҽ� �ִ� ������ ���� �ȴ�

#include<iostream>

using namespace std;

class Counter {
private:
	int val;

public:
	Counter() {
		val = 0;
	}

	void Print() const {
		cout << val << endl;
	}

	friend void SetX(Counter& c, int val); //friend ����
};

void SetX(Counter &c, int val) { //�����Լ�
	c.val = val;
}

int main() {
	Counter cnt;
	cnt.Print();

	SetX(cnt, 2002);
	cnt.Print();

	return 0;
}
*/
#include<iostream>
using std::cout;
using std::endl;

class AAA {
private:
	int data;
	friend class BBB; //class BBB�� friend�� ������ !
};

class BBB {
public:
	void SetData(AAA& aaa, int val) {
		aaa.data = val; //Ŭ���� AAA�� private ���� ���� !
	}
};

int main() {
	AAA aaa;
	BBB bbb;

	bbb.SetData(aaa, 10);
	return 0;
}
/*
�� �� ������ ���� ���� ����� ���ؼ��� ������ �� ���� �˾� �� �� �ִ�. friend�� �Լ�, Ŭ������
�����ؼ� �� �� �ִ�. friend�� ������ Ư¡�� ���� ���� �Ʒ� 4���� ������ ����� �� �ִ�.

1. Ŭ������ friend Ű����� �Բ� ������ ��� �ؾ� �Ѵ�
2. ��� ���� �ʴ´�.
3. friend �Լ��� Ŭ������ ����� �ƴ϶� �Ϲ��Լ��̴�. (��� ���� �����ڷ� �������� �ʴ´�.)
4. ���� ���Ǵ� ���� ������ �ߺ� ����, �ϳ��� �Լ����� �ٸ� Ŭ�������� ����� ����� ���ٽ� ���ȴ�.(��������)

�������� : �� �� �̻��� Ŭ������ ���ÿ� �����ϴ� ���� �������� �Ұ����ϹǷ� �����Ϸ����� �̸� �� Ŭ������ ������ �˸�

���� friend�� oop�� ĸ��ȭ�� ���������� ��ģ�ٴ� �̾߱Ⱑ ������, ��ټ��� ��� friend��
����� ������ �ٿ������μ� ĸ��ȭ�� �� �̷ο� ������ ������.(public ����� �������� ĸ��ȭ�� ��������)
friend�� ���ϱ� ���� ���������� public ����� �߰��Ѵٸ� �װ��� ������ oop�� �ǿ����� ������.
*/