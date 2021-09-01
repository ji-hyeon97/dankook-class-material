/* 
값에 의한 호출 : Call by Value라고 불리우며, 인자로 넘기는 값을 복사해서 새로운 함수에 넘겨주는
방식으로 값의 복사에 의한 함수 호출을 의미합니다.

#include<iostream>

using namespace std;

void swap(int a, int b);

int main() {
	int val1 = 10;
	int val2 = 20;
	swap(val1, val2);

	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;

	return 0;
}

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
}

위의 예제는 Call by Value 예제의 결과값입니다. Call by Value는 값을 복사해서 전달하기 때문에 원본의
값이 변경될 가능성이 없다는 특징을 가지고 있지만, 값을 넘겨 줄때마다 고비용, 복사손실 문제가 발생하는
단점도 있습니다.
Call by Value는 Pass by Value라고 불리기도 합니다.
*/


//참조에 의한 호출 : Call by Reference라고 부르며, 주소 값을 인자로 전달하는 함수 호출을 말합니다.

#include<iostream>
using namespace std;

void swap(int *a, int *b);

int main() {
	int val1 = 10;
	int val2 = 20;

	cout << "Before the swap function" << endl;
	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;

	swap(&val1, &val2);

	cout << endl << "After Swap function" << endl;
	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;

	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//위의 예제에서 알 수 있듯이 Call by Reference는 복사손실과 고비용 문제에서는 벗어났지만, 원본의 값의 변경이 일어
//날 수 있는 중대한 문제점을 안고 있는 걸 볼 수 있습니다.
