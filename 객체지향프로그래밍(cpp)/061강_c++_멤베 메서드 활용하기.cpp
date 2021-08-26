//벡터
//멤버 메서드의 선언, 정의 분리하기
#include<iostream>

using namespace std;

class Vector2 {
public:
	Vector2();
	Vector2(float x, float y) : x(x),y(y){}

	float GetX() const;
	float GetY() const { return y; }
	static Vector2 sum(Vector2 a, Vector2 b) { //정적 선언
		return Vector2(a.x + b.x, a.GetY() + b.GetY());
	}

	Vector2 Add(Vector2 rhs) { //동적 선언
		return Vector2(x + rhs.x, y + rhs.y);
	}

private:
	float x;
	float y;
};

/*
Vector2 sum(Vector2 a, Vector2 b) {
	return Vector2(a.GetX() + b.GetX(), a.GetY() + b.GetY());
}*/

int main() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	Vector2 c1 = Vector2::sum(a,b);
	Vector2 c2 = a.Add(b);
	cout << a.GetX() << " , " << a.GetY() << endl;
	cout << b.GetX() << " , " << b.GetY() << endl;
	cout << c1.GetX() << " , " << c1.GetY() << endl;
	cout << c2.GetX() << " , " << c2.GetY() << endl;

}

Vector2 ::Vector2() : x(0), y(0) {}
float Vector2::GetX() const{ return x; }