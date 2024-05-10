#include <iostream>
#include <string>

using namespace std;
class A {
public:
	A() {
		cout << "A created" << endl;
	}
	~A() {
		cout << "A deleted" << endl;
	}
	void operation() {
		cout << "Some A operation" << endl;
	}
};

class SmartPointerOfTypeA {
	A* ptr;
public:
	SmartPointerOfTypeA(A* ptrRef):ptr{ ptrRef }{}
	~SmartPointerOfTypeA() {
		delete ptr;
	}
	void operation() {
		this->ptr->operation();
	}
};



void instantiate() {

	//A* ptr = new A();
	SmartPointerOfTypeA smartPtr{ new A() };
	smartPtr.operation();

}

int main() {
	instantiate();

}