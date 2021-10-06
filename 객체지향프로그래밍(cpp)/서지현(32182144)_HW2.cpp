#include <iostream>
#include<random>
#define ROW 3
#define COL 3
using namespace std;
/*
HW 2 (5pts, Due: 10/4 23:59PM)
Provide a class Matrix to complete this code.
This class should support the following functionalities:

1. Matrix Creation
A 3 by 3 matrix is created. All values are intialized as non-zero integers.
You may want to use rand for this.

2. Matrix Addtion and Multiplication
You may want to use operator overloading.

3. Display
The values of a matrix are "well" displayed.

Submit this file to the LMS.
*/
//Your code goes here.

class Matrix {
	int** matrix;
public:
	Matrix() { //2�����迭 �����Ҵ� , ��������
		matrix = new int* [ROW];
		for (int i = 0; i < ROW; i++) {
			matrix[i] = new int[COL];
		}
		random_device rd; //�õ尪 Ȯ��
		mt19937 input(rd()); //���� ���� ���� �ʱ�ȭ
		uniform_int_distribution<int> uniform(10, 33); //"well" display ������ �����Ͽ� ���� �յ�������� 10~33 ���� �ξ� ����� ������� ��µ˴ϴ�.
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				matrix[i][j] = uniform(input); //All values are intialized as non - zero integers.
			}
		}
	}
	//friend -> private�� ������ matrix������ �����
	friend Matrix operator+(Matrix, Matrix);
	friend Matrix operator*(Matrix, Matrix);

	void show() { //3X3 matrix ���
		for (int i = 0; i < 3; i++) {
			cout << "[";
			for (int j = 0; j < 3; j++) {
				if (j != 2) {
					cout << matrix[i][j] << "  ";
				}
				else {
					cout << matrix[i][j];
				}
			}
			cout << "]";
			cout << "\n";
		}
		cout << "\n";

		for (int i = 0; i < ROW; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		return;
	}
};

Matrix operator+(Matrix d1, Matrix d2) {
	Matrix tmp;//return�� �ϱ����� ��ü ����
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			tmp.matrix[i][j] = d1.matrix[i][j] + d2.matrix[i][j];
		}
	}
	return tmp;
}

Matrix operator*(Matrix e1, Matrix e2) {
	Matrix tmp;

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			tmp.matrix[i][j] = e1.matrix[i][j] * e2.matrix[i][j];
		}
	}
	return tmp;
}

//DO NOT TOUCH THE MAIN FUNCTION.
int main() {

	Matrix A, B, C;		// 3 by 3 matrix created. All values are intialized as non-zero integers.

	Matrix D = A + B;	// Matrix Addition
	Matrix E = A * C;	// Matrix Multiplication

	cout << "A" << endl;
	A.show();		// display the values
	cout << "B" << endl;
	B.show();
	cout << "C" << endl;
	C.show();

	cout << "A + B" << endl;
	D.show();

	cout << "A * C" << endl;
	E.show();

	return 0;
}
