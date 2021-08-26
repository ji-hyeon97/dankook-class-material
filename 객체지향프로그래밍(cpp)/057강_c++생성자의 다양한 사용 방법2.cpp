#include<iostream>

using namespace std;

class Time {
public:
	Time():h(0),m(0),s(0){}
	Time(int s_):Time() {
		s = s_;
	}
	Time(int m_,int s_):Time(s_) {
		m = m_;
	}
	Time(int h_, int m_, int s_) : Time(m_,s_) {//생성자 위임(중복처리)
		h = h_;

	}
	int h;//get set 귀차나서
	int m;//get set 귀차나서
	int s;//get set 귀차나서
};
int main() {
	Time t1;
	Time t2(5);
	Time t3(3, 6);
	Time t4(2, 42, 15);

	cout << "t1 : " << t1.h << ":" << t1.m << ":" << t1.s << endl;
	cout << "t2 : " << t2.h << ":" << t2.m << ":" << t2.s << endl;
	cout << "t3 : " << t3.h << ":" << t3.m << ":" << t3.s << endl;
	cout << "t4 : " << t4.h << ":" << t4.m << ":" << t4.s << endl;

}