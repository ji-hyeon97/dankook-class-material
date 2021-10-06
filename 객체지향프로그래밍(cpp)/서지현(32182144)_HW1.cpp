#include <iostream>
#include<string>
using namespace std;

class hw1 {
private:
	int n;
	int index;
	float change;
	float *vector;

public:
	void create() {
		cout << "벡터의 성분 갯수를 입력하세요(단 1개 이상) : ";
		cin >> n;
		if (n <= 0) {
			cout << "잘못 입력하였습니다. 창을 끄고 다시시작해 주세요";
		}
		vector = new float[n];// Dynamic memomry allocation 개념을 이용해 보았습니다

		for (int i = 0; i < n; i++) {
			cout << i << "번째 값은 : ";
			cin >> vector[i];
		}
		return;
	}

	void modify() {
		cout << "입력한 값중 몇 번째 값을 수정하고 싶으신 가요?" << endl;

		cin >> index;
		cout << "어떤 값으로 바꾸고 싶으신 가요 ?" << endl;

		cin >> change;
		vector[index] = change;

		cout << "입력한 값중 수정하고 싶은 값이 더 있으신 가요 ? (yes 또는 no 로 대답해 주세요 !)" << endl;
		string repeat;
		cin >> repeat;
		if (repeat == "yes") {
			return modify();
		}
		return;
	}

	void multiply(float &scalar) {// call-by-reference개념을 이용해 보았습니다.
		for (int i = 0; i < n; i++) {
			vector[i] = vector[i] * scalar;
		}
		return;
	}

	void display() { //pdf의 조건d에 따르면 출력형식은 다음과 같습니다.
		cout << endl;
		cout << "벡터의 값들을 보여드리겠습니다." << endl;
		cout << "(";
		for (int i = 0; i < n; i++) {
			cout << vector[i] << ", ";
		}
		cout << " ...)";
		delete[] vector;//memory release
		return;
	}
};

int main() {
	hw1 h;//인스턴스 생성
	h.create();
	h.modify();
	float scalar;
	cout << "곱하고 싶은 수를 입력하세요 : ";
	cin >> scalar;
	h.multiply(scalar);
	h.display();
	return 0;
}

/*

<test code>

벡터의 성분 갯수를 입력하세요(단 1개 이상) : 5
0번째 값은 : 1.1
1번째 값은 : 2.2
2번째 값은 : 3.3
3번째 값은 : 4.4
4번째 값은 : 5.5
입력한 값중 몇번째 값을 수정하고 싶으신 가요?
0
어떤 값으로 바꾸고 싶으신 가요 ?
1
입력한 값중 수정하고 싶은 값이 더 있으신 가요 ? (yes 또는 no 로 대답해 주세요 !)
yes
입력한 값중 몇번째 값을 수정하고 싶으신 가요?
1
어떤 값으로 바꾸고 싶으신 가요 ?
2
입력한 값중 수정하고 싶은 값이 더 있으신 가요 ? (yes 또는 no 로 대답해 주세요 !)
no
곱하고 싶은 수를 입력하세요 : 10

벡터의 값들을 보여드리겠습니다.
(10, 20, 33, 44, 55,  ...)

C:\Users\서지현\source\repos\seoji\Debug\seoji.exe(프로세스 14128개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...

<unit code>

(a) to create a vector : create 함수에서 동적할당을 하여 vector를 생성하였습니다.
(b) to modify the value of a given element : modify함수를 통해 구현하였습니다.
(c) to multiply by a scalar value : multiply 함수에서 call-by-reference개념을 활용했습니다.
(d) to display the vector in the form (10, 20, 30, …) : display함수를 통해 구현하였습니다.

main함수에서 h라는 인스턴스를 생성해주었고 이로 인해 hw1클래스의 public부분을 자유롭게 접근하며
각각의 함수는 의도한 대로 잘 작동합니다.

감사합니다 !

*/
