#include <iostream>

#include "StringCalculator.h"

int main() {

	StringCalculator strCalcObj;

	int result = strCalcObj.add("1 2 3 5 2");

	cout << "Result: " << result << endl;

    return 0;
}
