/*

class A : public B{};

B클래스를 public으로 상속하겠다는 의미로 우리들이 일반적으로 많이 사용하는 class A:[상속형태] B 형태를
가지고 있다 기본적으로 기본 클래스는 파생 클래스에 의해 상속되어지는 과정에서 접근 권한이 변경된다.
그 상속 형태에 따라 멤버들을 상속하는데 있어서 접근권한을 무엇으로 변경할 것이냐 ? 하는 이야기 이다 
아래는 기본 클래스와 상속의 형태에 따른 파생클래스에서의 기본클래스 로의 접근범위를 표로 나타낸 것이다.
일반적으로는 public을 가장 많이 쓰이므로 그 부분에 초점을 맞춰서 보는 것이 좋다.
*/

#include<iostream>
using namespace std;

class Base {
private:
	int a;
protected:
	int b;
public:
	int c;
};

class Derived : public Base { //or protected Base or private Base
};

void main() {
	Derived obj;
}
/*
protected Base 상속의 경우
protected Base 로 선언 했다고 가정하자. 상속의 형태가 protected이다. 이 의미는 protected보다 접근 권한이
넓은 것이면, 그냥 protected에 맞춰서 내가 상속을 하겠다는 의미를 가지고 있다.
- int c : 상속되어지는 과정에서 int c는 지금 public 인데 protected보다 접근할 수 있는 범위가 넓기 때문에 
상속이 protected로 맞춰지게 된다.
- int b : 여전히 protected가 된다.
- int a : private인 int a는 private는 protected보다 접근 권한이 작으니까 그대로 private로 상속되겠다
생각하기 쉽지만, 파생클래스에서 int a는 private int a로 선언이 된다. (상속되면 결과적으로) int a는
private이기 때문에 파생 클래스에서 접근 가능한 것으로 생각되기 쉽지만, 접근 가능하지 않다. 그 이유는 private
멤버 특성상 자기 클래스 내에서만 접근 가능하지 상속됐다고 파생클래스에서 접근 하지는 못하기 때문이다.
그래서 우리는 헷갈리지 않게 Base 클래스에서 private로 선언된 멤버는 상속이 될때 접근 불가라는 키워드가 붙는 다고
생각하는 것이 옳다

private 상속의 경우
-int c, int b : 이 둘은 private보다 범위가 넓으니 private로 맞춰 지겠다.
-int a : 위에서 언급한 Base 클래스에서 private로 선언된 멤버는 접근 불가라는 것을 기억하자

public 상속의 경우
- int c : 범위가 같으므로 같은 public 으로
- int b : public 보다 범위가 작으니 자기 자신그대로의 접근 범위를 가져온다
- int a : 위에서 언급한 Base 클래스에서 private로 선언된 멤버는 접근 불가라는 것을 기억하자
*/

