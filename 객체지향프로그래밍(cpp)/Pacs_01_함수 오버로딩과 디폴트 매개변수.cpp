/* �Լ� �����ε� : ������ �̸��� �Լ��� �ߺ��ؼ� �����ϴ� �� �� �Ű������� ������ �޶�� ��
c������ �Լ��� �̸��� �ߺ��� ������� �ʾҴµ� �� ������ c���� �Լ��� ȣ���Ҷ�, �Լ���
�̸��������� ������ ȣ���Լ��� ã�� �����Դϴ�. ������, c++������ ȣ���� �Լ��� ã�µ� �־,
�̸��Ӹ� �ƴ϶� �Ű������� ������ �����ϰ� �ֱ� ������ �̷� ����� ���� �մϴ�.

int fuction(int n){}
int function(char c){}
int function(int n, char c){}
*/

/* ����Ʈ �Ű����� :C++�� �Լ��� ���� �� �ϳ��� Ư¡�� �ٷ� ����Ʈ �Ű�������� �� �Դϴ�. 
����Ʈ �Ű������� ���޵��� �ʴ� ���ڸ� ����ϱ� ���� �⺻���� �����Ǿ� �ִ� �����Դϴ�. �Ʒ���
���� �Լ����� () �� ���� ����Ʈ �Ű������� �����Ҽ� �ִ� �κ��Դϴ�.
int function(int a=0 ){ return a+1;} */

#include<iostream>

int BoxVolumn(int length, int width = 1, int height = 1); //�� ���� �����ؾ� ��

int main() {
	std::cout << "[3,3,3]    : " << BoxVolumn(3, 3, 3) << std::endl;
	std::cout << "[5,5,def]  : " << BoxVolumn(5, 5) << std::endl;
	std::cout << "[7,def,def]: " << BoxVolumn(7) << std::endl;
	return 0;
}

int BoxVolumn(int length, int width, int height) {
	return length * height*width;
}