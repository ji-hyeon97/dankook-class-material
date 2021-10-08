/*
������ �����ε� : C++ ������ �츮���� ����̶�� �� �� �ִµ�, �츮�� �Լ��� �����ϴµ� �̾
operator��� Ű����� �����ڸ� �ٿ��� �Լ��� �̸��� ���� ��쿡(operator + �̷���) �츮�� �Ϲ�����
�Լ��� ȣ�� �ϴ� ��� ���� �����ڸ��� �̿��ؼ��� �Լ��� ȣ�� �ǵ��� ���ְڴٴ� �̾߱��̴�.

#include<iostream>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0) {
		x = _x;
		y = _y;
	}

	void ShowPosition();

	Point operator+(const Point &p);
};

void Point::ShowPosition() {
	cout << x << " " << y << endl;
}

Point Point ::operator+(const Point &p) {
	Point temp(x + p.x, y + p.y);
	return temp;
}

int main() {
	Point p1(1, 2);
	Point p2(2, 1);
	Point p3 = p1 + p2;
	p3.ShowPosition();

	return 0;
}
�׷� ���� �ҽ� �ڵ� 35��° ���� p1+p2�� � �ǹ̸� ������ �˾� ���� ���⼭ p1, p2�� ��ü �̹Ƿ� �⺻������ '+'���� ������
�Ұ����ϴ�. �׷��� c++������ � ����� �Ͽ����� �ϸ�, '+'��� ��Ģ������ �ҷ��� �ϴ°� �ƴ϶�, �տ� operator��� Ű���带
�ٿ��� p1�� p2�� �̿��ؼ� operator +��� �Լ��� ȣ�����ְ� �Ǵ� ���̴�. �׷��� ���� c++������ 'operator +'��� �Լ��� ȣ�� �ؾ� �ϴµ�, 
C++������ �Լ��� ����� ���, ��� �Լ�, ���� �Լ� 2������ �ִ�. �׷��Ƿ� 'operator+'��� �� �ѷ� ���� �� �� �ִ� ���̴�. �츮�� �����
�����, �������� ����� C++�� 'operator +'�� ���� �˾Ƽ� ó������ �� �ִ�. �׷� ��� �Լ��� ���� �����ε��� ��� �Ͼ� ������ �˾ƺ���
35��° ������ p1+p2; �̰��� "���� ������ ���ʿ� ���� ��ü�� operator + �Լ��� ȣ���ϸ鼭, ���׿������� �������� �ǿ����ڸ� ���ڷ� �����Ѵ�"
��� �ǹ̰� �ȴ�. �� p1.operator +(p2); �̷��� �ٲ�ٴ� ���̴�. ���� ������ ������ p1+p2�ڸ��� temp��� �̸��� ��ü�� ���纻�� ��ȯ�Ǹ鼭
��� ���� �ȴ�. �׸��� ��ȯ�Ȱ��� p3�� �ʱ�ȭ���ش� ���⼭ temp��� ��ü�� ������ Ŭ������ ��ü�̹Ƿ�, �� ��� ���� �����ڰ� ȣ�� �Ǵ� �͵� 
�� �� �ִ�. temp�Լ��� ���꿡 ���ؼ� �Ʒ��� ���� ����� ������ ���� �� �� �ִ�.
*/
//�����Լ��� ���� �����ε�
#include<iostream>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0) {
		x = _x;
		y = _y;
	}
	
	void ShowPosition();

	friend Point operator+(const Point& p1, const Point& p2);
};

void Point::ShowPosition() {
	cout << x << " " << y << endl;
}

Point operator+(const Point &p1, const Point &p2) { //�����Լ�
	Point temp(p1.x + p2.x, p1.y + p2.y);
	return temp;
}

int main() {
	Point p1(1, 2);
	Point p2(2, 1);
	Point p3 = p1 + p2;
	p3.ShowPosition();

	return 0;
}
/*
���� �ҽ��ڵ�� �����Լ��� friend �������ְ� �ִ�. friend ������ �������μ�, operator+ �Լ��� ������ Ŭ����
��ü�� private����� ���� ������ �����ϴ�.(friend�� ������ �����ε��� �ַ� ���ȴ�.) �׷� �����Լ�����
p1+p2; �� C++�� ��ӿ� ���� � ������ �ؼ��� �Ǵ� ���ϱ�? �ٷ� �Ʒ��� ���� �ؼ��ȴ�. operator+(p1,p2);
�����Լ��� �Լ� �̸��� �־ ȣ���� �����ϹǷ�, ���� ���� ������ �ؼ��Ǵ� ���� �� �� �ִ�. ������� ����Լ�,
�����Լ��� ���� �����ε��� �˾� �ô�.
*/