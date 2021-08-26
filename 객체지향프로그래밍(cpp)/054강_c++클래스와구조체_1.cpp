#include<iostream>

using namespace std;

//private, protected, public
//캡슐화 oop중 1가지
//struct의 경우 접근제어 지시자 private가 없으면 public ->private작성해야함
//class의 경우 접근제어 지시자가 없으면 private ->public을 작성해야함
struct TV {
private:
	bool powerOn;
	int channel;
	int volume;

public:
	void on() {
		powerOn = true;
		cout << "TV를 켰습니다" << endl;
	}
	void off() {
		powerOn = false;
		cout << "TV를 껐습니다" << endl;
	}
	
	void setChannel(int chl) {
		if (chl >= 1 && chl <= 999) {
			channel = chl;
			cout << "채널을 " << chl << "으로 바꾸었습니다" << endl;
		}
	}

	void setVolume(int vol) {
		if (vol <= 100 && vol >= 0) {
			volume = vol;
			cout << "볼륨을 " << vol << "으로 바꾸었습니다" << endl;
		}
	}
}lg;

int main() {
	
	lg.on();
	lg.setChannel(10);
	lg.setVolume(50);

}