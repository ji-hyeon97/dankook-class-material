//클래스의 private 멤버까지 접근 가능한 정적 멤버 메소드
#include<iostream>

using namespace std;

//RGB -> float(0~1)
class Color {
public:
	Color() : r(0), g(0), b(0) {}
	Color(float r, float g, float b) : r(r), g(g), b(b){}
	float GetR() {
		return r;
	}
	float GetG() {
		return g;
	}
	float GetB() {
		return b;
	}
	static Color MixColor(Color a, Color b) { //정적멤버 -> private활용가능
		Color result((a.r + b.r) / 2, (a.g, b.g) / 2, (a.b + b.b) / 2);
		return result;
	}
private:
	float r;
	float g;
	float b;
};

/*Color MixColor(Color a, Color b) {
	Color result((a.GetR() + b.GetR()) / 2, (a.GetG(), b.GetG()) / 2, (a.GetB() + b.GetB()) / 2);
	return result;
}*/

int main() {
	Color blue(0, 0, 1);
	Color red(1, 0, 0);
	Color purple = Color::MixColor(blue, red);

	cout << "r = " << purple.GetR() << endl;
	cout << "g = " << purple.GetG() << endl;
	cout << "b = " << purple.GetB() << endl;
}