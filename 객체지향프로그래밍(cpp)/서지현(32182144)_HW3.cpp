#include <iostream>
#include<random>
#define ROW 3
#define COL 3
using namespace std;

/*
				HW 3 (7pts, Due: 10/13 23:59PM)
Complete a class Matrix2 by inheriting the class Matrix that you made in HW2.
Your Matrix2 class should support the following functionalities:

1. zeros()
This function is newly added in Matrix2, which makes the given matrix a zero matrix.
That is, all elements of the given matrix should be zeros.

2. eyes()
Another new function eyes() makes the given matrix the identity matrix.

3. show()
The show() function of the class Matrix is redefined in class Matrix2.
Now, this function only displays the biggest element of the matrix.

4. You are free to modify the previous class Matrix if necessary, but you need to use inheritance to create class Matrix2.
Make sure all functions (including those of HW2) are working as intended.
Also, any errors in the previous HW2 code should be corrected. Only then can you get a full score.

Submit this file to the LMS.
*/

//Your code goes here.

class Matrix {
protected: //상속을 해야합니다. 자식클래스도 접근이 가능하게 하겠습니다.
	int** matrix;
public:
	Matrix() { //2차원배열 동적할당 , 난수생성
		matrix = new int* [ROW];
		for (int i = 0; i < ROW; i++) {
			matrix[i] = new int[COL];
		}
		random_device rd; //시드값 확보
		mt19937 input(rd()); //난수 생성 엔진 초기화
		uniform_int_distribution<int> uniform(10, 33); //"well" display 조건을 생각하여 값의 균등분포값을 10~33 으로 두어 깔끔한 모습으로 출력됩니다.
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				matrix[i][j] = uniform(input); //All values are intialized as non - zero integers.
			}
		}
	}
	//friend -> private의 영역인 matrix접근을 허용함
	friend Matrix operator+(Matrix, Matrix);
	friend Matrix operator*(Matrix, Matrix);

	void show() { //3X3 matrix 출력
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
		return;
	}
};

Matrix operator+(Matrix d1, Matrix d2) {
	Matrix tmp;//return을 하기위한 객체 생성
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

class Matrix2 : public Matrix {
public:	
	void zeros() { //영행렬 만들기
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				matrix[i][j] = 0;
			}
		}
	}
	void eyes() { //단위행렬 만들기
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (i == j) {
					matrix[i][j] = 1;
				}
				else {
					matrix[i][j] = 0;
				}
			}
		}
	}
	void show() {
		int max = matrix[0][0];
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (matrix[i][j] > max) {
					max = matrix[i][j];
				}
			}
		}
		cout << "the biggest element is " << max << endl;
		cout << "\n";
	}
};


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


	//added for HW3
	
	Matrix2 F;
	cout << "Zero Matrix" << endl;
	F.zeros();			// zero all elements.
	F.Matrix::show();	// call the show() of the base.
	F.show();			// diplay the biggest element.

	cout << "Identity Matrix" << endl;
	F.eyes();			// make F the identity matrix.
	F.Matrix::show();
	F.show();
	

	return 0;
}