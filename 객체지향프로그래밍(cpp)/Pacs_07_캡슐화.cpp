/* ĸ��ȭ : Ŭ������ �����ϴµ� �־ �����ִ� ������ �� �Լ��� �ϳ��� ���� ���̴�. ĸ��ȭ�� �����ν�
���� ���е� �Բ� �������� ȿ���� �������⵵ �Ѵ�. �Ʒ��� ĸ��ȭ�� �� ������ ĸ��ȭ�� �ȵ� �����̴� */

/*
#include<iostream>

using namespace std;

class Point {
private:
	int x;
	int y;

public:
	int GetX() {
		return x;
	}

	int GetY() {
		return y;
	}

	void SetX(int _x);
	void SetY(int _y);
};

void Point::SetX(int _x) {
	if (_x < 0 || _x>100) {
		cout << "X��ǥ �Է� ����, Ȯ�� ��Ź�帳�ϴ� ~ " << endl;
		return;
	}
	x = _x;
}

void Point::SetY(int _y) {
	if (_y < 0 || _y>100) {
		cout << "Y��ǥ �Է� ����, Ȯ�� ��Ź�帳�ϴ� ~ " << endl;
		return;
	}
	y = _y;
}

class PointShow {
public:
	void ShowData(Point p) {
		cout << "X��ǥ : " << p.GetX() << endl;
		cout << "Y��ǥ : " << p.GetY() << endl;
	}
};

int main() {
	int x, y;
	cout << "��ǥ �Է� : ";
	cin >> x >> y;
	Point p;
	p.SetX(x);
	p.SetY(y);

	PointShow show;
	show.ShowData(p);

	return 0;
}

���� ��� Ŭ������ �����ϰ� ���� ������Ʈ�� ����� ��Ȳ���� ������ �߰�, ����Ʈ Ŭ�������ٰ� �ڱⰡ ���ϰ�
�ִ� ���� x,y�� ���� ����ϴ� ����� �־� ��� �ǰڱ��� ������ �ϰ� �ȴٰ� ��������. ������ �̹� Point���
Ŭ������ �̹� ������ �ְ� ������Ʈ�� �̹� ������ �Ǿ� �ֱ� ������ ������ Ŭ������ �����ϴ� ���� ����� ���̴�.
�׷��� �Ϲ������� ����̶�� ����� �����Ƿ�, �̿� ���� ����� Ŭ������ �����ϰ� �ȴ�. ����Ʈ Ŭ������ ��ü��
���ڷ� �޾Ƽ� ���ϵǴ� �����͸� ����ϴ� ���·� show��� ��ü�� �����ϰ� �ǰ�, ����� �������� ����� ������
ĸ��ȭ�� �������ٰ� �� �� �ִ�. showdata��� �Լ��� ���� ������ ����Ʈ �Լ��� x,y�� ����ϱ� ���� �Լ��̹Ƿ�, 
�̰��� ����Ʈ�� ���� ����� ���� ���̶�� ���� �ְ� showdata��� �Լ��� ����Ʈ Ŭ���� �ȿ� �����ϰ� �ȴ�.*/

//ĸ��ȭ�� �� ����
//ĸ��ȭ�� �ϴ� ���� : �ڵ��� ��Ȱ�뼺�� ���̰� ���� �߻��� �ּ�ȭ�ϸ� ���̳����� �Ӽ��� ���̱� ���� ĸ��ȭ �ʿ�
#include<iostream>

using namespace std;

class Point {
private:
	int x;
	int y;

public:
	int GetX() {
		return x;
	}

	int GetY() {
		return y;
	}

	void SetX(int _x);
	void SetY(int _y);

	void ShowData(); //ĸ��ȭ�� ���� �߰��� �Լ�
};

void Point::SetX(int _x) {
	if (_x < 0 || _x>100) {
		cout << "X��ǥ �Է� ����, Ȯ�� ��Ź�帮�ڽ��ϴ� ~ ";
		return;
	}
	x = _x;
}

void Point::SetY(int _y) {
	if (_y < 0 || _y>100) {
		cout << "Y��ǥ �Է� ����, Ȯ�� ��Ź�帮�ڽ��ϴ� ~ ";
		return;
	}
	y = _y;
}
void Point::ShowData() {
	cout << "x��ǥ : " << x << endl;
	cout << "y��ǥ : " << y << endl;
}

int main() {
	int x, y;
	cout << "��ǥ�� �Է��ϼ��� : ";
	cin >> x >> y;

	Point p;
	p.SetX(x);
	p.SetY(y);
	p.ShowData();

	return 0;
}