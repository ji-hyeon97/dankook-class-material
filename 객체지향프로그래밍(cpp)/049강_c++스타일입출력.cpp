#include<iostream>//input,output�쵥����
#include<string>
using namespace std;//�̸����� '��'�� ����
int main() {

	cout << "Hello, World!" << endl; //cout:���, endl:�ٹٲ�
	cout << endl;
	
	int a, b;
	cout << "���� 2���� �Է��� �ּ���" << endl;
	cin >> a >> b;
	cout << a << "+" << b << "=" << a + b << endl;
	cout << endl;

	string str;
	str = "Hello";
	cout << str << endl;
	cout << endl;

	string name;
	cout << "�̸� �Է� :";
	cin >> name;
	string message = "�ȳ��ϼ��� " + name + " ��!";
	cout << message << endl;
}