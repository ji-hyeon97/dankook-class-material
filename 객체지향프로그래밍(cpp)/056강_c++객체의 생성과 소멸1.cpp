//������: ��ü�� ������ �� �ڵ����� ȣ��Ǵ� �Լ�
//�Ҹ���: ��ü�� �Ҹ�� �� �ڵ����� ȣ��Ǵ� �Լ�

#include<iostream>

using namespace std;

class MyClass {
public:
	MyClass() { //������
		cout << "�����ڰ� ȣ��Ǿ���!" << endl;
	}

	~MyClass() { //�Ҹ���
		cout << "�Ҹ��ڰ� ȣ��Ǿ���!" << endl;
	}
};

//MyClass globalObj;

void testLocalObj() {
	cout << "testLocalObj �Լ� ����!!" << endl;
	MyClass localObj;
	cout << "testLocalObj �Լ� ��!!" << endl;

}

int main() {
	cout << "main�Լ� ���� !!" << endl;
	testLocalObj();
	cout << "main�Լ� �� !!" << endl;
}