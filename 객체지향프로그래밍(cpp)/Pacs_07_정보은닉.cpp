/* c++정보은닉과 캡슐화 : 프로그램을 사용하는 사용자가 알아야 하는 것은 프로그램 사용법이지 프로그램의 내부 동작이나
상세 구조가 아니다. 사용자가 굳이 알 필요가 없는 정보는 숨김으로써 사용자는 최소한의 정보만으로 프로그램을 쉽게 사용할수 있어야 한다
c++에서는 클래스의 정보 은폐 기능을 지원하기 위해 private, public, protected 등의 접근제어 키워드를 통해 선언된 클래스
외부에서 직접적인 접근을 허용하지 않는 것을 정보은닉이라고 한다
하지만 간접적 접근 경로를 제공해주어야 한다. 숨길 멤버와 공개할 멤버의 블록을 구성하여 공개된 멤버는
외부에서 자유롭게 읽을 수 있지만, 숨겨진 멤버를 참고하려고 시도하면 컴파일 과정에서 접근할수 없다는 에러를 처리하면 된다

캡슐과된 코드를 제공할때 함부로 건드려서는 안되는 코드들을 보호하기 위해 프로그램의 안정적 구현을 위해서 정보은닉 필요*/

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

	void SetX(int _x) {
		x = _x;
	}

	void SetY(int _y) {
		y = _y;
	}
};

int main() {
	int x, y;
	cout << "좌표를 입력해 주세요 : ";
	cin >> x >> y;

	Point p;
	p.SetX(x);
	p.SetY(y);

	cout << "입력 된 데이터를 이용해서 그림을 그림" << endl;
	cout << p.GetX() << " " << p.GetY() << endl;
	return 0;
}