#include <iostream>
#include <string>
using namespace std;

void f1(string arg) {
	arg = "hello1";
}

void f2(string *arg) {
	*arg = "hello2";
}

void f21(const string *arg) {
	string temp = "Const value";
	arg = &temp;
}

void f22(string* const arg) {
	*arg = "Const pointer";
}

void f3(string &arg) {
	arg = "hello3";
}

// For reference, only the below grammar is allowed. 
void f3(const string& arg) {
	//arg = "hello3";
}

int main() {
	string data = "hi";

	f1(data);
	cout << data << endl;

	f2(&data);
	cout << data << endl;

	f3(data);
	cout << data << endl;

	return 0;
}