#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string.h>
#define PI 3.14
using namespace std;


/*					OOP HW4 (5pts, Due: 10/31 23:59 PM)
Your goal is
1) to complete classes Shape, Circle and Rectangle, and
2) to provide a function clear that deletes all memory allocated to the objects.

Read the main function carefully, and find out what you need to implement.
Submit this file to the LMS.

Notes.
1. You are not allowed to modify the main function.
2. You are FREE to modify the class Shape.

The requirements are listed below:
1. Circle and Rectangle classes
	1-1. Both Circle and Rectangle are characterized by one integer variable _d which has a different meaning depending on the shape of the object as follows:
		 For Circle, _d represents the radius of the circle.
		 For Rectangle, _d represents the length of one side. Assume that all sides of a rectangle object have the same length, that is, a square.
	1-2. Both Circle and Rectangle require a parameterized constructor, which initializes the value of _d.
	1-3. Make destructors explicitly.

2. displayArea()
	2-1. diplayArea() displays the area (as a float value) of the corresponding object.
	2-2. This should display the area of the corresponding object, not that of the base (i.e., Shape).
	2-3. There is no fixed output format.

3. clear()
	3-1. This function clears all memory allocated to the objects.
	3-2. Make the destructors display an output message such as "Circle: Destructor".
	3-3. Remember that the destructors of the derived classes must be called.
*/


// Complete the Shape class. You are FREE to modify this.
class Shape {
protected:
	int _d;
	string design;
public:
	virtual ~Shape() {
		cout << "Base: Destructor" << endl; 
	}
	virtual void displayArea() { 
		cout << "When will you fix me?" << endl;
	}
};

class Circle : public Shape {
public:
	Circle(int a) {
		_d = a;
		design = "circle";
	}
	void displayArea() {
		cout << "Area: " << _d *_d * PI << endl<<endl;
	}	
	~Circle(){
		cout << "Circle: Destructor" << endl;
	}
};

class Rectangle : public Shape {
public:
	Rectangle(int b) {
		_d = b;
		design = "rectangle";
	}
	void displayArea() {
		cout << "Area: " << _d * _d << endl << endl;
	}
	~Rectangle() {
		cout << "Rectangle: Destructor" << endl;
	}
};

void clear(Shape* arr[3]) {
	for (int i = 0; i < 3; i++) {
		delete arr[i];
	}
}

// DO NOT TOUCH THE MAIN FUNCTION.
int main() {
	srand(time(NULL));
	cout << "Creating 3 objects" << endl << endl;
	Shape* arr[3] = {};

	char s;
	for (int i = 0; i < 3; i++) {
		if (rand() % 2 == 0) {
			cout << "Circle is created at [" << i << "] ";
			arr[i] = new Circle(rand() % 10 + 1);				// A circle is created.
		}
		else {
			cout << "Rectangle is created at [" << i << "] ";
			arr[i] = new Rectangle(rand() % 10 + 1);			// A rectangle is created
		}
		arr[i]->displayArea();									// The area of arr[i] is displayed, e.g., "Area: 4"
	}

	//Delete all memory of the created objects
	cout << endl << "Deleting the objects" << endl;
	clear(arr);

	return 0;
}