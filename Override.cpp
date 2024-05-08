#include <string>
#include <iostream>
using namespace std;

class TextBox {
public:
	virtual void accept(string text){
		cout << "Text Box" << endl;
	}
};

class NumericTextBox : public TextBox {
public:
	void accept(string text) override {
		cout << "Numeric Text Box" << endl;
	}
};

class PatternTextBox : public TextBox {
public:
	void accept(string text) override {
		cout << "Pattern Text Box" << endl;
	}
};

int main() {
	TextBox nameText;
	nameText.accept("XYZ");

	NumericTextBox ageText;
	ageText.accept("20");

	TextBox* basePtr = &ageText;
	basePtr->accept("32");

	PatternTextBox phNumText;
	basePtr = &phNumText;

	basePtr->accept("+91-4638229922");
}