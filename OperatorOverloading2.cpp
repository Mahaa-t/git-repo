#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
	int balance;
public:
	BankAccount(int initBalance) :balance{ initBalance } {

	}
	~BankAccount() {
		cout << "Destructor called" << endl;
	}
	int getBalance() const {
		return this->balance;
	}
	/*void operator+(BankAccount& operand2) {

	}*/
	// const BankAccount * const this
	// BankAccount operator+(const BankAccount& operand2) const {
	BankAccount operator+(const BankAccount& operand2) const {
		BankAccount newAccount(this->balance + operand2.balance);
		// Or
		// BankAccount newAccount(0);
		// newAccount.balance = this->balance + operand2.balance;
		return newAccount;
	}

	// Friend should be used as method to this class cannot be used -> first argument is this which is of type BankAccount, but cout's first
	// operand is of type ostream
	// Friend method can use the private members of the class
	friend ostream& operator<<(ostream& out, const BankAccount& operand2) {
		out << "Current balance is :" << operand2.balance;

		return out;
	}

};

// Print balance when object is printed
int main() {
	BankAccount acc1(1000);
	BankAccount acc2(2000);

	cout << acc1 << endl;
	cout << acc2 << endl;

	BankAccount acc3 = acc1 + acc2;
	cout << acc3 << endl;
}