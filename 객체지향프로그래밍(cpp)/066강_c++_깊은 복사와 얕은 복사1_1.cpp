#include<iostream>

using namespace std;

int main() {
	int *a = new int(5);
	int *b = new int(3);

	a = b; // 얕은 복사 (참조만 복사)
	*a = *b; //깊은 복사 (값을 복사)

	delete a;
	delete b; //얕은 복사를 실행할 경우 런타임 에러가 발생할 것으로 예상

}