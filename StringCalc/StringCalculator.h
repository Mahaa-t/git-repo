#include <string>
using namespace std;

class StringCalculator {
public:
	int add(string input); 
};

class GetNegatives {
private:
	string negatives;

public:
	void operator()(int i);
	operator string();
};