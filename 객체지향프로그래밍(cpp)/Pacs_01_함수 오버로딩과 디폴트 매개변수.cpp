/* 함수 오버로딩 : 동일한 이름의 함수를 중복해서 정의하는 것 단 매개변수의 정보가 달라야 함
c언어에서는 함수의 이름의 중복을 허용하지 않았는데 그 이유는 c언어에서 함수를 호출할때, 함수의
이름정보만을 가지고 호출함수를 찾기 때문입니다. 하지만, c++에서는 호출할 함수를 찾는데 있어서,
이름뿐만 아니라 매개변수의 정보도 포함하고 있기 때문에 이런 기능이 가능 합니다.

int fuction(int n){}
int function(char c){}
int function(int n, char c){}
*/

/* 디폴트 매개변수 :C++의 함수가 가진 또 하나의 특징은 바로 디폴트 매개변수라는 것 입니다. 
디폴트 매개변수란 전달되지 않는 인자를 대신하기 위한 기본값이 설정되어 있는 변수입니다. 아래와
같은 함수에서 () 이 곳이 디폴트 매개변수를 선언할수 있는 부분입니다.
int function(int a=0 ){ return a+1;} */

#include<iostream>

int BoxVolumn(int length, int width = 1, int height = 1); //한 번만 설정해야 함

int main() {
	std::cout << "[3,3,3]    : " << BoxVolumn(3, 3, 3) << std::endl;
	std::cout << "[5,5,def]  : " << BoxVolumn(5, 5) << std::endl;
	std::cout << "[7,def,def]: " << BoxVolumn(7) << std::endl;
	return 0;
}

int BoxVolumn(int length, int width, int height) {
	return length * height*width;
}