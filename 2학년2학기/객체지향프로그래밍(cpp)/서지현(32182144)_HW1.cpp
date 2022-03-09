#include <iostream>
#include<string>
using namespace std;

class hw1 {
private:
	int n;
	int index;
	float change;
	float *vector;

public:
	void create() {
		cout << "������ ���� ������ �Է��ϼ���(�� 1�� �̻�) : ";
		cin >> n;
		if (n <= 0) {
			cout << "�߸� �Է��Ͽ����ϴ�. â�� ���� �ٽý����� �ּ���";
		}
		vector = new float[n];// Dynamic memomry allocation ������ �̿��� ���ҽ��ϴ�

		for (int i = 0; i < n; i++) {
			cout << i << "��° ���� : ";
			cin >> vector[i];
		}
		return;
	}

	void modify() {
		cout << "�Է��� ���� �� ��° ���� �����ϰ� ������ ����?" << endl;

		cin >> index;
		cout << "� ������ �ٲٰ� ������ ���� ?" << endl;

		cin >> change;
		vector[index] = change;

		cout << "�Է��� ���� �����ϰ� ���� ���� �� ������ ���� ? (yes �Ǵ� no �� ����� �ּ��� !)" << endl;
		string repeat;
		cin >> repeat;
		if (repeat == "yes") {
			return modify();
		}
		return;
	}

	void multiply(float &scalar) {// call-by-reference������ �̿��� ���ҽ��ϴ�.
		for (int i = 0; i < n; i++) {
			vector[i] = vector[i] * scalar;
		}
		return;
	}

	void display() { //pdf�� ����d�� ������ ��������� ������ �����ϴ�.
		cout << endl;
		cout << "������ ������ �����帮�ڽ��ϴ�." << endl;
		cout << "(";
		for (int i = 0; i < n; i++) {
			cout << vector[i] << ", ";
		}
		cout << " ...)";
		delete[] vector;//memory release
		return;
	}
};

int main() {
	hw1 h;//�ν��Ͻ� ����
	h.create();
	h.modify();
	float scalar;
	cout << "���ϰ� ���� ���� �Է��ϼ��� : ";
	cin >> scalar;
	h.multiply(scalar);
	h.display();
	return 0;
}

/*

<test code>

������ ���� ������ �Է��ϼ���(�� 1�� �̻�) : 5
0��° ���� : 1.1
1��° ���� : 2.2
2��° ���� : 3.3
3��° ���� : 4.4
4��° ���� : 5.5
�Է��� ���� ���° ���� �����ϰ� ������ ����?
0
� ������ �ٲٰ� ������ ���� ?
1
�Է��� ���� �����ϰ� ���� ���� �� ������ ���� ? (yes �Ǵ� no �� ����� �ּ��� !)
yes
�Է��� ���� ���° ���� �����ϰ� ������ ����?
1
� ������ �ٲٰ� ������ ���� ?
2
�Է��� ���� �����ϰ� ���� ���� �� ������ ���� ? (yes �Ǵ� no �� ����� �ּ��� !)
no
���ϰ� ���� ���� �Է��ϼ��� : 10

������ ������ �����帮�ڽ��ϴ�.
(10, 20, 33, 44, 55,  ...)

C:\Users\������\source\repos\seoji\Debug\seoji.exe(���μ��� 14128��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...

<unit code>

(a) to create a vector : create �Լ����� �����Ҵ��� �Ͽ� vector�� �����Ͽ����ϴ�.
(b) to modify the value of a given element : modify�Լ��� ���� �����Ͽ����ϴ�.
(c) to multiply by a scalar value : multiply �Լ����� call-by-reference������ Ȱ���߽��ϴ�.
(d) to display the vector in the form (10, 20, 30, ��) : display�Լ��� ���� �����Ͽ����ϴ�.

main�Լ����� h��� �ν��Ͻ��� �������־��� �̷� ���� hw1Ŭ������ public�κ��� �����Ӱ� �����ϸ�
������ �Լ��� �ǵ��� ��� �� �۵��մϴ�.

�����մϴ� !

*/
