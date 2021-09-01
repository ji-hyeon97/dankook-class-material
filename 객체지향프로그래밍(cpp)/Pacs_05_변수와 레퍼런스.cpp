/* 
변수 : 메모리 공간에 붙은 이름, c에서는 하나의 메모리 공간에 하나의 이름만 가질수 있었으나,
c++에서는 하나의 메모리 공간에 둘 이상의 이름을 붙여줄수 있다 -> 레퍼런스
레퍼런스 : 이름을 지니는 대상에 별명을 붙여주는 행위, 

int main() {
	int val = 10;
	int *pVal = &val; //주소 값을 얻기 위해 &연산자 사용의 예
	int &val = val; //레퍼런스 선언을 위한 &연산자 사용

	return 0;
}

& 연산자를 이용해 마음대로 변수에다가 별명을 붙여 줄 수 있음
*/

#include<iostream>

using namespace std;

int main() {
	int val = 10;
	int &AAA = val; //레퍼런스 선언을 위한 &연산자 사용
	AAA = 20;

	cout << "val value is : " << val << endl;
	cout << "AAA value is : " <<  AAA <<  endl;

	val = 40;

	cout << "val value is : " << val << endl;
	cout << "AAA value is : " << AAA << endl;

	return 0;
}

//레퍼런스를 이용한 변수의 값을 변경하여도 어차피 AAA나 val은 같은 메모리 공간을 가지고 있기 때문에
//위와 같은 출력의 결과를 출력하는 것을 알 수 있다.