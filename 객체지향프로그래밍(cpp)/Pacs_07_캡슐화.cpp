/* 캡슐화 : 클래스를 정의하는데 있어서 관련있는 데이터 및 함수를 하나로 묶는 것이다. 캡슐화를 함으로써
정보 은닉도 함께 가져오는 효과를 가져오기도 한다. 아래의 캡슐화가 된 예제와 캡슐화가 안된 예제이다 */

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
		cout << "X좌표 입력 오류, 확인 부탁드립니다 ~ " << endl;
		return;
	}
	x = _x;
}

void Point::SetY(int _y) {
	if (_y < 0 || _y>100) {
		cout << "Y좌표 입력 오류, 확인 부탁드립니다 ~ " << endl;
		return;
	}
	y = _y;
}

class PointShow {
public:
	void ShowData(Point p) {
		cout << "X좌표 : " << p.GetX() << endl;
		cout << "Y좌표 : " << p.GetY() << endl;
	}
};

int main() {
	int x, y;
	cout << "좌표 입력 : ";
	cin >> x >> y;
	Point p;
	p.SetX(x);
	p.SetY(y);

	PointShow show;
	show.ShowData(p);

	return 0;
}

예를 들어 클래스를 정의하고 나서 프로젝트가 진행된 상황에서 문제를 발견, 포인트 클래스에다가 자기가 지니고
있는 변수 x,y에 대해 출력하는 기능을 넣어 줘야 되겠구나 생각을 하게 된다고 가정하자. 하지만 이미 Point라는
클래스는 이미 정해져 있고 프로젝트가 이미 진행이 되어 있기 때문에 기존의 클래스를 변경하는 것은 어려운 일이다.
그래서 일반적으로 출력이라는 기능이 없으므로, 이에 대한 기능을 클래스로 정의하게 된다. 포인트 클래스의 객체를
인자로 받아서 리턴되는 데이터를 출력하는 형태로 show라는 객체를 생성하게 되고, 결과는 무리없이 출력이 되지만
캡슐화는 무너졌다고 볼 수 있다. showdata라는 함수는 내가 정의한 포인트 함수의 x,y를 출력하기 위한 함수이므로, 
이것은 포인트에 대한 기능을 가진 것이라고 볼수 있고 showdata라는 함수는 포인트 클래스 안에 존재하게 된다.*/

//캡슐화가 된 예제
//캡슐화를 하는 이유 : 코드의 재활용성을 높이고 에러 발생을 최소화하며 다이나믹한 속성을 높이기 위해 캡슐화 필요
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

	void ShowData(); //캡슐화를 위해 추가된 함수
};

void Point::SetX(int _x) {
	if (_x < 0 || _x>100) {
		cout << "X좌표 입력 오류, 확인 부탁드리겠습니다 ~ ";
		return;
	}
	x = _x;
}

void Point::SetY(int _y) {
	if (_y < 0 || _y>100) {
		cout << "Y좌표 입력 오류, 확인 부탁드리겠습니다 ~ ";
		return;
	}
	y = _y;
}
void Point::ShowData() {
	cout << "x좌표 : " << x << endl;
	cout << "y좌표 : " << y << endl;
}

int main() {
	int x, y;
	cout << "좌표를 입력하세요 : ";
	cin >> x >> y;

	Point p;
	p.SetX(x);
	p.SetY(y);
	p.ShowData();

	return 0;
}