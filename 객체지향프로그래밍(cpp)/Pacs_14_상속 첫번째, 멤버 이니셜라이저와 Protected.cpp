/*
#include <iostream>
#include<string>
using namespace std;

class Person{
	int age;
	string name;
public:
	int GetAge() const {
		return age;
		}
	string GetName()const{
		return name;
		}

Person(int _age=1, string _name= "noname"){
	age=_age;
	name = _name;
	}
};

class Student : public Person{

	string major; //����
public:
	Student(string _major) {
		major = _major;
	}
	string GetMajor() const {
		return major;
	}

	void ShowData() {
		cout<<"�̸�: "<<GetName()<<endl;
		cout<<"����: "<<GetAge()<<endl;
		cout<<"����: "<<GetMajor()<<endl;
		}
};

int main(void){
	Student Kim("computer");
	Kim.ShowData();

	return 0;
};
���� �ҽ� �ڵ� �������� ���ڸ� main���� ��ü ������ �ϴ� Student Kim ��ü���� �ϴ� ���� ����
�̸��� Kim���� ������ �� �ִ�. �㳪 ���⼭ ���̿� ������ �츮�� ���ϴ� ���·� �ʱ�ȭ ���� ���Ѵٴ�
���� �ٷ� �������̴�, ��, Student Ŭ���� ��ü�� �����ɶ�, �ڽ��� ����� �����ڳ����� �ʱ�ȭ �ϰ�
������, Person Ŭ������ ����� default������ �ʱ�ȭ �ǰ� �ִ°� ������� �� ���ִ�.
��� �ڵ带 ���� ����, showdata �Լ� ������ GetName�̶�� �Լ��� ȣ�� �ϰ� �ִµ�, Student
Ŭ������������ GetName�̶�� �Լ��� ������, �̰��� ȣ�� �� ���ִ� ������ Student Ŭ������ Person
Ŭ������ ����ϰ� �ֱ� ������ Person�� GetName�̶�� �Լ��� �־ �̷� ȣ���� ������ ���̴�.

������ ���ƿͼ�, Student Ŭ������ Person�� ��� �����鵵 Student Ŭ������ ����� ��ӵǾ� ���ϱ�
�ƿ� Student Ŭ������ ������ ��, ���ڰ����� ���̿� �̸��� �ʱ�ȭ�ؼ� Default�� �ʱ�ȭ �Ǵ� ���� ����
�غ��ڴ� ���̴�.

Student(int _age, string _name, string _major) {
	age = _age;
	name = _name;
	major = _major;
}
���� ���� Student �����ڿ��� age�� name�� �ʱ�ȭ ���ָ� �� ���̴�. ������ Person ������� private����
����Ǿ� ������ ���� ���� �ڵ��� �ϸ� ������ ������ �� ���̴�. �� �̷� ������ ���� ���ϱ�? ���
Person Ŭ���� ����� Student Ŭ������ ���� ��ӵǾ� ������, Person Ŭ������ ������� private�̱�
������ PersonŬ���� �������� ���� ���� �ϱ� �����̴�. �׷��ٰ� �� ������ �ذ��ϱ� ���� public���� 
��� �������� �����ϸ� ������ �ذ�ǰ����� ��ü������ ���������� �������� ����� ���� ���̴�. �׷��� 
�ʿ��� �� �ٷ� ��� �̴ϼȶ�����(member initializer)�̴�. (�Ǵ� �ʱ�ȭ ����Ʈ)

��� �̴ϼȶ�����
Student(int _age, string _name, string _major) : Person(_age, _name) {
	major = _major;
}
���� ��� �̴ϼȶ����������� ��� ������ �ʱ�ȭ�� �̷�� ���� ������� �̸��� ������, ���⿡����
Ŭ���� �̸��� ���Դ�. �� �ǹ̴� _age�� _name�� �� ���� ���ڰ��� ���� �� �ִ� �����ڸ� ȣ���϶�� �ǹ̷�
�ٲ��. ���� �ϼ��� �ڵ�� �����غ���. ������ ���ϴ� ��� ����� �̷� �� �ִ�.
*/
#include<iostream>
#include<string>
using namespace std;

class Person {
	int age;
	string name;

public:
	int GetAge() const {
		return age;
	}

	const string GetName() const {
		return name;
	}

	Person(int _age = 1, string _name = "seo") {
		age = _age;
		name = _name;
	}
};

class Student : public Person {
	string major;

public:
	Student(int _age, string _name, string _major) : Person(_age, _name) {
		major = _major;
	}

	const string GetMajor() const {
		return major;
	}

	void ShowData() const{
		cout << "�̸� : " << GetName() << endl;
		cout << "���� : " << GetAge() << endl;
		cout << "���� : " << GetMajor() << endl;
	}
};

int main() {
	Student Pac(19, "Pacs.tistory.com", "computer");
	Pac.ShowData();

	return 0;
}
/* 
protected�� �������� Ű���� �� �ϳ���, �������� �����ÿ��� �̹� ����� �ٰ� �ִµ�, protected��
private�� ����� ������ ����������, �̰��� ��Ӱ��迡�� ���� ���� �Ļ� Ŭ������ �⺻ Ŭ�������� ������
����������.
class Person {
protected:
	int age;
	string name;

public:
};

����� ���� ���� ���� private ��ſ� protected�� ���ָ� �ǰڴ�. ������ protected�� ���ٰ� �ص� ��� 
�̴ϼȶ������� ���� ���� ���� �����̴�. ����, ��� ������ �̸��� ����Ǿ� ���� ��찡 ����ٰ� �Ѵٸ�,
�� �ٲ� �̸����� �ڽ� Ŭ������ �����̰�, ����� �ϰ� �ִ� Ŭ���������� �̸��� �ٲ�� �ϴ� ������ �����
�ܼ��� �̸��� �ٲٸ� �ȴٰ� �����ϱ� ������, �� Ŭ������ ������ �ٸ� Ŭ������ ������ ���� ���ױ� ������
�ɰ��� ������� �� �� �ִ�.
*/

