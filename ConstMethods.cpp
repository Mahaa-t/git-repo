#include <iostream>
#include <string>
using namespace std;

class A {
	int x;
public:
	void method(int y) {
		this->x = 100;
	}

	void method1(int y) const { // this pointer is not modifiable. To inform compiler that state also to be constant, const is added afetr the method => void method(const A * const this)
		// Method scope constant
		// this->x = 100; // Modifying value is not allowed
		y = 100;
		y = 124;
	}

	void method2() {
		this->x = 50;
	}
};

int main() {
	A obj;

	obj.method1(200); // obj is a non-constant but passed to a constant object. As constant added to the method is valid only at the method level. Other method can be non-constant.
	
	return 0;
}