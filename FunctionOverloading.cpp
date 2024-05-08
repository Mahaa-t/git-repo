#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
	string name, addr, pan, aadhar, mailId, phNum;
public:
	Customer(string nameArg, 
			 string addrArg, 
			 string panArg, 
			 string aadharArg) :name{ nameArg }, addr{ addrArg }, pan{ panArg }, aadhar{ aadharArg } {
		// this->name = nameArg; // Avoid this type of initialization. This does not work for all data types. 
		// Better to use initializer and leave it to the compiler. Using a universal grammar called initializer with {}.
		// Earlier () was used. Modern C++ uses universal initializer {} from C++ 11 onwards. This is to avoid vex parsing issue.
	}
	Customer(string nameArg,
		string addrArg,
		string panArg,
		string aadharArg,
		string phNumArg) :name{ nameArg }, addr{ addrArg }, pan{ panArg }, aadhar{ aadharArg }, phNum{ phNumArg } {
	}
	Customer(string nameArg,
		string addrArg,
		string panArg,
		string aadharArg,
		string mailIdArg,
		string phNumArg) :name{ nameArg }, addr{ addrArg }, pan{ panArg }, aadhar{ aadharArg }, mailId{ mailIdArg }, phNum { phNumArg } {
	}
};

int main_2() {
	Customer customerObj1{"XXX", "ABCDEF", "POIUYNT5768T", "87563127465292015"};
	Customer customerObj2{"YYY", "MNOPQR", "UTYRHNF4253G", "98645372527186967"};

	return 0;
}