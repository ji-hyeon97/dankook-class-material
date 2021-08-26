#include<iostream>

using namespace std;

//생성자: 멤버 변수 초기화
//복소수(real,imag)

class complex {
public:
	complex() {
		real = 0;
		imag = 0;
	}
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
	complex c2 = complex(2, 3);
	complex c3(2, 3);

	cout << "c1 = " << c1.GetReal() << ", " << c1.GetImag() << endl;
	cout << "c2 = " << c2.GetReal() << ", " << c2.GetImag() << endl;
	cout << "c3 = " << c3.GetReal() << ", " << c3.GetImag() << endl;
}