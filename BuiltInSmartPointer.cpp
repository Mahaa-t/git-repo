#include <iostream>
#include <string>
#include <memory>

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

template <typename T>
class SmartPointerOfAnyType {
	T* ptr;
public:
	SmartPointerOfAnyType(T* ptrRef) :ptr{ ptrRef } {}
	~SmartPointerOfAnyType() {
		delete ptr;
	}
	T* operator->() {
		return ptr;
	}
};

void instantiate() {

	//A* ptr = new A();
	//SmartPointerOfAnyType<A> smartPtr{ new A() };
	//smartPtr->operation();

	unique_ptr<A> uniqueSmartPtr = make_unique<A>();
	uniqueSmartPtr->operation();
}

int main() {
	instantiate();
}