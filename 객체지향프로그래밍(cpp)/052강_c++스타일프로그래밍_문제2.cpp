//question2
//���� ��� for���� ����Ͽ� ������ �迭�� ����ϱ�

#include<iostream>

using namespace std;

int main() {
	int arr[2][3] = { {1,2,3},{4,5,6} };

	//������� for�� 2��
	for (int(&ln)[3] : arr) {
		for (int &col : ln) {
			cout << col << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	//�����͸� Ȱ���� for��
	for (int (*ln)[3] = arr; ln < arr + 2; ln++) {
		for (int *c = *ln; c < *ln + 3; c++) {
			cout << *c << " ";
		}
		cout << endl;
	}
}

//question 3
/* ������ ���� �Լ� ���ǿ��� ������ ������ ���� ������ ã������

void drawRectangle(int l, int r, int t, int b){}

void drawRectangle(int w, int h, int x=0, int y=0){}

1�� default�Ű������� ���������� �־�� �Ѵ�
2�� drawRectangle(0,0,0,0)ȣ��� ������ �Լ��� ����





*/