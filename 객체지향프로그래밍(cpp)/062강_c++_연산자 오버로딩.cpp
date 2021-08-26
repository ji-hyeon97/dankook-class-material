//연산자 오버로딩
#include<iostream>

using namespace std;

class Vector2 {
public:
	Vector2();
	Vector2(float x, float y) : x(x),y(y){}

	float GetX() const;
	float GetY() const { return y; }

	Vector2 operator+(const Vector2 rhs) const{
		return Vector2(x + rhs.x, y + rhs.y);
	}
	Vector2 operator-(const Vector2 rhs) const {
		return Vector2(x - rhs.x, y - rhs.y);
	}
	Vector2 operator*(const float rhs) const {
		return Vector2(x * rhs, y * rhs);
	}
	float operator*(const Vector2 rhs) const {//벡터끼지의 곱은 실수 반환
		return (x * rhs.x +  y * rhs.y);
	}
	Vector2 operator/(const float rhs) const {// 벡터나누기 벡터는 안됨
		return Vector2(x / rhs, y / rhs);
	}

private:
	float x;
	float y;
};


Vector2 operator*(const float a, const Vector2 b) {
	return Vector2(a*b.GetX(), a*b.GetY());
}

int main() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	Vector2 c1 = a-b;
	Vector2 c2 = a*1.6;
	Vector2 c3 = 1.6 * a;
	float c4 = a * b;

	cout << a.GetX() << " , " << a.GetY() << endl;
	cout << b.GetX() << " , " << b.GetY() << endl;
	cout << c1.GetX() << " , " << c1.GetY() << endl;
	cout << c2.GetX() << " , " << c2.GetY() << endl;
	cout << c3.GetX() << " , " << c3.GetY() << endl;
	cout << c4 << endl;
}

Vector2 ::Vector2() : x(0), y(0) {}
float Vector2::GetX() const{ return x; }