#include<iostream>

using namespace std;

int main() {
	int *arr; //0번째 칸의 주소값
	int len;

	cout << "동적할당할 배열의 길이 입력 : ";
	cin >> len;

	arr = new int[len];

	for (int i = 0; i < len; i++) {
		arr[i] = len - i;
	}
	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}

	//delete arr; -> 0번째 칸만 사라짐
	delete[] arr;
}