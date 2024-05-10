#include <iostream>
#include <string>
using namespace std;

// Old C++ uses class instead of typename
template<typename T>
T add(T operand1, T operand2) {
	return operand1 + operand2;
}

int main() {
	cout << "Hello" << endl;

	int result = add<int>(10, 20);		// Template instantiation
	cout << result << endl;

	string result1 = add<string>("10", "20");	// Template instantiation
	cout << result1 << endl;
}