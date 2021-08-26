#include<iostream>//input,output헤데파일
#include<string>
using namespace std;//이름에서 '성'과 같음
int main() {

	cout << "Hello, World!" << endl; //cout:출력, endl:줄바꿈
	cout << endl;
	
	int a, b;
	cout << "숫자 2개를 입력해 주세요" << endl;
	cin >> a >> b;
	cout << a << "+" << b << "=" << a + b << endl;
	cout << endl;

	string str;
	str = "Hello";
	cout << str << endl;
	cout << endl;

	string name;
	cout << "이름 입력 :";
	cin >> name;
	string message = "안녕하세요 " + name + " 님!";
	cout << message << endl;
}