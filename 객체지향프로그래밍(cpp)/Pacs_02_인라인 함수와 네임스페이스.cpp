/* ��ũ�� �Լ� : ��ó���⿡ ���� ó�� �Ǹ鼭, �ſ� ���� ������ ������ ������ �Ǵ� �Լ�
#define Square((x)*(x))

�ζ��� �Լ� : c���� ��ũ�� �Լ��� ������, �ζ��� �Լ��� �����Ϸ��ܿ��� ó���Ǹ鼭, ������ �����ϸ�
�����Ϸ����� ����ȭ ��ȸ�� �����Ѵ�.
inline int Square(int x){
return x*x;
}
*/

/* ���� �����̽� : �̸� �浹�� ���� ���� ������ �̸��� �ִ� ������� �� �� �ִ�
ex) 101���� ��� ö����, 202���� ��� ö����*/

#include<iostream>

namespace A_COM {
	void function(void) {
		std::cout << "A.com���� ������ �Լ�" << std::endl;
	}
}

namespace B_COM {
	void function(void) {
		std::cout << "B.com���� ������ �Լ�" << std::endl;
	}
}

int main(void) {
	A_COM::function();
	B_COM::function();
	return 0;
}