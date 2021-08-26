#include<iostream>
using namespace std;

class complex {
public:
	complex() : real(0),imag(0) {}//간단한 생성자 정의(초기화 목록) 멤버변수만 정의가능
	complex(double real_, double imag_) {
		real = real_;
		imag = imag_;
	}
	double GetReal() {
		return real;
	}
	double SetReal(double real_) {
		real = real_;
	}
	double GetImag() {
		return imag;
	}
	double SetImag(double imag_) {
		imag = imag_;
	}
private:
	double real;
	double imag;
};

int main() {
	complex c1;
	complex c2 = complex(2,3);
	complex c3(2, 3);
	complex c4 = { 2,3 };
	complex c5 = complex{ 2,3 };
	complex c6{ 2,3 };

	cout << "c1 = " << c1.GetReal() << ", " << c1.GetImag() << endl;
	cout << "c2 = " << c2.GetReal() << ", " << c2.GetImag() << endl;
	cout << "c3 = " << c3.GetReal() << ", " << c3.GetImag() << endl;
}