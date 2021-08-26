//question2
//범위 기반 for문을 사용하여 이차원 배열을 출력하기

#include<iostream>

using namespace std;

int main() {
	int arr[2][3] = { {1,2,3},{4,5,6} };

	//범위기반 for문 2개
	for (int(&ln)[3] : arr) {
		for (int &col : ln) {
			cout << col << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	//포인터를 활용한 for문
	for (int (*ln)[3] = arr; ln < arr + 2; ln++) {
		for (int *c = *ln; c < *ln + 3; c++) {
			cout << *c << " ";
		}
		cout << endl;
	}
}

//question 3
/* 다음과 같은 함수 정의에서 컴파일 오류가 나는 이유를 찾으세요

void drawRectangle(int l, int r, int t, int b){}

void drawRectangle(int w, int h, int x=0, int y=0){}

1번 default매개변수는 오른쪽으로 주어야 한다
2번 drawRectangle(0,0,0,0)호출시 정해진 함수가 없다





*/