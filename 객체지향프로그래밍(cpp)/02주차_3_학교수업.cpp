/* 
인라인 함수
inline double cube(double a) {
	return a * a * a;
}

int main() {
	double y = cube(3);
	cout << y << endl;
	return 0;
}
*/
/*
OverLoading함수
int add(int a, int b) { return a + b; }
int add(int a, int b, int c) { return a + b + c; }

int main(){
	cout << add(5, 10) << endl;
	cout << add(15, 10, 30) << endl;
	return 0;
}
*/
/*
동적할당 및 해제

int** p2 = new int* [10];
for (int i = 0; i < 10; i++) {
	p2[i] = new int[5];
}
for (int i = 0; i < 10; i++) {
	delete p2[i];
}
delete[] p2;
*/
/*
call-by-reference
void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}
swap(m, n);
*/
/*
call-by-value
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
swap(&m, &n);
*/


