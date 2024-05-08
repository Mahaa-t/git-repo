// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
class A {
public:
	virtual void M1() { cout << "A.M1()" << endl; }
	void M2() { cout << "A.M2()" << endl; }
};
class B :public A {
public:
	//void M1() override { cout << "B.M1()" << endl; }
	void M2() { cout << "B.M2()" << endl; }
	virtual void M3() { cout << "B.M3()" << endl; }
	void M4() { cout << "B.M4" << endl; }
};
class C :public B {
public:
	void M1() { cout << "C.M1()" << endl; }
	void M3() override { cout << "C.M3()" << endl; }
	void M4() { cout << "C.M4()" << endl; }
};
// Virtual calls to be traced with the datatype of the object and not on the address of the object it holds
int main() {
	A aObj;
	A* aPtr = &aObj;
	aPtr->M1(); // Virtual call		// A.M1
	aPtr->M2(); // Non-Virtual call

	B bObj;
	B* bPtr = &bObj;
	bPtr->M1(); // Virtual call		// A.M1
	bPtr->M2(); // Non-Virtual call
	bPtr->M3(); // Virtual call		// B.M3
	bPtr->M4(); // Non-Virtual call

	aPtr = &bObj;
	aPtr->M1(); // Virtual call		// B.M1
	aPtr->M2(); // Non-Virtual call

	C cObj;
	cObj.M1(); // Virtual call as the base class definition is virtual	// C.M1
	cObj.M2(); // Non-Virtual call
	cObj.M3(); // Virtual call		// C.M3
	cObj.M4(); // Non-Virtual call

	aPtr = &cObj;
	aPtr->M1(); // Virtual call		// C.M1
	aPtr->M2(); // Non-Virtual call

	bPtr = &cObj;
	bPtr->M1(); // Virtual call		// C.M1
	bPtr->M2(); // Non-Virtual call
	bPtr->M3(); // Virtual call		// C.M3
	bPtr->M4(); // Non-Virtual call
}