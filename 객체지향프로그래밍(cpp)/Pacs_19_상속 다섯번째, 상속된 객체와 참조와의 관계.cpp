/*
��ü ���۷��� : ��ü�� ���� �� �� �ִ� ���۷����� Ŭ���� ������(��ü ������)�� Ư���� ��ġ �Ѵ�.

#include<iostream>
using namespace std;

class Person {
public:
	void Sleep() {
		cout << "Sleep" << endl;
	}
};

class Student : public Person {
public:
	void Study() {
		cout << "Study" << endl;
	}
};

class ScholarStd : public Student {
public:
	void Receive_Scholar() {
		cout << "Work" << endl;
	}
};

int main() {
	ScholarStd p;
	Student &ref1 = p;
	Person &ref2 = p;
	p.Sleep();
	ref1.Sleep();
	ref2.Sleep();

	return 0;
}

�ռ� ������� is-a ���迡�� � Ŭ������ �����ʹ� �ڽ� ��ü �Ӹ� �ƴ϶�, �ڽ��� ����ϰ� �ִ� Ŭ������ ��ü�� 
����ų���� �ִ�. Person Ŭ������ �����͸� ������, ���� �ڵ忡���� ���� Ŭ���� ��ü�� �� ī��ų �� �ִ�. Person
Ŭ������ ������ ����������, ���� ������ Ŭ������ �� ������ �� �ִ�.
������ ������ �ߴ� ��ü �������� Ư���� ��ġ�ϴ� ���� �� ���ִ�.

��ü ���۷��� ����
*/
#include<iostream>
using namespace std;

class Person {
public:
	void Sleep() {
		cout << "Sleep" << endl;
	}
};

class Student : public Person {
public:
	void Study() {
		cout << "Study" << endl;
	}
};

class PartTimeStd : public Student {
public:
	void Work() {
		cout << "Work" << endl;
	}
};

int main() {
	PartTimeStd p;
	p.Sleep();
	p.Study();
	p.Work();

	Person &ref = p;
	ref.Sleep();
	//ref.Study();  ����
	//ref.Work();  ����

	return 0;
}
/*
��ü�� ���۷��� ���ѵ� ��ü ������ ���Ѱ� ���������̴�. ��ü �����Ͷ��� ���㵵�� �ݺ��ؼ� ����� ������, A Ŭ������ 
������ B��ü��, C��ü�� ���� �� �� �ִµ�, ������ �� �ִ� ������ AŬ�������� ����Ǿ� �ְų�, AŬ������ ����ϰ�
�ִ� ����ν� ���ѵǾ� ����.
*/