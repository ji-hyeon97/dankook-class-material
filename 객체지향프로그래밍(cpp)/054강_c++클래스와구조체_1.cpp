#include<iostream>

using namespace std;

//private, protected, public
//ĸ��ȭ oop�� 1����
//struct�� ��� �������� ������ private�� ������ public ->private�ۼ��ؾ���
//class�� ��� �������� �����ڰ� ������ private ->public�� �ۼ��ؾ���
struct TV {
private:
	bool powerOn;
	int channel;
	int volume;

public:
	void on() {
		powerOn = true;
		cout << "TV�� �׽��ϴ�" << endl;
	}
	void off() {
		powerOn = false;
		cout << "TV�� �����ϴ�" << endl;
	}
	
	void setChannel(int chl) {
		if (chl >= 1 && chl <= 999) {
			channel = chl;
			cout << "ä���� " << chl << "���� �ٲپ����ϴ�" << endl;
		}
	}

	void setVolume(int vol) {
		if (vol <= 100 && vol >= 0) {
			volume = vol;
			cout << "������ " << vol << "���� �ٲپ����ϴ�" << endl;
		}
	}
}lg;

int main() {
	
	lg.on();
	lg.setChannel(10);
	lg.setVolume(50);

}