/* 매크로 함수 : 전처리기에 의해 처리 되면서, 매우 빠른 실행의 이점을 가지게 되는 함수
#define Square((x)*(x))

인라인 함수 : c와의 매크로 함수와 같지만, 인라인 함수는 컴파일러단에서 처리되면서, 구현이 용이하며
컴파일러에게 최적화 기회를 제공한다.
inline int Square(int x){
return x*x;
}
*/

/* 네임 스페이스 : 이름 충돌을 막기 위해 공간에 이름을 주는 행위라고 할 수 있다
ex) 101동에 사는 철수야, 202동에 사는 철수야*/

#include<iostream>

namespace A_COM {
	void function(void) {
		std::cout << "A.com에서 정의한 함수" << std::endl;
	}
}

namespace B_COM {
	void function(void) {
		std::cout << "B.com에서 정의한 함수" << std::endl;
	}
}

int main(void) {
	A_COM::function();
	B_COM::function();
	return 0;
}