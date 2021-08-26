//��������
#include<iostream>

using namespace std;
//int idCounter = 1;
//RGB -> float(0~1)
class Color {
public:
	Color() : r(0), g(0), b(0),id(idCounter++) {		
	}
	Color(float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) {}
	float GetR() {
		return r;
	}
	float GetG() {
		return g;
	}
	float GetB() {
		return b;
	}
	int GetId() {
		return id;
	}
	static Color MixColor(Color a, Color b) { //������� -> privateȰ�밡��
		Color result((a.r + b.r) / 2, (a.g, b.g) / 2, (a.b + b.b) / 2);
		return result;
	}
	static int idCounter;//���������� Ŭ���������� ������ ���·� ���� ����
private:
	float r;
	float g;
	float b;
	int id;
};
int Color::idCounter = 1;

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
	cout << "blue.GetId() = " << blue.GetId() << endl;
	cout << "red.GetId() = " << red.GetId() << endl;
	cout << "purple.GetId() = " << purple.GetId() << endl;
}