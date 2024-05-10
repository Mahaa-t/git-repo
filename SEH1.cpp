#include <iostream>
using namespace std;

class ErrorInfo {
public:
	string methodname;
	int lineNr;
	string message;
};

int division(int numerator, int divisor) {
	int result;
	cout << "Division begin" << endl;
	if (divisor <= 0) {
		ErrorInfo errorDetails;
		errorDetails.methodname = "division";
		errorDetails.lineNr = 11;
		errorDetails.message = "Divisor value should be > 0";
		throw errorDetails;	// Equivalent to return;
	}
	result = numerator / divisor;
	cout << "Division end" << endl;
	return result;
}

int init() {
	cout << "Init begin" << endl;

	int result = division(10, 0);
	cout << "Init end" << ":" << result << endl;

	return 0;
}

int main() {
	cout << "Main begin" << endl;
	try {
		init();
		cout << "Main end" << endl;
	}
	catch (ErrorInfo& errObj) {
		cout << "Exception handled" << endl;
		cout << "Method name: " << errObj.methodname << endl;
		cout << "Line nr: " << errObj.lineNr << endl;
		cout << "Message: " << errObj.message << endl;
	}

	return 0;
}