/*
1. �Ʒ��� GameWindow Ŭ������ �ڵ忡�� â �ʺ�� ���̸� �Ű������� �޴� ResizeWindow�Լ���
�߰��Ͽ� ���� ���ǰ� ���� width, height�� ���� �ٲܼ� �ֵ��� �ϼ���.
-> ���� �Ű������� ���� ��ġ�ϵ��� â�� ũ�⸦ ������ ��.
-> �ʺ� 800���� �۰ų� ���̰� 600���� ���� ���� ���� 800, 600���� ������ ��.

2.GameWindow::GameWindow(int w, int h)�����ڵ� ���������� 2���� ������ �����ϵ��� �����ϼ���.

3.�ۼ��� �ڵ忡�� ���ȭ�� ������ �κ��� ��� ���ȭ�ϼ���.
*/
#include<iostream>

using namespace std;

class GameWindow {
public:
	GameWindow();
	GameWindow(const int, const int);

	int GetWidth() const;
	int GetHeight() const;

	void ResizeWindow(const int,  const int);

private:
	int width;
	int height;
};

GameWindow::GameWindow() :width(800), height(600) {}
GameWindow::GameWindow(const int w, const int h) {
	ResizeWindow(w, h);
}

int GameWindow::GetWidth() const{ return width; }
int GameWindow::GetHeight() const { return height; }

void GameWindow::ResizeWindow(const int w, const int h) {
	if (w < 800)
		width = 800;
	else
		width = w;
	if (h < 600)
		height = 600;
	else
		height = h;
}
int main() {
	GameWindow mainwindow(500,768);
	cout << mainwindow.GetWidth() << "x" << mainwindow.GetHeight() << endl;
	mainwindow.ResizeWindow(1366, 768);
	cout << mainwindow.GetWidth() << "x" << mainwindow.GetHeight() << endl;
}