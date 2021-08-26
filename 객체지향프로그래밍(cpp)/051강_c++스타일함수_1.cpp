#include<iostream>

//overload
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void swap(double &a, double &b) {
	double temp = a;
	a = b;
	b = temp;
}
void swap(int *(&a), int *(&b)) {
	int *temp = a;
	a = b;
	b = temp;
}
int main() {
	int a(20);
	int b(30);
	swap(a, b);

	double da = 2.2222, db = 3.3333;
	swap(da, db);

	int *pa = &a, *pb = &b;
	swap(*pa, *pb);

	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "da : " << da << std::endl;
	std::cout << "db : " << db << std::endl;
	std::cout << "*pa : " << *pa << std::endl;
	std::cout << "*pb : " << *pb << std::endl;



}